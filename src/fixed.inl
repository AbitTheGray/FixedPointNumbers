#pragma once
#include "fixed.hpp"

#include <cmath>

namespace Voxelite
{
    template<typename T>
        requires std::is_integral_v<T> && std::is_unsigned_v<T>
    [[nodiscard]] inline static constexpr T (BIT)(T v) noexcept
    {
        return 1u << v;
    }
}
namespace Voxelite
{
    inline constexpr fixed32_16 operator+(const fixed32_16 left, const fixed32_16 right) noexcept
    {
        return left + right;
    }
    inline constexpr fixed32_16 operator-(const fixed32_16 left, const fixed32_16 right) noexcept
    {
        return left - right;
    }
    inline constexpr fixed32_16 operator*(const fixed32_16 left, const fixed32_16 right) noexcept
    {
        return static_cast<long double>(left) * static_cast<long double>(right); //TODO Without floating-point math
    }
    inline constexpr fixed32_16 operator/(const fixed32_16 left, const fixed32_16 right) noexcept
    {
        return static_cast<long double>(left) / static_cast<long double>(right); //TODO Without floating-point math
    }
}
namespace Voxelite
{
    inline constexpr fixed32_16::fixed32_16(const std::integral auto value) noexcept
      : Value(value << FractionalBits)
    {
    }
    template <typename TI> requires std::integral<TI>
    inline constexpr fixed32_16::operator TI() const noexcept
    {
        return Value >> FractionalBits;
    }
}
namespace Voxelite
{
    inline constexpr fixed32_16 operator+(const fixed32_16 left, const std::integral auto right) noexcept
    {
        return left + fixed32_16(right);
    }
    inline constexpr fixed32_16 operator+(const std::integral auto left, const fixed32_16 right) noexcept
    {
        return fixed32_16(left) + right;
    }
    inline constexpr fixed32_16 operator-(const fixed32_16 left, const std::integral auto right) noexcept
    {
        return left - fixed32_16(right);
    }
    inline constexpr fixed32_16 operator-(const std::integral auto left, const fixed32_16 right) noexcept
    {
        return fixed32_16(left) - right;
    }
    inline constexpr fixed32_16 operator*(const fixed32_16 left, const std::integral auto right) noexcept
    {
        return { left.Value * right };
    }
    inline constexpr fixed32_16 operator*(const std::integral auto left, const fixed32_16 right) noexcept
    {
        return { left * right.Value };
    }
    inline constexpr fixed32_16 operator/(const fixed32_16 left, const std::integral auto right) noexcept
    {
        return { left.Value / right };
    }
    inline constexpr fixed32_16 operator/(const std::integral auto left, const fixed32_16 right) noexcept
    {
        return { left / right.Value };
    }
}
namespace Voxelite
{
    inline constexpr fixed32_16::fixed32_16(const std::floating_point auto value) noexcept
    {
        //Value = static_cast<decltype(Value)>(value * BIT(FractionalBits));
        Value = static_cast<decltype(Value)>(std::round(value * BIT(FractionalBits)));
    }
    template<typename TF>
        requires std::floating_point<TF>
    inline constexpr fixed32_16::operator TF() const noexcept
    {
        return static_cast<TF>(Value) / static_cast<TF>(BIT(FractionalBits));
    }
}
namespace Voxelite
{
    inline std::string to_string(const fixed32_16 value)
    {
        return std::to_string(static_cast<double>(value));
    }
}
