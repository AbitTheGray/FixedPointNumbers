#pragma once
#include <cstdint>

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
