#pragma once
#include "fixed.hpp"

#include <cmath>
#include <stdexcept>

// Utility functions
namespace fpn
{
    /**
     * Get number with only specified bit set.
     */
    template<typename T>
        requires std::is_integral_v<T> && std::is_unsigned_v<T>
    [[nodiscard]] inline static constexpr T (BIT)(const T v) noexcept
    {
        return static_cast<T>(1u) << v;
    }
    static_assert(BIT<uint8_t>(0) == 0b0000'0001u);
    static_assert(BIT<uint8_t>(1) == 0b0000'0010u);
    static_assert(BIT<uint8_t>(2) == 0b0000'0100u);
    static_assert(BIT<uint8_t>(3) == 0b0000'1000u);
    static_assert(BIT<uint8_t>(4) == 0b0001'0000u);
    static_assert(BIT<uint8_t>(5) == 0b0010'0000u);
    static_assert(BIT<uint8_t>(6) == 0b0100'0000u);
    static_assert(BIT<uint8_t>(7) == 0b1000'0000u);
    /**
     * Get number with specified number of bits set.
     * @note Always least significant bits
     */
    template<typename T>
        requires std::is_integral_v<T> && std::is_unsigned_v<T>
    [[nodiscard]] inline static constexpr T (BITS)(const T v) noexcept
    {
        return BIT<T>(v) - 1u;
    }
    static_assert(BITS<uint8_t>(0) == 0b0000'0000u);
    static_assert(BITS<uint8_t>(1) == 0b0000'0001u);
    static_assert(BITS<uint8_t>(2) == 0b0000'0011u);
    static_assert(BITS<uint8_t>(3) == 0b0000'0111u);
    static_assert(BITS<uint8_t>(4) == 0b0000'1111u);
    static_assert(BITS<uint8_t>(5) == 0b0001'1111u);
    static_assert(BITS<uint8_t>(6) == 0b0011'1111u);
    static_assert(BITS<uint8_t>(7) == 0b0111'1111u);
    static_assert(BITS<uint8_t>(8) == 0b1111'1111u);
    /**
     * Crops the number to specified number of bits.
     * @note Same as using (v & BITS(bits)) for signed numbers.
     */
    template<typename T>
        requires std::is_integral_v<T> && std::is_signed_v<T>
    [[nodiscard]] inline static constexpr T TruncateBits_Signed(const T v, const fpn::size_t keepBits) noexcept
    {
        if(keepBits == sizeof(T) * 8)
            return v;
        if(v >= 0)
            return v & BITS(keepBits);
        else
            return (v & BITS(keepBits)) /* bits we don't want to change */ | (~BITS(keepBits)) /* bits we want to be set */;
    }
    static_assert(TruncateBits_Signed(1, 2) == 1);
    static_assert(TruncateBits_Signed(2, 2) == 2);
    static_assert(TruncateBits_Signed(1, 4) == 1);
    static_assert(TruncateBits_Signed(2, 4) == 2);
    static_assert(TruncateBits_Signed(-1, 4) == -1);
    static_assert(TruncateBits_Signed(-2, 4) == -2);
    static_assert(TruncateBits_Signed(-15, 4) == -15);
    static_assert(TruncateBits_Signed(-16, 4) == -16);
    static_assert(TruncateBits_Signed(-17, 4) == -1);
    static_assert(TruncateBits_Signed(-64, 4) == -16);
}
// Constructors
namespace fpn
{
    template<fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    inline constexpr fixed<IntegralBits, FractionalBits>::fixed(const ValueType value) noexcept
      : Value({TruncateBits_Signed(value.Value, IntegralBits + FractionalBits)})
    //  : Value(value)
    {
    }
    template<fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    inline constexpr fixed<IntegralBits, FractionalBits>::fixed(
        const typename integer_bits<IntegralBits>::signed_type     integralValue,
        const typename integer_bits<FractionalBits>::unsigned_type fractionalValue
    )
      : Value({static_cast<typename ValueType::T>((integralValue << IntegralBits) | fractionalValue)})
    {
        if(integralValue != TruncateBits_Signed(integralValue, IntegralBits))
        {
            if(std::is_constant_evaluated())
                Value = 0;
            else
                throw std::runtime_error("Too big integral value");
        }
        if(fractionalValue != (fractionalValue & BITS(FractionalBits)))
        {
            if(std::is_constant_evaluated())
                Value = 0;
            else
                throw std::runtime_error("Too big fractional value");
        }
    }
    template<fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    template<fpn::size_t IB2, fpn::size_t FB2>
    inline constexpr fixed<IntegralBits, FractionalBits>::fixed(const fixed<IB2, FB2> other) noexcept
    {
        using TLarger = std::conditional_t<sizeof(typename ValueType::T) >= sizeof(decltype(other.Value.Value)), typename ValueType::T, decltype(other.Value.Value)>;

        if constexpr(FractionalBits == FB2)
        {
            // Same amount of fractional bits.
            // Can juse use cast - same as casting between `int8` and `int16`
            Value.Value = static_cast<typename ValueType::T>(other.Value.Value);
        }
        else
        {
            if constexpr(FractionalBits < FB2)
            {
                // Use other's value, just truncate additional bits
                Value.Value = static_cast<typename ValueType::T>(other.Value.Value >> (FB2 - FractionalBits));
            }
            else // FractionalBits > FB2
            {
                // Use other's value, just add additional bits
                Value.Value = static_cast<typename ValueType::T>(static_cast<TLarger>(other.Value.Value) << (FractionalBits - FB2));
            }
        }

        // Limit total bits
        Value.Value = TruncateBits_Signed(Value.Value, IntegralBits + FractionalBits);
    }
    template <fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    constexpr fixed<IntegralBits, FractionalBits>::fixed(const std::string& value) noexcept
      : fixed(std::stod(value))
    {
        //TODO
    }
}
// Integral + Fractional Values
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr typename integer_bits<IB>::signed_type fixed<IB, FB>::IntegralPart() const noexcept
    {
        return static_cast<typename integer_bits<IB>::signed_type>(Value.Value >> FB);
    }
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr typename integer_bits<FB>::unsigned_type fixed<IB, FB>::FractionalPart() const noexcept
    {
        return static_cast<typename integer_bits<FB>::unsigned_type>(Value.Value) & BITS(FB);
    }
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> fixed<IB, FB>::IntegralValue() const noexcept
    {
        return fixed( ValueType{ static_cast<typename ValueType::T>(Value.Value & ~BITS(FB)) } );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> fixed<IB, FB>::FractionalValue() const noexcept
    {
        return fixed( ValueType{ static_cast<typename ValueType::T>(Value.Value & BITS(FB)) } );
    }
}
// Min + Max values
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    constexpr fixed<IB, FB> fixed<IB, FB>::MinValue() noexcept
    {
        return fixed( ValueType( static_cast<typename ValueType::T>(BIT(IB + FB - 1u)) ) );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    constexpr fixed<IB, FB> fixed<IB, FB>::MaxValue() noexcept
    {
        return fixed( ValueType( ~static_cast<typename ValueType::T>(BIT(IB + FB - 1u)) ) );
    }
}
// Fixed-point mathematical operators
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator+(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    left.Value.Value + right.Value.Value
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator-(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    left.Value.Value - right.Value.Value
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator*(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        // Best visualization of this algorithm can be found at https://i.stack.imgur.com/oOMA8.png / https://stackoverflow.com/a/75718789
        using T = typename fixed<IB, FB>::ValueType::T;
        using UT = std::make_unsigned_t<T>;

        const auto leftI = static_cast<T>(left.IntegralPart());
        const auto rightI = static_cast<T>(right.IntegralPart());
        const auto leftF = static_cast<UT>(left.FractionalPart());
        const auto rightF = static_cast<UT>(right.FractionalPart());

        const auto a = (leftF * rightF) >> FB;
        const auto b = leftI * rightF;
        const auto c = rightI * leftF;
        const auto d = TruncateBits_Signed(leftI * rightI, IB) << FB;

        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    a + b + c + d
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator/(const fixed<IB, FB> left, const fixed<IB, FB> right) noexcept
    {
        if constexpr(IB + FB * 2 <= sizeof(fpn::size_t) * 8) // Can use higher integer
        {
            using HigherT = typename integer_bits<IB + FB * 2>::signed_type;

            return fixed<IB, FB>(
                typename fixed<IB, FB>::ValueType{
                    static_cast<typename fixed<IB, FB>::ValueType::T>(
                        (
                            static_cast<HigherT>(left.Value.Value) << FB
                        ) / right.Value.Value
                    )
                }
            );
        }

#ifdef __SIZEOF_INT128__
        if constexpr(IB + FB * 2 <= sizeof(__int128) * 8)
        {
            using HigherT = __int128;

            return fixed<IB, FB>(
                typename fixed<IB, FB>::ValueType{
                    static_cast<typename fixed<IB, FB>::ValueType::T>(
                        (
                            static_cast<HigherT>(left.Value.Value) << FB
                        ) / right.Value.Value
                    )
                }
            );
        }
#endif

        return left * inverse(right);
    }
    template<fpn::size_t IB, fpn::size_t FB> requires (FB * 2 < sizeof(typename fixed<IB, FB>::ValueType::T) * 8)
    inline constexpr fixed<IB, FB> inverse(const fixed<IB, FB> value) noexcept
    {
        using T = typename fixed<IB, FB>::ValueType::T;
        using UT = std::make_unsigned_t<T>;
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<T>(BIT<UT>(FB + FB)) / value.Value.Value
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> inverse(const fixed<IB, FB> input) noexcept
    {
        using T = typename fixed<IB, FB>::ValueType::T;
        using UT = std::make_unsigned_t<T>;
        UT absInput = static_cast<UT>(abs(input).Value.Value);
        T value = 0;

        // This is not an optimal way but it is working without support for 128-bit integer (on 64-bit systems).
        // If you are using a type afected by this, it is recommended to use a library for 128-bit integer and define both `__int128` (typedef?) and `__SIZEOF_INT128__`=16
        for(fpn::size_t bit = 0; bit < IB + FB; bit++)
        {
            if(absInput & BIT(bit))
                value += BIT<UT>(2 * FB  - bit);
        }

        fixed<IB, FB> outValue = fixed<IB, FB>( typename fixed<IB, FB>::ValueType{ value } );

        return (input >= 0) ? outValue : -outValue;
    }
}
// Different fixed-point mathematical operators
namespace fpn
{
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    inline constexpr auto operator+(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const fpn::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const fpn::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) + fixed<IB, FB>(right);
    }
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    inline constexpr auto operator-(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const fpn::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const fpn::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) - fixed<IB, FB>(right);
    }
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    inline constexpr auto operator*(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const fpn::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const fpn::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) * fixed<IB, FB>(right);
    }
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    inline constexpr auto operator/(const fixed<IB1, FB1> left, const fixed<IB2, FB2> right) noexcept
    {
        static_assert(IB1 != IB2 || FB1 != FB2);
        const fpn::size_t IB = IB1 > IB2 ? IB1 : IB2; // std::max(IB1, IB2)
        const fpn::size_t FB = FB1 > FB2 ? FB1 : FB2; // std::max(FB1, FB2)

        return fixed<IB, FB>(left) / fixed<IB, FB>(right);
    }
}
// Integral conversion
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB>::fixed(const std::integral auto value) noexcept
      : Value({ static_cast<typename ValueType::T>( static_cast<typename ValueType::T>(value) << FB ) })
    {
    }
    template<fpn::size_t IB, fpn::size_t FB>
    template<typename TI> requires std::integral<TI>
    inline constexpr fixed<IB, FB>::operator TI() const noexcept
    {
        return static_cast<TI>(Value.Value >> FB);
    }
}
// Integral mathematical operators
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator+(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return left + fixed<IB, FB>(right);
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator+(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(left) + right;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator-(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return left - fixed<IB, FB>(right);
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator-(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(left) - right;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator*(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    left.Value.Value * right
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator*(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    left * right.Value.Value
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator/(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    left.Value.Value / right
                )
            }
        );
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator/(const std::integral auto left, const fixed<IB, FB> right) noexcept
    {
        return fixed<IB, FB>(left) / right;
    }
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB> operator%(const fixed<IB, FB> left, const std::integral auto right) noexcept
    {
        return fixed<IB, FB>(
            typename fixed<IB, FB>::ValueType{
                static_cast<typename fixed<IB, FB>::ValueType::T>(
                    ((left.Value.Value >> FB) % right) << FB
                )
            }
        ) + left.FractionalValue();
    }
}
// Floating-point conversion
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline FPN_CONSTEXPR fixed<IB, FB>::fixed(const std::floating_point auto value) noexcept
    {
        if(std::isnan(value) || std::isinf(value))
            Value = {};
        else
            Value.Value = static_cast<typename ValueType::T>(std::round(value * BIT(FB)));
            //Value.Value = static_cast<typename ValueType::T>(value * BIT(FB));
    }
    template<fpn::size_t IB, fpn::size_t FB>
    template<typename TF>
        requires std::floating_point<TF>
    inline constexpr fixed<IB, FB>::operator TF() const noexcept
    {
        return static_cast<TF>(Value.Value) / static_cast<TF>(BIT(FB));
    }
}
// to_string
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline std::string to_string(const fixed<IB, FB> value)
    {
        return std::to_string(static_cast<double>(value)); //TODO
    }
    template<typename CharT, fpn::size_t IB, fpn::size_t FB>
    std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& out, const fixed<IB, FB> value) noexcept
    {
        if constexpr(std::is_same_v<CharT, char>)
            return out << std::to_string(static_cast<double>(value));
        else
            return out << static_cast<double>(value);
    }
}
// Increment/Decrement operators
namespace fpn
{
    template <fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    inline constexpr fixed<IntegralBits, FractionalBits>& fixed<IntegralBits, FractionalBits>::operator++() noexcept
    {
        Value = (*this + 1).Value;
        return *this;
    }
    template <fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    inline constexpr fixed<IntegralBits, FractionalBits>& fixed<IntegralBits, FractionalBits>::operator--() noexcept
    {
        Value = (*this - 1).Value;
        return *this;
    }
    template <fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    inline constexpr const fixed<IntegralBits, FractionalBits> fixed<IntegralBits, FractionalBits>::operator++(int) noexcept
    {
        auto temp = *this;
        Value = (*this + 1).Value;
        return temp;
    }
    template <fpn::size_t IntegralBits, fpn::size_t FractionalBits>
    inline constexpr const fixed<IntegralBits, FractionalBits> fixed<IntegralBits, FractionalBits>::operator--(int) noexcept
    {
        auto temp = *this;
        Value = (*this - 1).Value;
        return temp;
    }
}
