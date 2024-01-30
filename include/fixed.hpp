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
     * Fixed-point numbers.
     */
    template<std::size_t IntegralBits, std::size_t FractionalBits>
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

        inline constexpr fixed() noexcept : Value() {}
        inline explicit constexpr fixed(ValueType) noexcept;
        inline explicit constexpr fixed(
            typename integer_bits<IntegralBits>::signed_type     integralValue,
            typename integer_bits<FractionalBits>::unsigned_type fractionalValue
        ) noexcept;
        template<std::size_t IB2, std::size_t FB2>
        inline explicit constexpr fixed(fixed<IB2, FB2>) noexcept;

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
        [[nodiscard]] [[deprecated]] inline constexpr typename integer_bits<IntegralBits>::signed_type IntegralPart() const noexcept;
        /**
         * Raw representation of the fractional part of this number.
         */
        [[nodiscard]] [[deprecated]] inline constexpr typename integer_bits<FractionalBits>::unsigned_type FractionalPart() const noexcept;
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

        /*
        [[nodiscard]] inline constexpr fixed operator++() noexcept;
        [[nodiscard]] inline constexpr fixed operator--() noexcept;
        [[nodiscard]] inline constexpr fixed operator++(int) noexcept;
        [[nodiscard]] inline constexpr fixed operator--(int) noexcept;
        */

#pragma region Integers
        inline constexpr fixed(std::integral auto) noexcept;

        template<typename TI>
            requires std::integral<TI>
        [[nodiscard]] inline constexpr operator TI() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::integral auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::integral auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion

#pragma region Floating-point numbers
        inline constexpr explicit fixed(std::floating_point auto) noexcept;

        template<typename TF>
            requires std::floating_point<TF>
        [[nodiscard]] inline constexpr explicit operator TF() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::floating_point auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::floating_point auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion
    };

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline fixed<IB, FB> operator*(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline fixed<IB, FB> operator/(fixed<IB, FB>, fixed<IB, FB>) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline std::string to_string(fixed<IB, FB>);

#pragma region Other fixed-point numbers
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator+(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator-(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline auto operator*(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline auto operator/(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
#pragma endregion

#pragma region Integers
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, std::integral auto) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, std::integral auto) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, std::integral auto) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, std::integral auto) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(std::integral auto, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(std::integral auto, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(std::integral auto, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline fixed<IB, FB> operator/(std::integral auto, fixed<IB, FB>) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator%(fixed<IB, FB>, std::integral auto) noexcept;
#pragma endregion

#if __SIZEOF_POINTER__ >= 8
    using fixed8_8  = fixed<8,  8>;
    using fixed8_16 = fixed<8, 16>;
    using fixed8_24 = fixed<8, 24>;
    using fixed8_32 = fixed<8, 32>;
    using fixed8_40 = fixed<8, 40>;
    using fixed8_48 = fixed<8, 48>;
    using fixed8_56 = fixed<8, 56>;
    
    using fixed16_8  = fixed<16,  8>;
    using fixed16_16 = fixed<16, 16>;
    using fixed16_24 = fixed<16, 24>;
    using fixed16_32 = fixed<16, 32>;
    using fixed16_40 = fixed<16, 40>;
    using fixed16_48 = fixed<16, 48>;

    using fixed24_8  = fixed<24,  8>;
    using fixed24_16 = fixed<24, 16>;
    using fixed24_24 = fixed<24, 24>;
    using fixed24_32 = fixed<24, 32>;
    using fixed24_40 = fixed<24, 40>;

    using fixed32_8  = fixed<32,  8>;
    using fixed32_16 = fixed<32, 16>;
    using fixed32_24 = fixed<32, 24>;
    using fixed32_32 = fixed<32, 32>;

    using fixed48_8  = fixed<48,  8>;
    using fixed48_16 = fixed<48, 16>;

    using fixed56_8  = fixed<56,  8>;
#else
    using fixed8_8  = fixed<8,  8>;
    using fixed8_16 = fixed<8, 16>;
    using fixed8_24 = fixed<8, 24>;

    using fixed16_8  = fixed<16,  8>;
    using fixed16_16 = fixed<16, 16>;

    using fixed24_8  = fixed<24,  8>;
    using fixed24_16 = fixed<24, 16>;
#endif
}

#include "fixed.inl"

template<std::size_t IB, std::size_t FB>
struct std::hash<fpn::fixed<IB, FB>>
{
    [[nodiscard]] std::size_t constexpr operator()(const fpn::fixed<IB, FB>& value) const noexcept
    {
        return value.Value.Value;
    }
};
