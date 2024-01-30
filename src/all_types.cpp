#include "fixed.hpp"

// Important
namespace fpn
{
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed8_8()  == 0);
    static_assert(fixed8_16() == 0);
    static_assert(fixed8_24() == 0);
    static_assert(fixed8_32() == 0);
    static_assert(fixed8_40() == 0);
    static_assert(fixed8_48() == 0);
    static_assert(fixed8_56() == 0);

    static_assert(fixed16_8()  == 0);
    static_assert(fixed16_16() == 0);
    static_assert(fixed16_24() == 0);
    static_assert(fixed16_32() == 0);
    static_assert(fixed16_40() == 0);
    static_assert(fixed16_48() == 0);

    static_assert(fixed24_8()  == 0);
    static_assert(fixed24_16() == 0);
    static_assert(fixed24_24() == 0);
    static_assert(fixed24_32() == 0);
    static_assert(fixed24_40() == 0);

    static_assert(fixed32_8()  == 0);
    static_assert(fixed32_16() == 0);
    static_assert(fixed32_24() == 0);
    static_assert(fixed32_32() == 0);

    static_assert(fixed48_8()  == 0);
    static_assert(fixed48_16() == 0);

    static_assert(fixed56_8() == 0);
#else
    static_assert(fixed8_8()  == 0);
    static_assert(fixed8_16() == 0);
    static_assert(fixed8_24() == 0);

    static_assert(fixed16_8()  == 0);
    static_assert(fixed16_16() == 0);

    static_assert(fixed24_8() == 0);
#endif
}

// 2
namespace fpn
{
    static_assert(fixed<2, 1>() == 0);
    static_assert(fixed<2, 2>() == 0);
    static_assert(fixed<2, 3>() == 0);
    static_assert(fixed<2, 4>() == 0);
    static_assert(fixed<2, 5>() == 0);
    static_assert(fixed<2, 6>() == 0);
    static_assert(fixed<2, 7>() == 0);
    static_assert(fixed<2, 8>() == 0);
    static_assert(fixed<2, 9>() == 0);
    static_assert(fixed<2, 10>() == 0);
    static_assert(fixed<2, 11>() == 0);
    static_assert(fixed<2, 12>() == 0);
    static_assert(fixed<2, 13>() == 0);
    static_assert(fixed<2, 14>() == 0);
    static_assert(fixed<2, 15>() == 0);
    static_assert(fixed<2, 16>() == 0);
    static_assert(fixed<2, 17>() == 0);
    static_assert(fixed<2, 18>() == 0);
    static_assert(fixed<2, 19>() == 0);
    static_assert(fixed<2, 20>() == 0);
    static_assert(fixed<2, 21>() == 0);
    static_assert(fixed<2, 22>() == 0);
    static_assert(fixed<2, 23>() == 0);
    static_assert(fixed<2, 24>() == 0);
    static_assert(fixed<2, 25>() == 0);
    static_assert(fixed<2, 26>() == 0);
    static_assert(fixed<2, 27>() == 0);
    static_assert(fixed<2, 28>() == 0);
    static_assert(fixed<2, 29>() == 0);
    static_assert(fixed<2, 30>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<2, 31>() == 0);
    static_assert(fixed<2, 32>() == 0);
    static_assert(fixed<2, 33>() == 0);
    static_assert(fixed<2, 34>() == 0);
    static_assert(fixed<2, 35>() == 0);
    static_assert(fixed<2, 36>() == 0);
    static_assert(fixed<2, 37>() == 0);
    static_assert(fixed<2, 38>() == 0);
    static_assert(fixed<2, 39>() == 0);
    static_assert(fixed<2, 40>() == 0);
    static_assert(fixed<2, 41>() == 0);
    static_assert(fixed<2, 42>() == 0);
    static_assert(fixed<2, 43>() == 0);
    static_assert(fixed<2, 44>() == 0);
    static_assert(fixed<2, 45>() == 0);
    static_assert(fixed<2, 46>() == 0);
    static_assert(fixed<2, 47>() == 0);
    static_assert(fixed<2, 48>() == 0);
    static_assert(fixed<2, 49>() == 0);
    static_assert(fixed<2, 50>() == 0);
    static_assert(fixed<2, 51>() == 0);
    static_assert(fixed<2, 52>() == 0);
    static_assert(fixed<2, 53>() == 0);
    static_assert(fixed<2, 54>() == 0);
    static_assert(fixed<2, 55>() == 0);
    static_assert(fixed<2, 56>() == 0);
    static_assert(fixed<2, 57>() == 0);
    static_assert(fixed<2, 58>() == 0);
    static_assert(fixed<2, 59>() == 0);
    static_assert(fixed<2, 60>() == 0);
    static_assert(fixed<2, 61>() == 0);
    static_assert(fixed<2, 62>() == 0);
#endif
}
// 3
namespace fpn
{
    static_assert(fixed<3, 1>() == 0);
    static_assert(fixed<3, 2>() == 0);
    static_assert(fixed<3, 3>() == 0);
    static_assert(fixed<3, 4>() == 0);
    static_assert(fixed<3, 5>() == 0);
    static_assert(fixed<3, 6>() == 0);
    static_assert(fixed<3, 7>() == 0);
    static_assert(fixed<3, 8>() == 0);
    static_assert(fixed<3, 9>() == 0);
    static_assert(fixed<3, 10>() == 0);
    static_assert(fixed<3, 11>() == 0);
    static_assert(fixed<3, 12>() == 0);
    static_assert(fixed<3, 13>() == 0);
    static_assert(fixed<3, 14>() == 0);
    static_assert(fixed<3, 15>() == 0);
    static_assert(fixed<3, 16>() == 0);
    static_assert(fixed<3, 17>() == 0);
    static_assert(fixed<3, 18>() == 0);
    static_assert(fixed<3, 19>() == 0);
    static_assert(fixed<3, 20>() == 0);
    static_assert(fixed<3, 21>() == 0);
    static_assert(fixed<3, 22>() == 0);
    static_assert(fixed<3, 23>() == 0);
    static_assert(fixed<3, 24>() == 0);
    static_assert(fixed<3, 25>() == 0);
    static_assert(fixed<3, 26>() == 0);
    static_assert(fixed<3, 27>() == 0);
    static_assert(fixed<3, 28>() == 0);
    static_assert(fixed<3, 29>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<3, 30>() == 0);
    static_assert(fixed<3, 31>() == 0);
    static_assert(fixed<3, 32>() == 0);
    static_assert(fixed<3, 33>() == 0);
    static_assert(fixed<3, 34>() == 0);
    static_assert(fixed<3, 35>() == 0);
    static_assert(fixed<3, 36>() == 0);
    static_assert(fixed<3, 37>() == 0);
    static_assert(fixed<3, 38>() == 0);
    static_assert(fixed<3, 39>() == 0);
    static_assert(fixed<3, 40>() == 0);
    static_assert(fixed<3, 41>() == 0);
    static_assert(fixed<3, 42>() == 0);
    static_assert(fixed<3, 43>() == 0);
    static_assert(fixed<3, 44>() == 0);
    static_assert(fixed<3, 45>() == 0);
    static_assert(fixed<3, 46>() == 0);
    static_assert(fixed<3, 47>() == 0);
    static_assert(fixed<3, 48>() == 0);
    static_assert(fixed<3, 49>() == 0);
    static_assert(fixed<3, 50>() == 0);
    static_assert(fixed<3, 51>() == 0);
    static_assert(fixed<3, 52>() == 0);
    static_assert(fixed<3, 53>() == 0);
    static_assert(fixed<3, 54>() == 0);
    static_assert(fixed<3, 55>() == 0);
    static_assert(fixed<3, 56>() == 0);
    static_assert(fixed<3, 57>() == 0);
    static_assert(fixed<3, 58>() == 0);
    static_assert(fixed<3, 59>() == 0);
    static_assert(fixed<3, 60>() == 0);
    static_assert(fixed<3, 61>() == 0);
#endif
}
// 4
namespace fpn
{
    static_assert(fixed<4, 1>() == 0);
    static_assert(fixed<4, 2>() == 0);
    static_assert(fixed<4, 3>() == 0);
    static_assert(fixed<4, 4>() == 0);
    static_assert(fixed<4, 5>() == 0);
    static_assert(fixed<4, 6>() == 0);
    static_assert(fixed<4, 7>() == 0);
    static_assert(fixed<4, 8>() == 0);
    static_assert(fixed<4, 9>() == 0);
    static_assert(fixed<4, 10>() == 0);
    static_assert(fixed<4, 11>() == 0);
    static_assert(fixed<4, 12>() == 0);
    static_assert(fixed<4, 13>() == 0);
    static_assert(fixed<4, 14>() == 0);
    static_assert(fixed<4, 15>() == 0);
    static_assert(fixed<4, 16>() == 0);
    static_assert(fixed<4, 17>() == 0);
    static_assert(fixed<4, 18>() == 0);
    static_assert(fixed<4, 19>() == 0);
    static_assert(fixed<4, 20>() == 0);
    static_assert(fixed<4, 21>() == 0);
    static_assert(fixed<4, 22>() == 0);
    static_assert(fixed<4, 23>() == 0);
    static_assert(fixed<4, 24>() == 0);
    static_assert(fixed<4, 25>() == 0);
    static_assert(fixed<4, 26>() == 0);
    static_assert(fixed<4, 27>() == 0);
    static_assert(fixed<4, 28>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<4, 29>() == 0);
    static_assert(fixed<4, 30>() == 0);
    static_assert(fixed<4, 31>() == 0);
    static_assert(fixed<4, 32>() == 0);
    static_assert(fixed<4, 33>() == 0);
    static_assert(fixed<4, 34>() == 0);
    static_assert(fixed<4, 35>() == 0);
    static_assert(fixed<4, 36>() == 0);
    static_assert(fixed<4, 37>() == 0);
    static_assert(fixed<4, 38>() == 0);
    static_assert(fixed<4, 39>() == 0);
    static_assert(fixed<4, 40>() == 0);
    static_assert(fixed<4, 41>() == 0);
    static_assert(fixed<4, 42>() == 0);
    static_assert(fixed<4, 43>() == 0);
    static_assert(fixed<4, 44>() == 0);
    static_assert(fixed<4, 45>() == 0);
    static_assert(fixed<4, 46>() == 0);
    static_assert(fixed<4, 47>() == 0);
    static_assert(fixed<4, 48>() == 0);
    static_assert(fixed<4, 49>() == 0);
    static_assert(fixed<4, 50>() == 0);
    static_assert(fixed<4, 51>() == 0);
    static_assert(fixed<4, 52>() == 0);
    static_assert(fixed<4, 53>() == 0);
    static_assert(fixed<4, 54>() == 0);
    static_assert(fixed<4, 55>() == 0);
    static_assert(fixed<4, 56>() == 0);
    static_assert(fixed<4, 57>() == 0);
    static_assert(fixed<4, 58>() == 0);
    static_assert(fixed<4, 59>() == 0);
    static_assert(fixed<4, 60>() == 0);
#endif
}
// 5
namespace fpn
{
    static_assert(fixed<5, 1>() == 0);
    static_assert(fixed<5, 2>() == 0);
    static_assert(fixed<5, 3>() == 0);
    static_assert(fixed<5, 4>() == 0);
    static_assert(fixed<5, 5>() == 0);
    static_assert(fixed<5, 6>() == 0);
    static_assert(fixed<5, 7>() == 0);
    static_assert(fixed<5, 8>() == 0);
    static_assert(fixed<5, 9>() == 0);
    static_assert(fixed<5, 10>() == 0);
    static_assert(fixed<5, 11>() == 0);
    static_assert(fixed<5, 12>() == 0);
    static_assert(fixed<5, 13>() == 0);
    static_assert(fixed<5, 14>() == 0);
    static_assert(fixed<5, 15>() == 0);
    static_assert(fixed<5, 16>() == 0);
    static_assert(fixed<5, 17>() == 0);
    static_assert(fixed<5, 18>() == 0);
    static_assert(fixed<5, 19>() == 0);
    static_assert(fixed<5, 20>() == 0);
    static_assert(fixed<5, 21>() == 0);
    static_assert(fixed<5, 22>() == 0);
    static_assert(fixed<5, 23>() == 0);
    static_assert(fixed<5, 24>() == 0);
    static_assert(fixed<5, 25>() == 0);
    static_assert(fixed<5, 26>() == 0);
    static_assert(fixed<5, 27>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<5, 28>() == 0);
    static_assert(fixed<5, 29>() == 0);
    static_assert(fixed<5, 30>() == 0);
    static_assert(fixed<5, 31>() == 0);
    static_assert(fixed<5, 32>() == 0);
    static_assert(fixed<5, 33>() == 0);
    static_assert(fixed<5, 34>() == 0);
    static_assert(fixed<5, 35>() == 0);
    static_assert(fixed<5, 36>() == 0);
    static_assert(fixed<5, 37>() == 0);
    static_assert(fixed<5, 38>() == 0);
    static_assert(fixed<5, 39>() == 0);
    static_assert(fixed<5, 40>() == 0);
    static_assert(fixed<5, 41>() == 0);
    static_assert(fixed<5, 42>() == 0);
    static_assert(fixed<5, 43>() == 0);
    static_assert(fixed<5, 44>() == 0);
    static_assert(fixed<5, 45>() == 0);
    static_assert(fixed<5, 46>() == 0);
    static_assert(fixed<5, 47>() == 0);
    static_assert(fixed<5, 48>() == 0);
    static_assert(fixed<5, 49>() == 0);
    static_assert(fixed<5, 50>() == 0);
    static_assert(fixed<5, 51>() == 0);
    static_assert(fixed<5, 52>() == 0);
    static_assert(fixed<5, 53>() == 0);
    static_assert(fixed<5, 54>() == 0);
    static_assert(fixed<5, 55>() == 0);
    static_assert(fixed<5, 56>() == 0);
    static_assert(fixed<5, 57>() == 0);
    static_assert(fixed<5, 58>() == 0);
    static_assert(fixed<5, 59>() == 0);
#endif
}
// 6
namespace fpn
{
    static_assert(fixed<6, 1>() == 0);
    static_assert(fixed<6, 2>() == 0);
    static_assert(fixed<6, 3>() == 0);
    static_assert(fixed<6, 4>() == 0);
    static_assert(fixed<6, 5>() == 0);
    static_assert(fixed<6, 6>() == 0);
    static_assert(fixed<6, 7>() == 0);
    static_assert(fixed<6, 8>() == 0);
    static_assert(fixed<6, 9>() == 0);
    static_assert(fixed<6, 10>() == 0);
    static_assert(fixed<6, 11>() == 0);
    static_assert(fixed<6, 12>() == 0);
    static_assert(fixed<6, 13>() == 0);
    static_assert(fixed<6, 14>() == 0);
    static_assert(fixed<6, 15>() == 0);
    static_assert(fixed<6, 16>() == 0);
    static_assert(fixed<6, 17>() == 0);
    static_assert(fixed<6, 18>() == 0);
    static_assert(fixed<6, 19>() == 0);
    static_assert(fixed<6, 20>() == 0);
    static_assert(fixed<6, 21>() == 0);
    static_assert(fixed<6, 22>() == 0);
    static_assert(fixed<6, 23>() == 0);
    static_assert(fixed<6, 24>() == 0);
    static_assert(fixed<6, 25>() == 0);
    static_assert(fixed<6, 26>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<6, 27>() == 0);
    static_assert(fixed<6, 28>() == 0);
    static_assert(fixed<6, 29>() == 0);
    static_assert(fixed<6, 30>() == 0);
    static_assert(fixed<6, 31>() == 0);
    static_assert(fixed<6, 32>() == 0);
    static_assert(fixed<6, 33>() == 0);
    static_assert(fixed<6, 34>() == 0);
    static_assert(fixed<6, 35>() == 0);
    static_assert(fixed<6, 36>() == 0);
    static_assert(fixed<6, 37>() == 0);
    static_assert(fixed<6, 38>() == 0);
    static_assert(fixed<6, 39>() == 0);
    static_assert(fixed<6, 40>() == 0);
    static_assert(fixed<6, 41>() == 0);
    static_assert(fixed<6, 42>() == 0);
    static_assert(fixed<6, 43>() == 0);
    static_assert(fixed<6, 44>() == 0);
    static_assert(fixed<6, 45>() == 0);
    static_assert(fixed<6, 46>() == 0);
    static_assert(fixed<6, 47>() == 0);
    static_assert(fixed<6, 48>() == 0);
    static_assert(fixed<6, 49>() == 0);
    static_assert(fixed<6, 50>() == 0);
    static_assert(fixed<6, 51>() == 0);
    static_assert(fixed<6, 52>() == 0);
    static_assert(fixed<6, 53>() == 0);
    static_assert(fixed<6, 54>() == 0);
    static_assert(fixed<6, 55>() == 0);
    static_assert(fixed<6, 56>() == 0);
    static_assert(fixed<6, 57>() == 0);
    static_assert(fixed<6, 58>() == 0);
#endif
}
// 7
namespace fpn
{
    static_assert(fixed<7, 1>() == 0);
    static_assert(fixed<7, 2>() == 0);
    static_assert(fixed<7, 3>() == 0);
    static_assert(fixed<7, 4>() == 0);
    static_assert(fixed<7, 5>() == 0);
    static_assert(fixed<7, 6>() == 0);
    static_assert(fixed<7, 7>() == 0);
    static_assert(fixed<7, 8>() == 0);
    static_assert(fixed<7, 9>() == 0);
    static_assert(fixed<7, 10>() == 0);
    static_assert(fixed<7, 11>() == 0);
    static_assert(fixed<7, 12>() == 0);
    static_assert(fixed<7, 13>() == 0);
    static_assert(fixed<7, 14>() == 0);
    static_assert(fixed<7, 15>() == 0);
    static_assert(fixed<7, 16>() == 0);
    static_assert(fixed<7, 17>() == 0);
    static_assert(fixed<7, 18>() == 0);
    static_assert(fixed<7, 19>() == 0);
    static_assert(fixed<7, 20>() == 0);
    static_assert(fixed<7, 21>() == 0);
    static_assert(fixed<7, 22>() == 0);
    static_assert(fixed<7, 23>() == 0);
    static_assert(fixed<7, 24>() == 0);
    static_assert(fixed<7, 25>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<7, 26>() == 0);
    static_assert(fixed<7, 27>() == 0);
    static_assert(fixed<7, 28>() == 0);
    static_assert(fixed<7, 29>() == 0);
    static_assert(fixed<7, 30>() == 0);
    static_assert(fixed<7, 31>() == 0);
    static_assert(fixed<7, 32>() == 0);
    static_assert(fixed<7, 33>() == 0);
    static_assert(fixed<7, 34>() == 0);
    static_assert(fixed<7, 35>() == 0);
    static_assert(fixed<7, 36>() == 0);
    static_assert(fixed<7, 37>() == 0);
    static_assert(fixed<7, 38>() == 0);
    static_assert(fixed<7, 39>() == 0);
    static_assert(fixed<7, 40>() == 0);
    static_assert(fixed<7, 41>() == 0);
    static_assert(fixed<7, 42>() == 0);
    static_assert(fixed<7, 43>() == 0);
    static_assert(fixed<7, 44>() == 0);
    static_assert(fixed<7, 45>() == 0);
    static_assert(fixed<7, 46>() == 0);
    static_assert(fixed<7, 47>() == 0);
    static_assert(fixed<7, 48>() == 0);
    static_assert(fixed<7, 49>() == 0);
    static_assert(fixed<7, 50>() == 0);
    static_assert(fixed<7, 51>() == 0);
    static_assert(fixed<7, 52>() == 0);
    static_assert(fixed<7, 53>() == 0);
    static_assert(fixed<7, 54>() == 0);
    static_assert(fixed<7, 55>() == 0);
    static_assert(fixed<7, 56>() == 0);
    static_assert(fixed<7, 57>() == 0);
#endif
}
// 8
namespace fpn
{
    static_assert(fixed<8, 1>() == 0);
    static_assert(fixed<8, 2>() == 0);
    static_assert(fixed<8, 3>() == 0);
    static_assert(fixed<8, 4>() == 0);
    static_assert(fixed<8, 5>() == 0);
    static_assert(fixed<8, 6>() == 0);
    static_assert(fixed<8, 7>() == 0);
    static_assert(fixed<8, 8>() == 0);
    static_assert(fixed<8, 9>() == 0);
    static_assert(fixed<8, 10>() == 0);
    static_assert(fixed<8, 11>() == 0);
    static_assert(fixed<8, 12>() == 0);
    static_assert(fixed<8, 13>() == 0);
    static_assert(fixed<8, 14>() == 0);
    static_assert(fixed<8, 15>() == 0);
    static_assert(fixed<8, 16>() == 0);
    static_assert(fixed<8, 17>() == 0);
    static_assert(fixed<8, 18>() == 0);
    static_assert(fixed<8, 19>() == 0);
    static_assert(fixed<8, 20>() == 0);
    static_assert(fixed<8, 21>() == 0);
    static_assert(fixed<8, 22>() == 0);
    static_assert(fixed<8, 23>() == 0);
    static_assert(fixed<8, 24>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<8, 25>() == 0);
    static_assert(fixed<8, 26>() == 0);
    static_assert(fixed<8, 27>() == 0);
    static_assert(fixed<8, 28>() == 0);
    static_assert(fixed<8, 29>() == 0);
    static_assert(fixed<8, 30>() == 0);
    static_assert(fixed<8, 31>() == 0);
    static_assert(fixed<8, 32>() == 0);
    static_assert(fixed<8, 33>() == 0);
    static_assert(fixed<8, 34>() == 0);
    static_assert(fixed<8, 35>() == 0);
    static_assert(fixed<8, 36>() == 0);
    static_assert(fixed<8, 37>() == 0);
    static_assert(fixed<8, 38>() == 0);
    static_assert(fixed<8, 39>() == 0);
    static_assert(fixed<8, 40>() == 0);
    static_assert(fixed<8, 41>() == 0);
    static_assert(fixed<8, 42>() == 0);
    static_assert(fixed<8, 43>() == 0);
    static_assert(fixed<8, 44>() == 0);
    static_assert(fixed<8, 45>() == 0);
    static_assert(fixed<8, 46>() == 0);
    static_assert(fixed<8, 47>() == 0);
    static_assert(fixed<8, 48>() == 0);
    static_assert(fixed<8, 49>() == 0);
    static_assert(fixed<8, 50>() == 0);
    static_assert(fixed<8, 51>() == 0);
    static_assert(fixed<8, 52>() == 0);
    static_assert(fixed<8, 53>() == 0);
    static_assert(fixed<8, 54>() == 0);
    static_assert(fixed<8, 55>() == 0);
    static_assert(fixed<8, 56>() == 0);
#endif
}
// 9
namespace fpn
{
    static_assert(fixed<9, 1>() == 0);
    static_assert(fixed<9, 2>() == 0);
    static_assert(fixed<9, 3>() == 0);
    static_assert(fixed<9, 4>() == 0);
    static_assert(fixed<9, 5>() == 0);
    static_assert(fixed<9, 6>() == 0);
    static_assert(fixed<9, 7>() == 0);
    static_assert(fixed<9, 8>() == 0);
    static_assert(fixed<9, 9>() == 0);
    static_assert(fixed<9, 10>() == 0);
    static_assert(fixed<9, 11>() == 0);
    static_assert(fixed<9, 12>() == 0);
    static_assert(fixed<9, 13>() == 0);
    static_assert(fixed<9, 14>() == 0);
    static_assert(fixed<9, 15>() == 0);
    static_assert(fixed<9, 16>() == 0);
    static_assert(fixed<9, 17>() == 0);
    static_assert(fixed<9, 18>() == 0);
    static_assert(fixed<9, 19>() == 0);
    static_assert(fixed<9, 20>() == 0);
    static_assert(fixed<9, 21>() == 0);
    static_assert(fixed<9, 22>() == 0);
    static_assert(fixed<9, 23>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<9, 24>() == 0);
    static_assert(fixed<9, 25>() == 0);
    static_assert(fixed<9, 26>() == 0);
    static_assert(fixed<9, 27>() == 0);
    static_assert(fixed<9, 28>() == 0);
    static_assert(fixed<9, 29>() == 0);
    static_assert(fixed<9, 30>() == 0);
    static_assert(fixed<9, 31>() == 0);
    static_assert(fixed<9, 32>() == 0);
    static_assert(fixed<9, 33>() == 0);
    static_assert(fixed<9, 34>() == 0);
    static_assert(fixed<9, 35>() == 0);
    static_assert(fixed<9, 36>() == 0);
    static_assert(fixed<9, 37>() == 0);
    static_assert(fixed<9, 38>() == 0);
    static_assert(fixed<9, 39>() == 0);
    static_assert(fixed<9, 40>() == 0);
    static_assert(fixed<9, 41>() == 0);
    static_assert(fixed<9, 42>() == 0);
    static_assert(fixed<9, 43>() == 0);
    static_assert(fixed<9, 44>() == 0);
    static_assert(fixed<9, 45>() == 0);
    static_assert(fixed<9, 46>() == 0);
    static_assert(fixed<9, 47>() == 0);
    static_assert(fixed<9, 48>() == 0);
    static_assert(fixed<9, 49>() == 0);
    static_assert(fixed<9, 50>() == 0);
    static_assert(fixed<9, 51>() == 0);
    static_assert(fixed<9, 52>() == 0);
    static_assert(fixed<9, 53>() == 0);
    static_assert(fixed<9, 54>() == 0);
    static_assert(fixed<9, 55>() == 0);
#endif
}
// 10
namespace fpn
{
    static_assert(fixed<10, 1>() == 0);
    static_assert(fixed<10, 2>() == 0);
    static_assert(fixed<10, 3>() == 0);
    static_assert(fixed<10, 4>() == 0);
    static_assert(fixed<10, 5>() == 0);
    static_assert(fixed<10, 6>() == 0);
    static_assert(fixed<10, 7>() == 0);
    static_assert(fixed<10, 8>() == 0);
    static_assert(fixed<10, 9>() == 0);
    static_assert(fixed<10, 10>() == 0);
    static_assert(fixed<10, 11>() == 0);
    static_assert(fixed<10, 12>() == 0);
    static_assert(fixed<10, 13>() == 0);
    static_assert(fixed<10, 14>() == 0);
    static_assert(fixed<10, 15>() == 0);
    static_assert(fixed<10, 16>() == 0);
    static_assert(fixed<10, 17>() == 0);
    static_assert(fixed<10, 18>() == 0);
    static_assert(fixed<10, 19>() == 0);
    static_assert(fixed<10, 20>() == 0);
    static_assert(fixed<10, 21>() == 0);
    static_assert(fixed<10, 22>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<10, 23>() == 0);
    static_assert(fixed<10, 24>() == 0);
    static_assert(fixed<10, 25>() == 0);
    static_assert(fixed<10, 26>() == 0);
    static_assert(fixed<10, 27>() == 0);
    static_assert(fixed<10, 28>() == 0);
    static_assert(fixed<10, 29>() == 0);
    static_assert(fixed<10, 30>() == 0);
    static_assert(fixed<10, 31>() == 0);
    static_assert(fixed<10, 32>() == 0);
    static_assert(fixed<10, 33>() == 0);
    static_assert(fixed<10, 34>() == 0);
    static_assert(fixed<10, 35>() == 0);
    static_assert(fixed<10, 36>() == 0);
    static_assert(fixed<10, 37>() == 0);
    static_assert(fixed<10, 38>() == 0);
    static_assert(fixed<10, 39>() == 0);
    static_assert(fixed<10, 40>() == 0);
    static_assert(fixed<10, 41>() == 0);
    static_assert(fixed<10, 42>() == 0);
    static_assert(fixed<10, 43>() == 0);
    static_assert(fixed<10, 44>() == 0);
    static_assert(fixed<10, 45>() == 0);
    static_assert(fixed<10, 46>() == 0);
    static_assert(fixed<10, 47>() == 0);
    static_assert(fixed<10, 48>() == 0);
    static_assert(fixed<10, 49>() == 0);
    static_assert(fixed<10, 50>() == 0);
    static_assert(fixed<10, 51>() == 0);
    static_assert(fixed<10, 52>() == 0);
    static_assert(fixed<10, 53>() == 0);
    static_assert(fixed<10, 54>() == 0);
#endif
}
// 11
namespace fpn
{
    static_assert(fixed<11, 1>() == 0);
    static_assert(fixed<11, 2>() == 0);
    static_assert(fixed<11, 3>() == 0);
    static_assert(fixed<11, 4>() == 0);
    static_assert(fixed<11, 5>() == 0);
    static_assert(fixed<11, 6>() == 0);
    static_assert(fixed<11, 7>() == 0);
    static_assert(fixed<11, 8>() == 0);
    static_assert(fixed<11, 9>() == 0);
    static_assert(fixed<11, 10>() == 0);
    static_assert(fixed<11, 11>() == 0);
    static_assert(fixed<11, 12>() == 0);
    static_assert(fixed<11, 13>() == 0);
    static_assert(fixed<11, 14>() == 0);
    static_assert(fixed<11, 15>() == 0);
    static_assert(fixed<11, 16>() == 0);
    static_assert(fixed<11, 17>() == 0);
    static_assert(fixed<11, 18>() == 0);
    static_assert(fixed<11, 19>() == 0);
    static_assert(fixed<11, 20>() == 0);
    static_assert(fixed<11, 21>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<11, 22>() == 0);
    static_assert(fixed<11, 23>() == 0);
    static_assert(fixed<11, 24>() == 0);
    static_assert(fixed<11, 25>() == 0);
    static_assert(fixed<11, 26>() == 0);
    static_assert(fixed<11, 27>() == 0);
    static_assert(fixed<11, 28>() == 0);
    static_assert(fixed<11, 29>() == 0);
    static_assert(fixed<11, 30>() == 0);
    static_assert(fixed<11, 31>() == 0);
    static_assert(fixed<11, 32>() == 0);
    static_assert(fixed<11, 33>() == 0);
    static_assert(fixed<11, 34>() == 0);
    static_assert(fixed<11, 35>() == 0);
    static_assert(fixed<11, 36>() == 0);
    static_assert(fixed<11, 37>() == 0);
    static_assert(fixed<11, 38>() == 0);
    static_assert(fixed<11, 39>() == 0);
    static_assert(fixed<11, 40>() == 0);
    static_assert(fixed<11, 41>() == 0);
    static_assert(fixed<11, 42>() == 0);
    static_assert(fixed<11, 43>() == 0);
    static_assert(fixed<11, 44>() == 0);
    static_assert(fixed<11, 45>() == 0);
    static_assert(fixed<11, 46>() == 0);
    static_assert(fixed<11, 47>() == 0);
    static_assert(fixed<11, 48>() == 0);
    static_assert(fixed<11, 49>() == 0);
    static_assert(fixed<11, 50>() == 0);
    static_assert(fixed<11, 51>() == 0);
    static_assert(fixed<11, 52>() == 0);
    static_assert(fixed<11, 53>() == 0);
#endif
}
// 12
namespace fpn
{
    static_assert(fixed<12, 1>() == 0);
    static_assert(fixed<12, 2>() == 0);
    static_assert(fixed<12, 3>() == 0);
    static_assert(fixed<12, 4>() == 0);
    static_assert(fixed<12, 5>() == 0);
    static_assert(fixed<12, 6>() == 0);
    static_assert(fixed<12, 7>() == 0);
    static_assert(fixed<12, 8>() == 0);
    static_assert(fixed<12, 9>() == 0);
    static_assert(fixed<12, 10>() == 0);
    static_assert(fixed<12, 11>() == 0);
    static_assert(fixed<12, 12>() == 0);
    static_assert(fixed<12, 13>() == 0);
    static_assert(fixed<12, 14>() == 0);
    static_assert(fixed<12, 15>() == 0);
    static_assert(fixed<12, 16>() == 0);
    static_assert(fixed<12, 17>() == 0);
    static_assert(fixed<12, 18>() == 0);
    static_assert(fixed<12, 19>() == 0);
    static_assert(fixed<12, 20>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<12, 21>() == 0);
    static_assert(fixed<12, 22>() == 0);
    static_assert(fixed<12, 23>() == 0);
    static_assert(fixed<12, 24>() == 0);
    static_assert(fixed<12, 25>() == 0);
    static_assert(fixed<12, 26>() == 0);
    static_assert(fixed<12, 27>() == 0);
    static_assert(fixed<12, 28>() == 0);
    static_assert(fixed<12, 29>() == 0);
    static_assert(fixed<12, 30>() == 0);
    static_assert(fixed<12, 31>() == 0);
    static_assert(fixed<12, 32>() == 0);
    static_assert(fixed<12, 33>() == 0);
    static_assert(fixed<12, 34>() == 0);
    static_assert(fixed<12, 35>() == 0);
    static_assert(fixed<12, 36>() == 0);
    static_assert(fixed<12, 37>() == 0);
    static_assert(fixed<12, 38>() == 0);
    static_assert(fixed<12, 39>() == 0);
    static_assert(fixed<12, 40>() == 0);
    static_assert(fixed<12, 41>() == 0);
    static_assert(fixed<12, 42>() == 0);
    static_assert(fixed<12, 43>() == 0);
    static_assert(fixed<12, 44>() == 0);
    static_assert(fixed<12, 45>() == 0);
    static_assert(fixed<12, 46>() == 0);
    static_assert(fixed<12, 47>() == 0);
    static_assert(fixed<12, 48>() == 0);
    static_assert(fixed<12, 49>() == 0);
    static_assert(fixed<12, 50>() == 0);
    static_assert(fixed<12, 51>() == 0);
    static_assert(fixed<12, 52>() == 0);
#endif
}
// 13
namespace fpn
{
    static_assert(fixed<13, 1>() == 0);
    static_assert(fixed<13, 2>() == 0);
    static_assert(fixed<13, 3>() == 0);
    static_assert(fixed<13, 4>() == 0);
    static_assert(fixed<13, 5>() == 0);
    static_assert(fixed<13, 6>() == 0);
    static_assert(fixed<13, 7>() == 0);
    static_assert(fixed<13, 8>() == 0);
    static_assert(fixed<13, 9>() == 0);
    static_assert(fixed<13, 10>() == 0);
    static_assert(fixed<13, 11>() == 0);
    static_assert(fixed<13, 12>() == 0);
    static_assert(fixed<13, 13>() == 0);
    static_assert(fixed<13, 14>() == 0);
    static_assert(fixed<13, 15>() == 0);
    static_assert(fixed<13, 16>() == 0);
    static_assert(fixed<13, 17>() == 0);
    static_assert(fixed<13, 18>() == 0);
    static_assert(fixed<13, 19>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<13, 20>() == 0);
    static_assert(fixed<13, 21>() == 0);
    static_assert(fixed<13, 22>() == 0);
    static_assert(fixed<13, 23>() == 0);
    static_assert(fixed<13, 24>() == 0);
    static_assert(fixed<13, 25>() == 0);
    static_assert(fixed<13, 26>() == 0);
    static_assert(fixed<13, 27>() == 0);
    static_assert(fixed<13, 28>() == 0);
    static_assert(fixed<13, 29>() == 0);
    static_assert(fixed<13, 30>() == 0);
    static_assert(fixed<13, 31>() == 0);
    static_assert(fixed<13, 32>() == 0);
    static_assert(fixed<13, 33>() == 0);
    static_assert(fixed<13, 34>() == 0);
    static_assert(fixed<13, 35>() == 0);
    static_assert(fixed<13, 36>() == 0);
    static_assert(fixed<13, 37>() == 0);
    static_assert(fixed<13, 38>() == 0);
    static_assert(fixed<13, 39>() == 0);
    static_assert(fixed<13, 40>() == 0);
    static_assert(fixed<13, 41>() == 0);
    static_assert(fixed<13, 42>() == 0);
    static_assert(fixed<13, 43>() == 0);
    static_assert(fixed<13, 44>() == 0);
    static_assert(fixed<13, 45>() == 0);
    static_assert(fixed<13, 46>() == 0);
    static_assert(fixed<13, 47>() == 0);
    static_assert(fixed<13, 48>() == 0);
    static_assert(fixed<13, 49>() == 0);
    static_assert(fixed<13, 50>() == 0);
    static_assert(fixed<13, 51>() == 0);
#endif
}
// 14
namespace fpn
{
    static_assert(fixed<14, 1>() == 0);
    static_assert(fixed<14, 2>() == 0);
    static_assert(fixed<14, 3>() == 0);
    static_assert(fixed<14, 4>() == 0);
    static_assert(fixed<14, 5>() == 0);
    static_assert(fixed<14, 6>() == 0);
    static_assert(fixed<14, 7>() == 0);
    static_assert(fixed<14, 8>() == 0);
    static_assert(fixed<14, 9>() == 0);
    static_assert(fixed<14, 10>() == 0);
    static_assert(fixed<14, 11>() == 0);
    static_assert(fixed<14, 12>() == 0);
    static_assert(fixed<14, 13>() == 0);
    static_assert(fixed<14, 14>() == 0);
    static_assert(fixed<14, 15>() == 0);
    static_assert(fixed<14, 16>() == 0);
    static_assert(fixed<14, 17>() == 0);
    static_assert(fixed<14, 18>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<14, 19>() == 0);
    static_assert(fixed<14, 20>() == 0);
    static_assert(fixed<14, 21>() == 0);
    static_assert(fixed<14, 22>() == 0);
    static_assert(fixed<14, 23>() == 0);
    static_assert(fixed<14, 24>() == 0);
    static_assert(fixed<14, 25>() == 0);
    static_assert(fixed<14, 26>() == 0);
    static_assert(fixed<14, 27>() == 0);
    static_assert(fixed<14, 28>() == 0);
    static_assert(fixed<14, 29>() == 0);
    static_assert(fixed<14, 30>() == 0);
    static_assert(fixed<14, 31>() == 0);
    static_assert(fixed<14, 32>() == 0);
    static_assert(fixed<14, 33>() == 0);
    static_assert(fixed<14, 34>() == 0);
    static_assert(fixed<14, 35>() == 0);
    static_assert(fixed<14, 36>() == 0);
    static_assert(fixed<14, 37>() == 0);
    static_assert(fixed<14, 38>() == 0);
    static_assert(fixed<14, 39>() == 0);
    static_assert(fixed<14, 40>() == 0);
    static_assert(fixed<14, 41>() == 0);
    static_assert(fixed<14, 42>() == 0);
    static_assert(fixed<14, 43>() == 0);
    static_assert(fixed<14, 44>() == 0);
    static_assert(fixed<14, 45>() == 0);
    static_assert(fixed<14, 46>() == 0);
    static_assert(fixed<14, 47>() == 0);
    static_assert(fixed<14, 48>() == 0);
    static_assert(fixed<14, 49>() == 0);
    static_assert(fixed<14, 50>() == 0);
#endif
}
// 15
namespace fpn
{
    static_assert(fixed<15, 1>() == 0);
    static_assert(fixed<15, 2>() == 0);
    static_assert(fixed<15, 3>() == 0);
    static_assert(fixed<15, 4>() == 0);
    static_assert(fixed<15, 5>() == 0);
    static_assert(fixed<15, 6>() == 0);
    static_assert(fixed<15, 7>() == 0);
    static_assert(fixed<15, 8>() == 0);
    static_assert(fixed<15, 9>() == 0);
    static_assert(fixed<15, 10>() == 0);
    static_assert(fixed<15, 11>() == 0);
    static_assert(fixed<15, 12>() == 0);
    static_assert(fixed<15, 13>() == 0);
    static_assert(fixed<15, 14>() == 0);
    static_assert(fixed<15, 15>() == 0);
    static_assert(fixed<15, 16>() == 0);
    static_assert(fixed<15, 17>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<15, 18>() == 0);
    static_assert(fixed<15, 19>() == 0);
    static_assert(fixed<15, 20>() == 0);
    static_assert(fixed<15, 21>() == 0);
    static_assert(fixed<15, 22>() == 0);
    static_assert(fixed<15, 23>() == 0);
    static_assert(fixed<15, 24>() == 0);
    static_assert(fixed<15, 25>() == 0);
    static_assert(fixed<15, 26>() == 0);
    static_assert(fixed<15, 27>() == 0);
    static_assert(fixed<15, 28>() == 0);
    static_assert(fixed<15, 29>() == 0);
    static_assert(fixed<15, 30>() == 0);
    static_assert(fixed<15, 31>() == 0);
    static_assert(fixed<15, 32>() == 0);
    static_assert(fixed<15, 33>() == 0);
    static_assert(fixed<15, 34>() == 0);
    static_assert(fixed<15, 35>() == 0);
    static_assert(fixed<15, 36>() == 0);
    static_assert(fixed<15, 37>() == 0);
    static_assert(fixed<15, 38>() == 0);
    static_assert(fixed<15, 39>() == 0);
    static_assert(fixed<15, 40>() == 0);
    static_assert(fixed<15, 41>() == 0);
    static_assert(fixed<15, 42>() == 0);
    static_assert(fixed<15, 43>() == 0);
    static_assert(fixed<15, 44>() == 0);
    static_assert(fixed<15, 45>() == 0);
    static_assert(fixed<15, 46>() == 0);
    static_assert(fixed<15, 47>() == 0);
    static_assert(fixed<15, 48>() == 0);
    static_assert(fixed<15, 49>() == 0);
#endif
}
// 16
namespace fpn
{
    static_assert(fixed<16, 1>() == 0);
    static_assert(fixed<16, 2>() == 0);
    static_assert(fixed<16, 3>() == 0);
    static_assert(fixed<16, 4>() == 0);
    static_assert(fixed<16, 5>() == 0);
    static_assert(fixed<16, 6>() == 0);
    static_assert(fixed<16, 7>() == 0);
    static_assert(fixed<16, 8>() == 0);
    static_assert(fixed<16, 9>() == 0);
    static_assert(fixed<16, 10>() == 0);
    static_assert(fixed<16, 11>() == 0);
    static_assert(fixed<16, 12>() == 0);
    static_assert(fixed<16, 13>() == 0);
    static_assert(fixed<16, 14>() == 0);
    static_assert(fixed<16, 15>() == 0);
    static_assert(fixed<16, 16>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<16, 17>() == 0);
    static_assert(fixed<16, 18>() == 0);
    static_assert(fixed<16, 19>() == 0);
    static_assert(fixed<16, 20>() == 0);
    static_assert(fixed<16, 21>() == 0);
    static_assert(fixed<16, 22>() == 0);
    static_assert(fixed<16, 23>() == 0);
    static_assert(fixed<16, 24>() == 0);
    static_assert(fixed<16, 25>() == 0);
    static_assert(fixed<16, 26>() == 0);
    static_assert(fixed<16, 27>() == 0);
    static_assert(fixed<16, 28>() == 0);
    static_assert(fixed<16, 29>() == 0);
    static_assert(fixed<16, 30>() == 0);
    static_assert(fixed<16, 31>() == 0);
    static_assert(fixed<16, 32>() == 0);
    static_assert(fixed<16, 33>() == 0);
    static_assert(fixed<16, 34>() == 0);
    static_assert(fixed<16, 35>() == 0);
    static_assert(fixed<16, 36>() == 0);
    static_assert(fixed<16, 37>() == 0);
    static_assert(fixed<16, 38>() == 0);
    static_assert(fixed<16, 39>() == 0);
    static_assert(fixed<16, 40>() == 0);
    static_assert(fixed<16, 41>() == 0);
    static_assert(fixed<16, 42>() == 0);
    static_assert(fixed<16, 43>() == 0);
    static_assert(fixed<16, 44>() == 0);
    static_assert(fixed<16, 45>() == 0);
    static_assert(fixed<16, 46>() == 0);
    static_assert(fixed<16, 47>() == 0);
    static_assert(fixed<16, 48>() == 0);
#endif
}
// 17
namespace fpn
{
    static_assert(fixed<17, 1>() == 0);
    static_assert(fixed<17, 2>() == 0);
    static_assert(fixed<17, 3>() == 0);
    static_assert(fixed<17, 4>() == 0);
    static_assert(fixed<17, 5>() == 0);
    static_assert(fixed<17, 6>() == 0);
    static_assert(fixed<17, 7>() == 0);
    static_assert(fixed<17, 8>() == 0);
    static_assert(fixed<17, 9>() == 0);
    static_assert(fixed<17, 10>() == 0);
    static_assert(fixed<17, 11>() == 0);
    static_assert(fixed<17, 12>() == 0);
    static_assert(fixed<17, 13>() == 0);
    static_assert(fixed<17, 14>() == 0);
    static_assert(fixed<17, 15>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<17, 16>() == 0);
    static_assert(fixed<17, 17>() == 0);
    static_assert(fixed<17, 18>() == 0);
    static_assert(fixed<17, 19>() == 0);
    static_assert(fixed<17, 20>() == 0);
    static_assert(fixed<17, 21>() == 0);
    static_assert(fixed<17, 22>() == 0);
    static_assert(fixed<17, 23>() == 0);
    static_assert(fixed<17, 24>() == 0);
    static_assert(fixed<17, 25>() == 0);
    static_assert(fixed<17, 26>() == 0);
    static_assert(fixed<17, 27>() == 0);
    static_assert(fixed<17, 28>() == 0);
    static_assert(fixed<17, 29>() == 0);
    static_assert(fixed<17, 30>() == 0);
    static_assert(fixed<17, 31>() == 0);
    static_assert(fixed<17, 32>() == 0);
    static_assert(fixed<17, 33>() == 0);
    static_assert(fixed<17, 34>() == 0);
    static_assert(fixed<17, 35>() == 0);
    static_assert(fixed<17, 36>() == 0);
    static_assert(fixed<17, 37>() == 0);
    static_assert(fixed<17, 38>() == 0);
    static_assert(fixed<17, 39>() == 0);
    static_assert(fixed<17, 40>() == 0);
    static_assert(fixed<17, 41>() == 0);
    static_assert(fixed<17, 42>() == 0);
    static_assert(fixed<17, 43>() == 0);
    static_assert(fixed<17, 44>() == 0);
    static_assert(fixed<17, 45>() == 0);
    static_assert(fixed<17, 46>() == 0);
    static_assert(fixed<17, 47>() == 0);
#endif
}
// 18
namespace fpn
{
    static_assert(fixed<18, 1>() == 0);
    static_assert(fixed<18, 2>() == 0);
    static_assert(fixed<18, 3>() == 0);
    static_assert(fixed<18, 4>() == 0);
    static_assert(fixed<18, 5>() == 0);
    static_assert(fixed<18, 6>() == 0);
    static_assert(fixed<18, 7>() == 0);
    static_assert(fixed<18, 8>() == 0);
    static_assert(fixed<18, 9>() == 0);
    static_assert(fixed<18, 10>() == 0);
    static_assert(fixed<18, 11>() == 0);
    static_assert(fixed<18, 12>() == 0);
    static_assert(fixed<18, 13>() == 0);
    static_assert(fixed<18, 14>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<18, 15>() == 0);
    static_assert(fixed<18, 16>() == 0);
    static_assert(fixed<18, 17>() == 0);
    static_assert(fixed<18, 18>() == 0);
    static_assert(fixed<18, 19>() == 0);
    static_assert(fixed<18, 20>() == 0);
    static_assert(fixed<18, 21>() == 0);
    static_assert(fixed<18, 22>() == 0);
    static_assert(fixed<18, 23>() == 0);
    static_assert(fixed<18, 24>() == 0);
    static_assert(fixed<18, 25>() == 0);
    static_assert(fixed<18, 26>() == 0);
    static_assert(fixed<18, 27>() == 0);
    static_assert(fixed<18, 28>() == 0);
    static_assert(fixed<18, 29>() == 0);
    static_assert(fixed<18, 30>() == 0);
    static_assert(fixed<18, 31>() == 0);
    static_assert(fixed<18, 32>() == 0);
    static_assert(fixed<18, 33>() == 0);
    static_assert(fixed<18, 34>() == 0);
    static_assert(fixed<18, 35>() == 0);
    static_assert(fixed<18, 36>() == 0);
    static_assert(fixed<18, 37>() == 0);
    static_assert(fixed<18, 38>() == 0);
    static_assert(fixed<18, 39>() == 0);
    static_assert(fixed<18, 40>() == 0);
    static_assert(fixed<18, 41>() == 0);
    static_assert(fixed<18, 42>() == 0);
    static_assert(fixed<18, 43>() == 0);
    static_assert(fixed<18, 44>() == 0);
    static_assert(fixed<18, 45>() == 0);
    static_assert(fixed<18, 46>() == 0);
#endif
}
// 19
namespace fpn
{
    static_assert(fixed<19, 1>() == 0);
    static_assert(fixed<19, 2>() == 0);
    static_assert(fixed<19, 3>() == 0);
    static_assert(fixed<19, 4>() == 0);
    static_assert(fixed<19, 5>() == 0);
    static_assert(fixed<19, 6>() == 0);
    static_assert(fixed<19, 7>() == 0);
    static_assert(fixed<19, 8>() == 0);
    static_assert(fixed<19, 9>() == 0);
    static_assert(fixed<19, 10>() == 0);
    static_assert(fixed<19, 11>() == 0);
    static_assert(fixed<19, 12>() == 0);
    static_assert(fixed<19, 13>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<19, 14>() == 0);
    static_assert(fixed<19, 15>() == 0);
    static_assert(fixed<19, 16>() == 0);
    static_assert(fixed<19, 17>() == 0);
    static_assert(fixed<19, 18>() == 0);
    static_assert(fixed<19, 19>() == 0);
    static_assert(fixed<19, 20>() == 0);
    static_assert(fixed<19, 21>() == 0);
    static_assert(fixed<19, 22>() == 0);
    static_assert(fixed<19, 23>() == 0);
    static_assert(fixed<19, 24>() == 0);
    static_assert(fixed<19, 25>() == 0);
    static_assert(fixed<19, 26>() == 0);
    static_assert(fixed<19, 27>() == 0);
    static_assert(fixed<19, 28>() == 0);
    static_assert(fixed<19, 29>() == 0);
    static_assert(fixed<19, 30>() == 0);
    static_assert(fixed<19, 31>() == 0);
    static_assert(fixed<19, 32>() == 0);
    static_assert(fixed<19, 33>() == 0);
    static_assert(fixed<19, 34>() == 0);
    static_assert(fixed<19, 35>() == 0);
    static_assert(fixed<19, 36>() == 0);
    static_assert(fixed<19, 37>() == 0);
    static_assert(fixed<19, 38>() == 0);
    static_assert(fixed<19, 39>() == 0);
    static_assert(fixed<19, 40>() == 0);
    static_assert(fixed<19, 41>() == 0);
    static_assert(fixed<19, 42>() == 0);
    static_assert(fixed<19, 43>() == 0);
    static_assert(fixed<19, 44>() == 0);
    static_assert(fixed<19, 45>() == 0);
#endif
}
// 19
namespace fpn
{
    static_assert(fixed<20, 1>() == 0);
    static_assert(fixed<20, 2>() == 0);
    static_assert(fixed<20, 3>() == 0);
    static_assert(fixed<20, 4>() == 0);
    static_assert(fixed<20, 5>() == 0);
    static_assert(fixed<20, 6>() == 0);
    static_assert(fixed<20, 7>() == 0);
    static_assert(fixed<20, 8>() == 0);
    static_assert(fixed<20, 9>() == 0);
    static_assert(fixed<20, 10>() == 0);
    static_assert(fixed<20, 11>() == 0);
    static_assert(fixed<20, 12>() == 0);
#if __SIZEOF_POINTER__ >= 8
    static_assert(fixed<20, 13>() == 0);
    static_assert(fixed<20, 14>() == 0);
    static_assert(fixed<20, 15>() == 0);
    static_assert(fixed<20, 16>() == 0);
    static_assert(fixed<20, 17>() == 0);
    static_assert(fixed<20, 18>() == 0);
    static_assert(fixed<20, 19>() == 0);
    static_assert(fixed<20, 20>() == 0);
    static_assert(fixed<20, 21>() == 0);
    static_assert(fixed<20, 22>() == 0);
    static_assert(fixed<20, 23>() == 0);
    static_assert(fixed<20, 24>() == 0);
    static_assert(fixed<20, 25>() == 0);
    static_assert(fixed<20, 26>() == 0);
    static_assert(fixed<20, 27>() == 0);
    static_assert(fixed<20, 28>() == 0);
    static_assert(fixed<20, 29>() == 0);
    static_assert(fixed<20, 30>() == 0);
    static_assert(fixed<20, 31>() == 0);
    static_assert(fixed<20, 32>() == 0);
    static_assert(fixed<20, 33>() == 0);
    static_assert(fixed<20, 34>() == 0);
    static_assert(fixed<20, 35>() == 0);
    static_assert(fixed<20, 36>() == 0);
    static_assert(fixed<20, 37>() == 0);
    static_assert(fixed<20, 38>() == 0);
    static_assert(fixed<20, 39>() == 0);
    static_assert(fixed<20, 40>() == 0);
    static_assert(fixed<20, 41>() == 0);
    static_assert(fixed<20, 42>() == 0);
    static_assert(fixed<20, 43>() == 0);
    static_assert(fixed<20, 44>() == 0);
#endif
}

//TODO Add the rest of posible values
