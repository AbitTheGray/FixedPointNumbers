#pragma once

namespace fpn
{
    using size_t = uint64_t;
    
    template<fpn::size_t T>
    struct integer_bits
    {
        using type          = typename integer_bits<T + 1>::type;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;

        integer_bits() = delete;
    };
    template<>
    struct integer_bits<0>
    {
        using type          = void;
        using unsigned_type = void;
        using signed_type   = void;

        integer_bits() = delete;
    };
    template<>
    struct integer_bits<8>
    {
        using type          = int8_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
        static_assert(sizeof(unsigned_type) == 1);

        integer_bits() = delete;
    };
    template<>
    struct integer_bits<16>
    {
        using type          = int16_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
        static_assert(sizeof(unsigned_type) == 2);

        integer_bits() = delete;
    };
    template<>
    struct integer_bits<32>
    {
        using type          = int32_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
        static_assert(sizeof(unsigned_type) == 4);

        integer_bits() = delete;
    };
    template<>
    struct integer_bits<64>
    {
        using type          = int64_t;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
        static_assert(sizeof(unsigned_type) == 8);

        integer_bits() = delete;

        static_assert(sizeof(fpn::size_t) >= sizeof(uint64_t));
    };
/*
#ifdef __SIZEOF_INT128__
    template<>
        requires sizeof(fpn::size_t) >= sizeof(__int128)
    struct integer_bits<128>
    {
        using type          = __int128;
        using unsigned_type = std::make_unsigned_t<type>;
        using signed_type   = std::make_signed_t<type>;
        static_assert(sizeof(unsigned_type) == 16);

        integer_bits() = delete;

        static_assert(sizeof(fpn::size_t) >= sizeof(__int128));
    };
#endif
*/
}
