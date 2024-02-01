#pragma once
#include <cstdint>
#include <type_traits>
#include <concepts>
#include <compare>
#include <string>
#include <numbers>

#include "integer_bits.hpp"

namespace fpn
{
#if defined(__GNUC__) || (defined(_MSVC_LANG) && _MSVC_LANG >= 202600)
#   define FPN_CONSTEXPR_HAS 1
#   define FPN_CONSTEXPR constexpr
#endif
#ifndef FPN_CONSTEXPR
#   define FPN_CONSTEXPR_HAS 0
#   define FPN_CONSTEXPR
#endif
    /**
     * Signed fixed-point numbers.
     * @note There is no unsigned variant
     * Equivalent to integer of IntegralBits (8 -> int8_t, 16 -> int16_t) with additional FractionalBits for fractional part.
     * @note FractionalBits are not decimal places it will print. Best way to imagine it is as 1 over number of values of FractionalBits unsigned integer for minimum step (1 -> 1/2 = 0.5, 2 -> 1/4 = 0.25, 3 -> 1/8 = 0.125)
     */
    template<fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    struct fixed
    {
        static_assert(IntegralBits > 1);
        static_assert(FractionalBits > 0);
        static_assert(IntegralBits + FractionalBits <= 64);

        /**
         * Structure to hold the value and not collide with other types.
         */
        struct ValueType
        {
            using T = typename integer_bits<IntegralBits + FractionalBits>::signed_type;
            T Value{};

            inline constexpr ValueType() noexcept : Value() {}
            inline constexpr ValueType(const decltype(Value) value) noexcept : Value(value) {}

            // Copy
            inline constexpr ValueType(const ValueType& other) noexcept = default;
            inline constexpr ValueType& operator=(const ValueType& other) noexcept = default;
            // Move
            inline constexpr ValueType(ValueType&& other) noexcept = default;
            inline constexpr ValueType& operator=(ValueType&& other) noexcept = default;
        };

        ValueType Value{};

        // Basic (technical) constructors
        inline constexpr fixed() noexcept : Value() {}
        inline explicit constexpr fixed(ValueType) noexcept;
        inline explicit constexpr fixed(
            typename integer_bits<IntegralBits>::signed_type     integralValue,
            typename integer_bits<FractionalBits>::unsigned_type fractionalValue
        );

        // Conversion from other fixed size
        template<fpn::size_t IB2, fpn::size_t FB2>
        inline explicit constexpr fixed(fixed<IB2, FB2>) noexcept;

        // Conversion from string
        inline explicit constexpr fixed(const std::string&) noexcept; //TODO Use std::string_view as main implementation using std::from_chars
        inline explicit constexpr fixed(const std::string_view value) noexcept : fixed(std::string(value)) {}
        inline explicit constexpr fixed(const char* value) noexcept : fixed(std::string(value)) {}

        // Copy
        inline constexpr fixed(const fixed& other) noexcept = default;
        inline constexpr fixed& operator=(const fixed& other) noexcept = default;
        // Move
        inline constexpr fixed(fixed&& other) noexcept = default;
        inline constexpr fixed& operator=(fixed&& other) noexcept = default;

        [[nodiscard]] inline constexpr operator bool() const noexcept { return Value.Value != 0; }

        [[nodiscard]] inline constexpr bool operator==(const fixed other) const noexcept { return Value.Value == other.Value.Value; }
        [[nodiscard]] inline constexpr auto operator<=>(const fixed other) const noexcept { return Value.Value <=> other.Value.Value; }

        [[nodiscard]] inline constexpr fixed operator-() const noexcept { return fixed{ ValueType{ static_cast<typename ValueType::T>(-Value.Value) } }; }

#pragma region Integral + Fractional Values
        /**
         * Raw representation of the integral part of this number.
         */
        [[nodiscard]] inline constexpr typename integer_bits<IntegralBits>::signed_type IntegralPart() const noexcept;
        /**
         * Raw representation of the fractional part of this number.
         */
        [[nodiscard]] inline constexpr typename integer_bits<FractionalBits>::unsigned_type FractionalPart() const noexcept;
        /**
         * Integral part only.
         * @warning For negative values with fractional part, the value is as if rounded away from zero ( -1.5 becomes -2 )
         */
        [[nodiscard]] inline constexpr fixed IntegralValue() const noexcept;
        /**
         * Fractional value only.
         * @warning Positive value even for negative numbers.
         */
        [[nodiscard]] inline constexpr fixed FractionalValue() const noexcept;
#pragma endregion

#pragma region Min + Max values
        [[nodiscard]] inline static constexpr fixed MinValue() noexcept;
        [[nodiscard]] inline static constexpr fixed MaxValue() noexcept;
#pragma endregion

#pragma region Mathematical constants
#ifndef _WIN32 // Disabled as MSVC has several problems with this
        inline static const fixed e          = std::numbers::template e_v<double>;
        inline static const fixed log2e      = std::numbers::template log2e_v<double>;
        inline static const fixed log10e     = std::numbers::template log10e_v<double>;
        inline static const fixed pi         = std::numbers::template pi_v<double>;
        inline static const fixed inv_pi     = std::numbers::template inv_pi_v<double>;
        inline static const fixed inv_sqrtpi = std::numbers::template inv_sqrtpi_v<double>;
        inline static const fixed ln2        = std::numbers::template ln2_v<double>;
        inline static const fixed ln10       = std::numbers::template ln10_v<double>;
        inline static const fixed sqrt2      = std::numbers::template sqrt2_v<double>;
        inline static const fixed sqrt3      = std::numbers::template sqrt3_v<double>;
        inline static const fixed egamma     = std::numbers::template egamma_v<double>;
        inline static const fixed phi        = std::numbers::template phi_v<double>;
#endif
#pragma endregion

#pragma region Increment/Decrement operators
        // Prefix
        [[nodiscard]] inline constexpr fixed& operator++() noexcept;
        [[nodiscard]] inline constexpr fixed& operator--() noexcept;
        // Postfix
        [[nodiscard]] inline constexpr const fixed operator++(int) noexcept;
        [[nodiscard]] inline constexpr const fixed operator--(int) noexcept;
#pragma endregion

#pragma region Integers
        inline constexpr fixed(std::integral auto) noexcept;

        template<typename TI>
            requires std::integral<TI>
        [[nodiscard]] inline constexpr operator TI() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::integral auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::integral auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion

#pragma region Floating-point numbers
        inline FPN_CONSTEXPR explicit fixed(std::floating_point auto) noexcept;

        template<typename TF>
            requires std::floating_point<TF>
        [[nodiscard]] inline constexpr explicit operator TF() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::floating_point auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::floating_point auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion
    };

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, fixed<IB, FB>) noexcept;

    /**
     * Calculate 1/x
    */
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> inverse(fixed<IB, FB>) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline std::string to_string(fixed<IB, FB>);

    template <typename CharT, fpn::size_t IB, fpn::size_t FB>
    inline std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>&, fixed<IB, FB>) noexcept;

#pragma region Other fixed-point numbers
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator+(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator-(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator*(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator/(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
#pragma endregion

#pragma region Integers
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, std::integral auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, std::integral auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, std::integral auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, std::integral auto) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(std::integral auto, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(std::integral auto, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(std::integral auto, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(std::integral auto, fixed<IB, FB>) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator%(fixed<IB, FB>, std::integral auto) noexcept;
#pragma endregion

#pragma region Predefined types
    // "Slow division" below means division operation uses 128-bit number or far slower algorithm for platforms without 128-bit numbers (=Windows)

    using fixed8_8  = fixed<8,  8>;
    using fixed8_16 = fixed<8, 16>;
    using fixed8_24 = fixed<8, 24>;
    using fixed8_32 = fixed<8, 32>; // Slow division
    using fixed8_40 = fixed<8, 40>; // Slow division
    using fixed8_48 = fixed<8, 48>; // Slow division
    using fixed8_56 = fixed<8, 56>; // Slow division
    
    using fixed16_8  = fixed<16,  8>;
    using fixed16_16 = fixed<16, 16>;
    using fixed16_24 = fixed<16, 24>;
    using fixed16_32 = fixed<16, 32>; // Slow division
    using fixed16_40 = fixed<16, 40>; // Slow division
    using fixed16_48 = fixed<16, 48>; // Slow division

    using fixed24_8  = fixed<24,  8>;
    using fixed24_16 = fixed<24, 16>;
    using fixed24_24 = fixed<24, 24>;
    using fixed24_32 = fixed<24, 32>; // Slow division
    using fixed24_40 = fixed<24, 40>; // Slow division

    using fixed32_8  = fixed<32,  8>;
    using fixed32_16 = fixed<32, 16>;
    using fixed32_24 = fixed<32, 24>;
    using fixed32_32 = fixed<32, 32>; // Slow division

    using fixed40_8  = fixed<40,  8>;
    using fixed40_16 = fixed<40, 16>;
    using fixed40_24 = fixed<40, 24>;

    using fixed48_8  = fixed<48,  8>;
    using fixed48_16 = fixed<48, 16>;

    using fixed56_8  = fixed<56,  8>;
#pragma endregion
}

#include "fixed.inl"

namespace std
{
    template<fpn::size_t IB, fpn::size_t FB>
    struct hash<fpn::fixed<IB, FB>>
    {
        [[nodiscard]] std::size_t constexpr operator()(const fpn::fixed<IB, FB>& value) const noexcept
        {
            return static_cast<std::size_t>(value.Value.Value);
        }
    };
    template<fpn::size_t IB, fpn::size_t FB>
    struct numeric_limits<fpn::fixed<IB, FB>>
    {
        numeric_limits() = delete;
        using FIXED = fpn::fixed<IB, FB>;

        static constexpr bool is_specialized = true;

        static constexpr bool is_signed  = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact   = true;

        static constexpr bool               has_infinity      = false;
        static constexpr bool               has_quiet_NaN     = false;
        static constexpr bool               has_signaling_NaN = false;
        static constexpr float_denorm_style has_denorm        = denorm_absent;
        static constexpr bool               has_denorm_loss   = false;

        static constexpr float_round_style round_style = round_toward_zero;
        static constexpr bool              is_iec559   = false;
        static constexpr bool              is_bounded  = true;
        static constexpr bool              is_modulo   = false; //THINK Maybe?

        static constexpr int digits       = IB + FB - 1;
        static constexpr int digits10     = (IB - 1) * std::log10(2);
        static constexpr int max_digits10 = 0;
        static constexpr int radix        = 2;

        static constexpr int min_exponent   = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent   = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool traps           = true;
        static constexpr bool tinyness_before = false;

        static constexpr FIXED min()           noexcept { return FIXED::MinValue(); }
        static constexpr FIXED lowest()        noexcept { return min(); }
        static constexpr FIXED max()           noexcept { return FIXED::MaxValue(); }
        static constexpr FIXED epsilon()       noexcept { return {}; }
        static constexpr FIXED round_error()   noexcept { return {}; }
        static constexpr FIXED infinity()      noexcept { return {}; }
        static constexpr FIXED quiet_NaN()     noexcept { return {}; }
        static constexpr FIXED signaling_NaN() noexcept { return {}; }
        static constexpr FIXED denorm_min()    noexcept { return {}; }
    };
}
