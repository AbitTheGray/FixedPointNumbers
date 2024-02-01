#include "fixed.hpp"

// fixed8_8 <-> fixed8_16
namespace fpn
{
    static_assert(fixed8_8()  == fixed8_8(fixed8_16()));
    static_assert(fixed8_16() == fixed8_16(fixed8_8()));

    static_assert(fixed8_8( 0) == fixed8_8(fixed8_16(0)));
    static_assert(fixed8_16(0) == fixed8_16(fixed8_8(0)));

    static_assert(fixed8_8( 1) == fixed8_8(fixed8_16(1)));
    static_assert(fixed8_16(1) == fixed8_16(fixed8_8(1)));

    static_assert(fixed8_8( 2) == fixed8_8(fixed8_16(2)));
    static_assert(fixed8_16(2) == fixed8_16(fixed8_8(2)));

    static_assert(fixed8_8( -1) == fixed8_8(fixed8_16(-1)));
    static_assert(fixed8_16(-1) == fixed8_16(fixed8_8(-1)));

    static_assert(fixed8_8( -2) == fixed8_8(fixed8_16(-2)));
    static_assert(fixed8_16(-2) == fixed8_16(fixed8_8(-2)));

#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.125) == fixed8_8(fixed8_16(0.125)));
    static_assert(fixed8_16(0.125) == fixed8_16(fixed8_8(0.125)));

    static_assert(fixed8_8( 1.125) == fixed8_8(fixed8_16(1.125)));
    static_assert(fixed8_16(1.125) == fixed8_16(fixed8_8(1.125)));

    static_assert(fixed8_8( 2.125) == fixed8_8(fixed8_16(2.125)));
    static_assert(fixed8_16(2.125) == fixed8_16(fixed8_8(2.125)));

    static_assert(fixed8_8( -1.125) == fixed8_8(fixed8_16(-1.125)));
    static_assert(fixed8_16(-1.125) == fixed8_16(fixed8_8(-1.125)));

    static_assert(fixed8_8( -2.125) == fixed8_8(fixed8_16(-2.125)));
    static_assert(fixed8_16(-2.125) == fixed8_16(fixed8_8(-2.125)));
#endif
}
// fixed8_8 <-> fixed8_24
namespace fpn
{
    static_assert(fixed8_8()  == fixed8_8(fixed8_24()));
    static_assert(fixed8_24() == fixed8_24(fixed8_8()));

    static_assert(fixed8_8( 0) == fixed8_8(fixed8_24(0)));
    static_assert(fixed8_24(0) == fixed8_24(fixed8_8(0)));

    static_assert(fixed8_8( 1) == fixed8_8(fixed8_24(1)));
    static_assert(fixed8_24(1) == fixed8_24(fixed8_8(1)));

    static_assert(fixed8_8( 2) == fixed8_8(fixed8_24(2)));
    static_assert(fixed8_24(2) == fixed8_24(fixed8_8(2)));

    static_assert(fixed8_8( -1) == fixed8_8(fixed8_24(-1)));
    static_assert(fixed8_24(-1) == fixed8_24(fixed8_8(-1)));

    static_assert(fixed8_8( -2) == fixed8_8(fixed8_24(-2)));
    static_assert(fixed8_24(-2) == fixed8_24(fixed8_8(-2)));

#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.125) == fixed8_8(fixed8_24(0.125)));
    static_assert(fixed8_24(0.125) == fixed8_24(fixed8_8(0.125)));

    static_assert(fixed8_8( 1.125) == fixed8_8(fixed8_24(1.125)));
    static_assert(fixed8_24(1.125) == fixed8_24(fixed8_8(1.125)));

    static_assert(fixed8_8( 2.125) == fixed8_8(fixed8_24(2.125)));
    static_assert(fixed8_24(2.125) == fixed8_24(fixed8_8(2.125)));

    static_assert(fixed8_8( -1.125) == fixed8_8(fixed8_24(-1.125)));
    static_assert(fixed8_24(-1.125) == fixed8_24(fixed8_8(-1.125)));

    static_assert(fixed8_8( -2.125) == fixed8_8(fixed8_24(-2.125)));
    static_assert(fixed8_24(-2.125) == fixed8_24(fixed8_8(-2.125)));
#endif
}
// fixed8_8 <-> fixed8_56
namespace fpn
{
    static_assert(fixed8_8()  == fixed8_8(fixed8_56()));
    static_assert(fixed8_56() == fixed8_56(fixed8_8()));

    static_assert(fixed8_8( 0) == fixed8_8(fixed8_56(0)));
    static_assert(fixed8_56(0) == fixed8_56(fixed8_8(0)));

    static_assert(fixed8_8( 1) == fixed8_8(fixed8_56(1)));
    static_assert(fixed8_56(1) == fixed8_56(fixed8_8(1)));

    static_assert(fixed8_8( 2) == fixed8_8(fixed8_56(2)));
    static_assert(fixed8_56(2) == fixed8_56(fixed8_8(2)));

    static_assert(fixed8_8( -1) == fixed8_8(fixed8_56(-1)));
    static_assert(fixed8_56(-1) == fixed8_56(fixed8_8(-1)));

    static_assert(fixed8_8( -2) == fixed8_8(fixed8_56(-2)));
    static_assert(fixed8_56(-2) == fixed8_56(fixed8_8(-2)));

#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.125) == fixed8_8(fixed8_56(0.125)));
    static_assert(fixed8_56(0.125) == fixed8_56(fixed8_8(0.125)));

    static_assert(fixed8_8( 1.125) == fixed8_8(fixed8_56(1.125)));
    static_assert(fixed8_56(1.125) == fixed8_56(fixed8_8(1.125)));

    static_assert(fixed8_8( 2.125) == fixed8_8(fixed8_56(2.125)));
    static_assert(fixed8_56(2.125) == fixed8_56(fixed8_8(2.125)));

    static_assert(fixed8_8( -1.125) == fixed8_8(fixed8_56(-1.125)));
    static_assert(fixed8_56(-1.125) == fixed8_56(fixed8_8(-1.125)));

    static_assert(fixed8_8( -2.125) == fixed8_8(fixed8_56(-2.125)));
    static_assert(fixed8_56(-2.125) == fixed8_56(fixed8_8(-2.125)));
#endif
}
// fixed8_8 <-> fixed24_8
namespace fpn
{
    static_assert(fixed8_8()  == fixed8_8(fixed24_8()));
    static_assert(fixed24_8() == fixed24_8(fixed8_8()));

    static_assert(fixed8_8( 0) == fixed8_8(fixed24_8(0)));
    static_assert(fixed24_8(0) == fixed24_8(fixed8_8(0)));

    static_assert(fixed8_8( 1) == fixed8_8(fixed24_8(1)));
    static_assert(fixed24_8(1) == fixed24_8(fixed8_8(1)));

    static_assert(fixed8_8( 2) == fixed8_8(fixed24_8(2)));
    static_assert(fixed24_8(2) == fixed24_8(fixed8_8(2)));

    static_assert(fixed8_8( -1) == fixed8_8(fixed24_8(-1)));
    static_assert(fixed24_8(-1) == fixed24_8(fixed8_8(-1)));

    static_assert(fixed8_8( -2) == fixed8_8(fixed24_8(-2)));
    static_assert(fixed24_8(-2) == fixed24_8(fixed8_8(-2)));

#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.125) == fixed8_8(fixed24_8(0.125)));
    static_assert(fixed24_8(0.125) == fixed24_8(fixed8_8(0.125)));

    static_assert(fixed8_8( 1.125) == fixed8_8(fixed24_8(1.125)));
    static_assert(fixed24_8(1.125) == fixed24_8(fixed8_8(1.125)));

    static_assert(fixed8_8( 2.125) == fixed8_8(fixed24_8(2.125)));
    static_assert(fixed24_8(2.125) == fixed24_8(fixed8_8(2.125)));

    static_assert(fixed8_8( -1.125) == fixed8_8(fixed24_8(-1.125)));
    static_assert(fixed24_8(-1.125) == fixed24_8(fixed8_8(-1.125)));

    static_assert(fixed8_8( -2.125) == fixed8_8(fixed24_8(-2.125)));
    static_assert(fixed24_8(-2.125) == fixed24_8(fixed8_8(-2.125)));
#endif
}
// fixed8_8 <-> fixed56_8
namespace fpn
{
    static_assert(fixed8_8()  == fixed8_8(fixed56_8()));
    static_assert(fixed56_8() == fixed56_8(fixed8_8()));

    static_assert(fixed8_8( 0) == fixed8_8(fixed56_8(0)));
    static_assert(fixed56_8(0) == fixed56_8(fixed8_8(0)));

    static_assert(fixed8_8( 1) == fixed8_8(fixed56_8(1)));
    static_assert(fixed56_8(1) == fixed56_8(fixed8_8(1)));

    static_assert(fixed8_8( 2) == fixed8_8(fixed56_8(2)));
    static_assert(fixed56_8(2) == fixed56_8(fixed8_8(2)));

    static_assert(fixed8_8( -1) == fixed8_8(fixed56_8(-1)));
    static_assert(fixed56_8(-1) == fixed56_8(fixed8_8(-1)));

    static_assert(fixed8_8( -2) == fixed8_8(fixed56_8(-2)));
    static_assert(fixed56_8(-2) == fixed56_8(fixed8_8(-2)));

#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.125) == fixed8_8(fixed56_8(0.125)));
    static_assert(fixed56_8(0.125) == fixed56_8(fixed8_8(0.125)));

    static_assert(fixed8_8( 1.125) == fixed8_8(fixed56_8(1.125)));
    static_assert(fixed56_8(1.125) == fixed56_8(fixed8_8(1.125)));

    static_assert(fixed8_8( 2.125) == fixed8_8(fixed56_8(2.125)));
    static_assert(fixed56_8(2.125) == fixed56_8(fixed8_8(2.125)));

    static_assert(fixed8_8( -1.125) == fixed8_8(fixed56_8(-1.125)));
    static_assert(fixed56_8(-1.125) == fixed56_8(fixed8_8(-1.125)));

    static_assert(fixed8_8( -2.125) == fixed8_8(fixed56_8(-2.125)));
    static_assert(fixed56_8(-2.125) == fixed56_8(fixed8_8(-2.125)));
#endif
}
