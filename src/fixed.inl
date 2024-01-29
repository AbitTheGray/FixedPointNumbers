#pragma once
#include "fixed.hpp"

#include <cmath>

namespace fpn
{
    template<typename T>
        requires std::is_integral_v<T> && std::is_unsigned_v<T>
    [[nodiscard]] inline static constexpr T (BIT)(const T v) noexcept
    {
        return static_cast<T>(1u) << v;
    }
    template<typename T>
        requires std::is_integral_v<T> && std::is_unsigned_v<T>
    [[nodiscard]] inline static constexpr T (BITS)(const T v) noexcept
    {
        return BIT(v) - 1u;
    }
}
namespace fpn
{
    template <std::size_t IntegralBits, std::size_t FractionalBits>
    inline constexpr fixed<IntegralBits, FractionalBits>::fixed(
        const typename integer_bits<IntegralBits>::signed_type     integralValue,
        const typename integer_bits<FractionalBits>::unsigned_type fractionalValue
    ) noexcept
      : Value((integralValue << IntegralBits) + fractionalValue)
    {
        assert(integralValue   < BIT<std::size_t>(IntegralBits   + 1u));
        assert(fractionalValue < BIT<std::size_t>(FractionalBits + 1u));
    }
    template <std::size_t IntegralBits, std::size_t FractionalBits>
    template<std::size_t IB2, std::size_t FB2>
    inline constexpr fixed<IntegralBits, FractionalBits>::fixed(const fixed<IB2, FB2> other) noexcept
    {
        using TLarger = std::conditional_t<sizeof(decltype(Value)) >= sizeof(decltype(other.Value)), decltype(Value), decltype(other.Value)>;

        if constexpr(FractionalBits == FB2)
        {
            // Same amount of fractional bits.
            // Can juse use cast - same as casting between `int8` and `int16`
            Value = static_cast<decltype(Value)>(other.Value);
        }
        else
        {
            if constexpr(FractionalBits < FB2)
            {
                // Use other's value, just truncate additional bits
                Value = static_cast<decltype(Value)>(other.Value >> (FB2 - FractionalBits));
            }
            else // FractionalBits > FB2
            {
                // Use other's value, just add additional bits
                Value = static_cast<decltype(Value)>(static_cast<TLarger>(other.Value) << (FB2 - FractionalBits));
            }
        }

        // Limit total bits
        Value = Value & BITS(IntegralBits + FractionalBits);
    }
}
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator+(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return left + right;
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator-(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return left - right;
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator*(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return static_cast<double>(left) * static_cast<double>(right); //TODO Without floating-point math
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator/(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return static_cast<long double>(left) / static_cast<long double>(right); //TODO Without floating-point math
    }
}
namespace fpn
{
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    inline constexpr auto operator+(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const std::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const std::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) + fixed<IB, FB>(right);
    }
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    inline constexpr auto operator-(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const std::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const std::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) - fixed<IB, FB>(right);
    }
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    inline constexpr auto operator*(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const std::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const std::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) * fixed<IB, FB>(right);
    }
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    inline constexpr auto operator/(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const std::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const std::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) / fixed<IB, FB>(right);
    }
}
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB>::fixed(const std::integral auto value) noexcept
      : Value(static_cast<decltype(Value)>(value) << FB)
    {
    }
    template<std::size_t IB, std::size_t FB>
    template <typename TI> requires std::integral<TI>
    inline constexpr fixed<IB, FB>::operator TI() const noexcept
    {
        return Value >> FB;
    }
}
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator+(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return left + fixed<IB, FB>(right);
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator+(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(left) + right;
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator-(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return left - fixed<IB, FB>(right);
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator-(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(left) - right;
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator*(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return { left.Value * right };
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator*(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return { left * right.Value };
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator/(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return { left.Value / right };
    }
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB> operator/(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return { left / right.Value };
    }
}
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline constexpr fixed<IB, FB>::fixed(const std::floating_point auto value) noexcept
    {
#if FPN_CONSTEXPR_HAS == 1
        Value = static_cast<decltype(Value)>(std::round(value * BIT(FB)));
#else
        // Because MSVC does not have `constexpr` for `std::round`
        Value = static_cast<decltype(Value)>(value * BIT(FB));
#endif
    }
    template<std::size_t IB, std::size_t FB>
    template<typename TF>
        requires std::floating_point<TF>
    inline constexpr fixed<IB, FB>::operator TF() const noexcept
    {
        return static_cast<TF>(Value) / static_cast<TF>(BIT(FB));
    }
}
namespace fpn
{
    template<std::size_t IB, std::size_t FB>
    inline std::string to_string(const fixed<IB, FB> value)
    {
        return std::to_string(static_cast<double>(value));
    }
}
