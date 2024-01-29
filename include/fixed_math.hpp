#pragma once
#include "fixed.hpp"

namespace fpn
{
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
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> exp(fixed<IB, FB>) noexcept;
    /**
     * Returns 2 raised to the given power
     * @note 2^x
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> exp2(fixed<IB, FB>) noexcept;
    /**
     * Returns e raised to the given power, minus one
     * @note e^x - 1
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> expm1(fixed<IB, FB>) noexcept;
    /**
     * Computes natural (base e) logarithm
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> log(fixed<IB, FB>) noexcept;
    /**
     * Computes common (base 10) logarithm
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> log10(fixed<IB, FB>) noexcept;
    /**
     * Computes base 2 logarithm
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> log2(fixed<IB, FB>) noexcept;
    /**
     * Computes natural (base e) logarithm of 1 plus given number
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> log1p(fixed<IB, FB>) noexcept;
#pragma endregion

#pragma region Power functions
    /**
     * raises a number to the given power
     * @note x^y
     * @see https://en.wikipedia.org/wiki/Square_root
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> pow(fixed<IB, FB> x, fixed<IB, FB> y) noexcept;
    /**
     * Computes square root
     * @see https://en.wikipedia.org/wiki/Square_root
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> sqrt(fixed<IB, FB>) noexcept;
    /**
     * Computes cube root
     * @see https://en.wikipedia.org/wiki/Cube_root
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> cbrt(fixed<IB, FB>) noexcept;
    /**
     * Computes square root of the sum of the squares of two given numbers
     * @see https://en.wikipedia.org/wiki/Pythagorean_theorem
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> hypot(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    /**
     * Computes square root of the sum of the squares of three given numbers
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> hypot(fixed<IB, FB>, fixed<IB, FB>, fixed<IB, FB>) noexcept;
#pragma endregion

#pragma region Trigonometric functions
    /**
     * Computes sine
     * @see https://en.wikipedia.org/wiki/Sine_and_cosine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> sin(fixed<IB, FB> radians) noexcept;
    /**
     * Computes cosine
     * @see https://en.wikipedia.org/wiki/Sine_and_cosine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> cos(fixed<IB, FB> radians) noexcept;
    /**
     * Computes tangent
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> tan(fixed<IB, FB> radians) noexcept;
    /**
     * Computes arc sine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> asin(fixed<IB, FB> radians) noexcept;
    /**
     * Computes arc cosine
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> acos(fixed<IB, FB> radians) noexcept;
    /**
     * Computes arc tangent
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> atan(fixed<IB, FB> radians) noexcept;
    /**
     * Arc tangent, using signs to determine quadrants
     * @see https://en.wikipedia.org/wiki/Atan2
     * @see https://en.wikipedia.org/wiki/Inverse_trigonometric_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> atan2(fixed<IB, FB> y, fixed<IB, FB> x) noexcept;
#pragma endregion

#pragma region Hyperbolic functions
    /**
     * Computes hyperbolic sine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> sinh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes hyperbolic cosine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> cosh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes hyperbolic tangent
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> tanh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes the inverse hyperbolic sine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> asinh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes the inverse hyperbolic cosine
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> acosh(fixed<IB, FB> radians) noexcept;
    /**
     * Computes the inverse hyperbolic tangent
     * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> atanh(fixed<IB, FB> radians) noexcept;
#pragma endregion

#pragma region Error and gamma functions
    /**
     * Error function
     * @see https://en.wikipedia.org/wiki/Error_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> erf(fixed<IB, FB>) noexcept;
    /**
     * Complementary error function
     * @see https://en.wikipedia.org/wiki/Error_function#Complementary_error_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> erfc(fixed<IB, FB>) noexcept;
    /**
     * Gamma function
     * @see https://en.wikipedia.org/wiki/Gamma_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> tgamma(fixed<IB, FB>) noexcept;
    /**
     * Natural logarithm of the gamma function
     * @see https://en.wikipedia.org/wiki/Gamma_function
     */
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline FPN_CONSTEXPR fixed<IB, FB> lgamma(fixed<IB, FB>) noexcept;
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
}

#include "fixed_math.inl"
