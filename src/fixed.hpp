#pragma once
#include <cstdint>
#include <type_traits>
#include <concepts>
#include <compare>
#include <string>

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
        inline constexpr fixed(fixed<IB2, FB2>) noexcept;

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
        inline static const fixed e          = std::numbers::e_v<double>;
        inline static const fixed log2e      = std::numbers::log2e_v<double>;
        inline static const fixed log10e     = std::numbers::log10e_v<double>;
        inline static const fixed pi         = std::numbers::pi_v<double>;
        inline static const fixed inv_pi     = std::numbers::inv_pi_v<double>;
        inline static const fixed inv_sqrtpi = std::numbers::inv_sqrtpi_v<double>;
        inline static const fixed ln2        = std::numbers::ln2_v<double>;
        inline static const fixed ln10       = std::numbers::ln10_v<double>;
        inline static const fixed sqrt2      = std::numbers::sqrt2_v<double>;
        inline static const fixed sqrt3      = std::numbers::sqrt3_v<double>;
        inline static const fixed egamma     = std::numbers::egamma_v<double>;
        inline static const fixed phi        = std::numbers::phi_v<double>;
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
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, fixed<IB, FB>) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline std::string to_string(fixed<IB, FB>);

#pragma region Other fixed-point numbers
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator+(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator-(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator*(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator/(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
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
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(std::integral auto, fixed<IB, FB>) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator%(fixed<IB, FB>, std::integral auto) noexcept;
#pragma endregion

#pragma region Math functions/operations
#pragma region Basic operations
    /**
     * Absolute value.
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> abs(fixed<IB, FB>) noexcept;
    /**
     * Smaller of two values.
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> min(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    /**
     * Larger of two values.
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> max(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    /**
     * Positive difference of two floating point values.
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> dim(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    /**
     * Get sign value of the number.
     * @note Can be -1, 0 or 1
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr int8_t sign(fixed<IB, FB>) noexcept;
#pragma endregion
#pragma region Exponential functions
    /**
     * Returns e raised to the given power
     * @note e^x
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> exp(fixed<IB, FB>) noexcept;
    /**
     * Returns 2 raised to the given power
     * @note 2^x
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> exp2(fixed<IB, FB>) noexcept;
    /**
     * Returns e raised to the given power, minus one
     * @note e^x - 1
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> expm1(fixed<IB, FB>) noexcept;
    /**
     * Computes natural (base e) logarithm
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> log(fixed<IB, FB>) noexcept;
    /**
     * Computes common (base 10) logarithm
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> log10(fixed<IB, FB>) noexcept;
    /**
     * Computes base 2 logarithm
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> log2(fixed<IB, FB>) noexcept;
    /**
     * Computes natural (base e) logarithm of 1 plus given number
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> log1p(fixed<IB, FB>) noexcept;
#pragma endregion
#pragma region Power functions
    /**
     * raises a number to the given power
     * @note x^y
     * @see https://en.wikipedia.org/wiki/Square_root
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> pow(fixed<IB, FB> x, fixed<IB, FB> y) noexcept;
    /**
     * Computes square root
     * @see https://en.wikipedia.org/wiki/Square_root
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> sqrt(fixed<IB, FB>) noexcept;
    /**
     * Computes cube root
     * @see https://en.wikipedia.org/wiki/Cube_root
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> cbrt(fixed<IB, FB>) noexcept;
    /**
     * Computes square root of the sum of the squares of two given numbers
     * @see https://en.wikipedia.org/wiki/Pythagorean_theorem
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> hypot(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    /**
     * Computes square root of the sum of the squares of three given numbers
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> hypot(fixed<IB, FB>, fixed<IB, FB>, fixed<IB, FB>) noexcept;
#pragma endregion
#pragma region Trigonometric functions
    /**
     * Computes sine
     * @see https://en.wikipedia.org/wiki/Sine_and_cosine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> sin(fixed<IB, FB> radians) noexcept;
    /**
     * Computes cosine
     * @see https://en.wikipedia.org/wiki/Sine_and_cosine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> cos(fixed<IB, FB> radians) noexcept;
    /**
     * Computes tangent
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> tan(fixed<IB, FB> radians) noexcept;
    /**
     * Computes arc sine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> asin(fixed<IB, FB> radians) noexcept;
    /**
     * Computes arc cosine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> acos(fixed<IB, FB> radians) noexcept;
    /**
     * Computes arc tangent
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> atan(fixed<IB, FB> radians) noexcept;
    /**
     * Arc tangent, using signs to determine quadrants
     * @see https://en.wikipedia.org/wiki/Atan2
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> atan2(fixed<IB, FB> y, fixed<IB, FB> x) noexcept;
#pragma endregion
#pragma region Hyperbolic functions
    /**
     * Computes hyperbolic sine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> sinh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes hyperbolic cosine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> cosh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes hyperbolic tangent
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> tanh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes the inverse hyperbolic sine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> asinh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes the inverse hyperbolic cosine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> acosh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes the inverse hyperbolic tangent
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> atanh(fixed<IB, FB> radians) noexcept;
#pragma endregion
#pragma region Error and gamma functions
    /**
     * Error function
     * @see https://en.wikipedia.org/wiki/Error_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> erf(fixed<IB, FB>) noexcept;
    /**
     * Complementary error function
     * @see https://en.wikipedia.org/wiki/Error_function#Complementary_error_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> erfc(fixed<IB, FB>) noexcept;
    /**
     * Gamma function
     * @see https://en.wikipedia.org/wiki/Gamma_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> tgamma(fixed<IB, FB>) noexcept;
    /**
     * Natural logarithm of the gamma function
     * @see https://en.wikipedia.org/wiki/Gamma_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> lgamma(fixed<IB, FB>) noexcept;
#pragma endregion
#pragma region Nearest integer operations
    /**
     * Nearest integer not less than the given value
     * @note Round up
     * @note 1.0 -> 1.0 ; 1.1 -> 2.0
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> ceil(fixed<IB, FB>) noexcept;
    /**
     * Nearest integer not greater than the given value
     * @note Round down
     * @note 1.0 -> 1.0 ; 1.1 -> 1.0
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> floor(fixed<IB, FB>) noexcept;
    /**
     * Nearest integer not greater in magnitude than the given value
     * @note Round towards zero
     * @note 0.1 -> 0.0 ; -0.1 -> -0.0
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> trunc(fixed<IB, FB>) noexcept;
    /**
     * Nearest integer, rounding away from zero in halfway cases
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> round(fixed<IB, FB>) noexcept;
#pragma endregion
#pragma endregion

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

    using fixed32_8  = fixed<32,  8>;
    using fixed32_16 = fixed<32, 16>;
    using fixed32_24 = fixed<32, 24>;
    using fixed32_32 = fixed<32, 32>;
}

#include "fixed.inl"
#include "fixed_math.inl"

template<std::size_t IB, std::size_t FB>
struct std::hash<fpn::fixed<IB, FB>>
{
    [[nodiscard]] std::size_t operator()(const fpn::fixed<IB, FB>& value) const noexcept\
    {
        return value.Value;
    }
};
