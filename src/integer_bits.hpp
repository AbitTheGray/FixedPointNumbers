#pragma once

namespace Voxelite
{
    template<std::size_t T>
    struct integer_bits
    {
        using type          = integer_bits<T + 1>::type;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
    };
    template<>
    struct integer_bits<0>
    {
        using type          = void;
        using unsigned_type = void;
        using signed_type   = void;
    };
    template<>
    struct integer_bits<8>
    {
        using type          = int8_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
    };
    template<>
    struct integer_bits<16>
    {
        using type          = int16_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
    };
    template<>
    struct integer_bits<32>
    {
        using type          = int32_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
    };
    template<>
    struct integer_bits<64>
    {
        using type          = int64_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
    };
#ifdef __int128
    template<>
    struct integer_bits<128>
    {
        using type          = __int128;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
    };
#endif
}
