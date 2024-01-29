#pragma once
#include "fixed.hpp"

// Basic operations
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> abs(const fixed<IB, FB> value) noexcept
    {
        if(value > 0)
            return value;
        else
            return -value;
        //THINK Is this faster than worying about 2's complement (like in https://stackoverflow.com/a/6114214 ) ? Check compiler output first!
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> min(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return left <= right ? left : right;
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> max(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return left >= right ? left : right;
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> dim(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        if(left >= right)
            return left - right;
        else // left < right
            return right - left;
    }
    template<std::size_t IB, std::size_t FB>
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
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> exp(const fixed<IB, FB> value) noexcept
    {
        return std::exp(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> exp2(const fixed<IB, FB> value) noexcept
    {
        return std::exp2(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> expm1(const fixed<IB, FB> value) noexcept
    {
        return std::expm1(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> log(const fixed<IB, FB> value) noexcept
    {
        return std::log(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> log10(const fixed<IB, FB> value) noexcept
    {
        return std::log10(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> log2(const fixed<IB, FB> value) noexcept
    {
        return std::log2(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> log1p(const fixed<IB, FB> value) noexcept
    {
        return std::log1p(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
}
// Power functions
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> pow(fixed<IB, FB>, fixed<IB, FB>) noexcept
    {
        //TODO
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> sqrt(const fixed<IB, FB> value) noexcept
    {
        return std::sqrt(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> cbrt(const fixed<IB, FB> value) noexcept
    {
        return std::cbrt(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> hypot(const fixed<IB, FB> v0, const fixed<IB, FB> v1) noexcept
    {
        return std::hypot(static_cast<double>(v0), static_cast<double>(v1));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> hypot(const fixed<IB, FB> v0, const fixed<IB, FB> v1, const fixed<IB, FB> v2) noexcept
    {
        return std::hypot(static_cast<double>(v0), static_cast<double>(v1), static_cast<double>(v2));
        //TODO Fixed-point-number specific implementation
    }
}
// Trigonometric functions
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> sin(const fixed<IB, FB> value) noexcept
    {
        return std::sin(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> cos(const fixed<IB, FB> value) noexcept
    {
        return std::cos(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> tan(const fixed<IB, FB> value) noexcept
    {
        return std::tan(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> asin(const fixed<IB, FB> value) noexcept
    {
        return std::asin(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> acos(const fixed<IB, FB> value) noexcept
    {
        return std::acos(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> atan(const fixed<IB, FB> value) noexcept
    {
        return std::atan(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> atan2(fixed<IB, FB> y, fixed<IB, FB> x) noexcept
    {
        return std::atan2(static_cast<double>(y), static_cast<double>(x));
        //TODO Fixed-point-number specific implementation
    }
}
// Hyperbolic functions
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> sinh(const fixed<IB, FB> value) noexcept
    {
        return std::sinh(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> cosh(const fixed<IB, FB> value) noexcept
    {
        return std::cosh(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> tanh(const fixed<IB, FB> value) noexcept
    {
        return std::tanh(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> asinh(const fixed<IB, FB> value) noexcept
    {
        return std::asinh(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> acosh(const fixed<IB, FB> value) noexcept
    {
        return std::acosh(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> atanh(const fixed<IB, FB> value) noexcept
    {
        return std::atanh(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
}
// Error and gamma functions
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> erf(const fixed<IB, FB> value) noexcept
    {
        return std::erf(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> erfc(const fixed<IB, FB> value) noexcept
    {
        return std::erfc(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> tgamma(const fixed<IB, FB> value) noexcept
    {
        return std::tgamma(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> lgamma(const fixed<IB, FB> value) noexcept
    {
        return std::lgamma(static_cast<double>(value));
        //TODO Fixed-point-number specific implementation
    }
}
// Nearest integer operations
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> floor(const fixed<IB, FB> value) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    value.Value.Value & (~BITS(FB))
                )
            }
        );
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> ceil(const fixed<IB, FB> value) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    floor(value).Value.Value
                    + static_cast<typename fixed<IB, FB>::ValueType::T>((value.Value.Value & BITS(FB)) != 0 ? BIT(FB) : 0)
                )
            }
        );
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> trunc(const fixed<IB, FB> value) noexcept
    {
        if(value > 0)
            return floor(value);
        else
            return ceil(value);
    }
    template<std::size_t IB, std::size_t FB>
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
