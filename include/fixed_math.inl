#pragma once
#include "fixed_math.hpp"

// Basic operations
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> abs(const fixed<IB, FB> value) noexcept
    {
        if(value > 0)
            return value;
        else
            return -value;
        //THINK Is this faster than worying about 2's complement (like in https://stackoverflow.com/a/6114214 ) ? Check compiler output first!
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> min(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return left <= right ? left : right;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> max(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return left >= right ? left : right;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> dim(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        if(left >= right)
            return left - right;
        else // left < right
            return right - left;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr int8_t sign(const fixed<IB, FB> value) noexcept
    {
        if(value.Value.Value == 0)
            return 0;
        if(value.Value.Value > 0)
            return 1;
        //if(value.Value.Value < 0)
        return -1;
    }
}
// Exponential functions
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> exp(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::exp(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> exp2(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::exp2(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> expm1(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::expm1(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> log(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::log(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> log10(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::log10(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> log2(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::log2(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> log1p(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::log1p(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
}
// Power functions
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> pow(const fixed<IB, FB> x, const fixed<IB, FB> y) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::pow(static_cast<double>(x), static_cast<double>(y))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> sqrt(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::sqrt(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> cbrt(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::cbrt(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> hypot(const fixed<IB, FB> v0, const fixed<IB, FB> v1) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::hypot(static_cast<double>(v0), static_cast<double>(v1))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> hypot(const fixed<IB, FB> v0, const fixed<IB, FB> v1, const fixed<IB, FB> v2) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::hypot(static_cast<double>(v0), static_cast<double>(v1), static_cast<double>(v2))
        );
        //TODO Fixed-point-number specific implementation
    }
}
// Trigonometric functions
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> sin(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::sin(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> cos(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::cos(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> tan(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::tan(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> asin(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::asin(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> acos(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::acos(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> atan(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::atan(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> atan2(fixed<IB, FB> y, fixed<IB, FB> x) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::atan2(static_cast<double>(y), static_cast<double>(x))
        );
        //TODO Fixed-point-number specific implementation
    }
}
// Hyperbolic functions
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> sinh(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::sinh(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> cosh(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::cosh(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> tanh(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::tanh(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> asinh(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::asinh(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> acosh(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::acosh(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> atanh(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::atanh(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
}
// Error and gamma functions
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> erf(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::erf(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> erfc(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::erfc(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> tgamma(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::tgamma(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> lgamma(const fixed<IB, FB> value) noexcept
    {
        return fpn::fixed<IB, FB>(
            std::lgamma(static_cast<double>(value))
        );
        //TODO Fixed-point-number specific implementation
    }
}
// Nearest integer operations
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> floor(const fixed<IB, FB> value) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::T>(
                    value.Value.Value & (~BITS(FB))
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> ceil(const fixed<IB, FB> value) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::T>(
                    floor(value).Value.Value
                    + static_cast<typename fixed<IB, FB>::T>((value.Value.Value & BITS(FB)) != 0 ? BIT(FB) : 0)
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> trunc(const fixed<IB, FB> value) noexcept
    {
        if(value > 0)
            return floor(value);
        else
            return ceil(value);
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> round(const fixed<IB, FB> value) noexcept
    {
        const auto fractional = value.FractionalValue();
        if(fractional > 0.5)
            return ceil(value);
        if(fractional == 0.5)
        {
            if(value >= 0)
                return ceil(value);
            else
                return floor(value);
        }
        //if(fractional < 0.5)
        return floor(value);
    }
}
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> degrees(const fixed<IB, FB> radians) noexcept
    {
        return radians * std::numbers::template pi_v<double> / 180;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB> radians(const fixed<IB, FB> degrees) noexcept
    {
        return degrees / std::numbers::template pi_v<double> * 180;
    }
}
