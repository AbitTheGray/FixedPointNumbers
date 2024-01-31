#include "fixed_math.hpp"

// Addition (integers)
//TODO Floating-point checks
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(0) + fixed8_8(0) == 0);
    static_assert(fixed8_8(0) + fixed8_8(1) == 1);
    static_assert(fixed8_8(1) + fixed8_8(0) == 1);
    static_assert(fixed8_8(1) + fixed8_8(1) == 2);
    static_assert(fixed8_8(2) + fixed8_8(2) == 4);

    static_assert(fixed8_8(-0) + fixed8_8(1) ==  1);
    static_assert(fixed8_8(-1) + fixed8_8(0) == -1);
    static_assert(fixed8_8(-1) + fixed8_8(1) ==  0);
    static_assert(fixed8_8(-2) + fixed8_8(2) ==  0);

    static_assert(fixed8_8(0) + fixed8_8(-1) == -1);
    static_assert(fixed8_8(1) + fixed8_8(-0) ==  1);
    static_assert(fixed8_8(1) + fixed8_8(-1) ==  0);
    static_assert(fixed8_8(2) + fixed8_8(-2) ==  0);

    static_assert(fixed8_8(-0) + fixed8_8(-1) == -1);
    static_assert(fixed8_8(-1) + fixed8_8(-0) == -1);
    static_assert(fixed8_8(-1) + fixed8_8(-1) == -2);
    static_assert(fixed8_8(-2) + fixed8_8(-2) == -4);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed8_16(0) + fixed8_16(0) == 0);
    static_assert(fixed8_16(0) + fixed8_16(1) == 1);
    static_assert(fixed8_16(1) + fixed8_16(0) == 1);
    static_assert(fixed8_16(1) + fixed8_16(1) == 2);
    static_assert(fixed8_16(2) + fixed8_16(2) == 4);

    static_assert(fixed8_16(-0) + fixed8_16(1) ==  1);
    static_assert(fixed8_16(-1) + fixed8_16(0) == -1);
    static_assert(fixed8_16(-1) + fixed8_16(1) ==  0);
    static_assert(fixed8_16(-2) + fixed8_16(2) ==  0);

    static_assert(fixed8_16(0) + fixed8_16(-1) == -1);
    static_assert(fixed8_16(1) + fixed8_16(-0) ==  1);
    static_assert(fixed8_16(1) + fixed8_16(-1) ==  0);
    static_assert(fixed8_16(2) + fixed8_16(-2) ==  0);

    static_assert(fixed8_16(-0) + fixed8_16(-1) == -1);
    static_assert(fixed8_16(-1) + fixed8_16(-0) == -1);
    static_assert(fixed8_16(-1) + fixed8_16(-1) == -2);
    static_assert(fixed8_16(-2) + fixed8_16(-2) == -4);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(0) + fixed16_8(0) == 0);
    static_assert(fixed16_8(0) + fixed16_8(1) == 1);
    static_assert(fixed16_8(1) + fixed16_8(0) == 1);
    static_assert(fixed16_8(1) + fixed16_8(1) == 2);
    static_assert(fixed16_8(2) + fixed16_8(2) == 4);

    static_assert(fixed16_8(-0) + fixed16_8(1) ==  1);
    static_assert(fixed16_8(-1) + fixed16_8(0) == -1);
    static_assert(fixed16_8(-1) + fixed16_8(1) ==  0);
    static_assert(fixed16_8(-2) + fixed16_8(2) ==  0);

    static_assert(fixed16_8(0) + fixed16_8(-1) == -1);
    static_assert(fixed16_8(1) + fixed16_8(-0) ==  1);
    static_assert(fixed16_8(1) + fixed16_8(-1) ==  0);
    static_assert(fixed16_8(2) + fixed16_8(-2) ==  0);

    static_assert(fixed16_8(-0) + fixed16_8(-1) == -1);
    static_assert(fixed16_8(-1) + fixed16_8(-0) == -1);
    static_assert(fixed16_8(-1) + fixed16_8(-1) == -2);
    static_assert(fixed16_8(-2) + fixed16_8(-2) == -4);
#pragma endregion
}

// Subtraction (integers)
//TODO Floating-point checks
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(0) - fixed8_8(0) ==  0);
    static_assert(fixed8_8(0) - fixed8_8(1) == -1);
    static_assert(fixed8_8(1) - fixed8_8(0) ==  1);
    static_assert(fixed8_8(1) - fixed8_8(1) ==  0);
    static_assert(fixed8_8(2) - fixed8_8(2) ==  0);

    static_assert(fixed8_8(-0) - fixed8_8(1) == -1);
    static_assert(fixed8_8(-1) - fixed8_8(0) == -1);
    static_assert(fixed8_8(-1) - fixed8_8(1) == -2);
    static_assert(fixed8_8(-2) - fixed8_8(2) == -4);

    static_assert(fixed8_8(0) - fixed8_8(-1) == 1);
    static_assert(fixed8_8(1) - fixed8_8(-0) == 1);
    static_assert(fixed8_8(1) - fixed8_8(-1) == 2);
    static_assert(fixed8_8(2) - fixed8_8(-2) == 4);

    static_assert(fixed8_8(-0) - fixed8_8(-1) ==  1);
    static_assert(fixed8_8(-1) - fixed8_8(-0) == -1);
    static_assert(fixed8_8(-1) - fixed8_8(-1) ==  0);
    static_assert(fixed8_8(-2) - fixed8_8(-2) ==  0);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed8_16(0) - fixed8_16(0) ==  0);
    static_assert(fixed8_16(0) - fixed8_16(1) == -1);
    static_assert(fixed8_16(1) - fixed8_16(0) ==  1);
    static_assert(fixed8_16(1) - fixed8_16(1) ==  0);
    static_assert(fixed8_16(2) - fixed8_16(2) ==  0);

    static_assert(fixed8_16(-0) - fixed8_16(1) == -1);
    static_assert(fixed8_16(-1) - fixed8_16(0) == -1);
    static_assert(fixed8_16(-1) - fixed8_16(1) == -2);
    static_assert(fixed8_16(-2) - fixed8_16(2) == -4);

    static_assert(fixed8_16(0) - fixed8_16(-1) == 1);
    static_assert(fixed8_16(1) - fixed8_16(-0) == 1);
    static_assert(fixed8_16(1) - fixed8_16(-1) == 2);
    static_assert(fixed8_16(2) - fixed8_16(-2) == 4);

    static_assert(fixed8_16(-0) - fixed8_16(-1) ==  1);
    static_assert(fixed8_16(-1) - fixed8_16(-0) == -1);
    static_assert(fixed8_16(-1) - fixed8_16(-1) ==  0);
    static_assert(fixed8_16(-2) - fixed8_16(-2) ==  0);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(0) - fixed16_8(0) ==  0);
    static_assert(fixed16_8(0) - fixed16_8(1) == -1);
    static_assert(fixed16_8(1) - fixed16_8(0) ==  1);
    static_assert(fixed16_8(1) - fixed16_8(1) ==  0);
    static_assert(fixed16_8(2) - fixed16_8(2) ==  0);

    static_assert(fixed16_8(-0) - fixed16_8(1) == -1);
    static_assert(fixed16_8(-1) - fixed16_8(0) == -1);
    static_assert(fixed16_8(-1) - fixed16_8(1) == -2);
    static_assert(fixed16_8(-2) - fixed16_8(2) == -4);

    static_assert(fixed16_8(0) - fixed16_8(-1) == 1);
    static_assert(fixed16_8(1) - fixed16_8(-0) == 1);
    static_assert(fixed16_8(1) - fixed16_8(-1) == 2);
    static_assert(fixed16_8(2) - fixed16_8(-2) == 4);

    static_assert(fixed16_8(-0) - fixed16_8(-1) ==  1);
    static_assert(fixed16_8(-1) - fixed16_8(-0) == -1);
    static_assert(fixed16_8(-1) - fixed16_8(-1) ==  0);
    static_assert(fixed16_8(-2) - fixed16_8(-2) ==  0);
#pragma endregion
}

// Multiplication (integers)
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(0) * fixed8_8(0) == 0);
    static_assert(fixed8_8(0) * fixed8_8(1) == 0);
    static_assert(fixed8_8(1) * fixed8_8(0) == 0);
    static_assert(fixed8_8(1) * fixed8_8(1) == 1);
    static_assert(fixed8_8(2) * fixed8_8(2) == 4);

    static_assert(fixed8_8(-0) * fixed8_8(1) ==  0);
    static_assert(fixed8_8(-1) * fixed8_8(0) ==  0);
    static_assert(fixed8_8(-1) * fixed8_8(1) == -1);
    static_assert(fixed8_8(-2) * fixed8_8(2) == -4);

    static_assert(fixed8_8(0) * fixed8_8(-1) ==  0);
    static_assert(fixed8_8(1) * fixed8_8(-0) ==  0);
    static_assert(fixed8_8(1) * fixed8_8(-1) == -1);
    static_assert(fixed8_8(2) * fixed8_8(-2) == -4);

    static_assert(fixed8_8(-0) * fixed8_8(-1) == 0);
    static_assert(fixed8_8(-1) * fixed8_8(-0) == 0);
    static_assert(fixed8_8(-1) * fixed8_8(-1) == 1);
    static_assert(fixed8_8(-2) * fixed8_8(-2) == 4);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed8_16(0) * fixed8_16(0) == 0);
    static_assert(fixed8_16(0) * fixed8_16(1) == 0);
    static_assert(fixed8_16(1) * fixed8_16(0) == 0);
    static_assert(fixed8_16(1) * fixed8_16(1) == 1);
    static_assert(fixed8_16(2) * fixed8_16(2) == 4);

    static_assert(fixed8_16(-0) * fixed8_16(1) ==  0);
    static_assert(fixed8_16(-1) * fixed8_16(0) ==  0);
    static_assert(fixed8_16(-1) * fixed8_16(1) == -1);
    static_assert(fixed8_16(-2) * fixed8_16(2) == -4);

    static_assert(fixed8_16(0) * fixed8_16(-1) ==  0);
    static_assert(fixed8_16(1) * fixed8_16(-0) ==  0);
    static_assert(fixed8_16(1) * fixed8_16(-1) == -1);
    static_assert(fixed8_16(2) * fixed8_16(-2) == -4);

    static_assert(fixed8_16(-0) * fixed8_16(-1) == 0);
    static_assert(fixed8_16(-1) * fixed8_16(-0) == 0);
    static_assert(fixed8_16(-1) * fixed8_16(-1) == 1);
    static_assert(fixed8_16(-2) * fixed8_16(-2) == 4);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(0) * fixed16_8(0) == 0);
    static_assert(fixed16_8(0) * fixed16_8(1) == 0);
    static_assert(fixed16_8(1) * fixed16_8(0) == 0);
    static_assert(fixed16_8(1) * fixed16_8(1) == 1);
    static_assert(fixed16_8(2) * fixed16_8(2) == 4);

    static_assert(fixed16_8(-0) * fixed16_8(1) ==  0);
    static_assert(fixed16_8(-1) * fixed16_8(0) ==  0);
    static_assert(fixed16_8(-1) * fixed16_8(1) == -1);
    static_assert(fixed16_8(-2) * fixed16_8(2) == -4);

    static_assert(fixed16_8(0) * fixed16_8(-1) ==  0);
    static_assert(fixed16_8(1) * fixed16_8(-0) ==  0);
    static_assert(fixed16_8(1) * fixed16_8(-1) == -1);
    static_assert(fixed16_8(2) * fixed16_8(-2) == -4);

    static_assert(fixed16_8(-0) * fixed16_8(-1) == 0);
    static_assert(fixed16_8(-1) * fixed16_8(-0) == 0);
    static_assert(fixed16_8(-1) * fixed16_8(-1) == 1);
    static_assert(fixed16_8(-2) * fixed16_8(-2) == 4);
#pragma endregion
}

// Multiplication (integer + decimal, decimals)
#if FPN_CONSTEXPR_HAS == 1
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(0) * fixed8_8(1.5) == 0);
    static_assert(fixed8_8(1) * fixed8_8(1.5) == 1.5);
    static_assert(fixed8_8(2) * fixed8_8(1.5) == 3);

    static_assert(fixed8_8(-0) * fixed8_8(1.5) == -0);
    static_assert(fixed8_8(-1) * fixed8_8(1.5) == -1.5);
    static_assert(fixed8_8(-2) * fixed8_8(1.5) == -3);

    static_assert(fixed8_8(0) * fixed8_8(-1.5) == -0);
    static_assert(fixed8_8(1) * fixed8_8(-1.5) == -1.5);
    static_assert(fixed8_8(2) * fixed8_8(-1.5) == -3);

    static_assert(fixed8_8(-0) * fixed8_8(-1.5) == 0);
    static_assert(fixed8_8(-1) * fixed8_8(-1.5) == 1.5);
    static_assert(fixed8_8(-2) * fixed8_8(-1.5) == 3);

    static_assert(fixed8_8( 1.5) * fixed8_8( 1.5) ==  2.25);
    static_assert(fixed8_8(-1.5) * fixed8_8( 1.5) == -2.25);
    static_assert(fixed8_8( 1.5) * fixed8_8(-1.5) == -2.25);
    static_assert(fixed8_8(-1.5) * fixed8_8(-1.5) ==  2.25);

    static_assert(fixed8_8( 1.25) * fixed8_8( 1.25) ==  1.5625);
    static_assert(fixed8_8(-1.25) * fixed8_8( 1.25) == -1.5625);
    static_assert(fixed8_8( 1.25) * fixed8_8(-1.25) == -1.5625);
    static_assert(fixed8_8(-1.25) * fixed8_8(-1.25) ==  1.5625);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed8_16(0) * fixed8_16(1.5) == 0);
    static_assert(fixed8_16(1) * fixed8_16(1.5) == 1.5);
    static_assert(fixed8_16(2) * fixed8_16(1.5) == 3);

    static_assert(fixed8_16(-0) * fixed8_16(1.5) == -0);
    static_assert(fixed8_16(-1) * fixed8_16(1.5) == -1.5);
    static_assert(fixed8_16(-2) * fixed8_16(1.5) == -3);

    static_assert(fixed8_16(0) * fixed8_16(-1.5) == -0);
    static_assert(fixed8_16(1) * fixed8_16(-1.5) == -1.5);
    static_assert(fixed8_16(2) * fixed8_16(-1.5) == -3);

    static_assert(fixed8_16(-0) * fixed8_16(-1.5) == 0);
    static_assert(fixed8_16(-1) * fixed8_16(-1.5) == 1.5);
    static_assert(fixed8_16(-2) * fixed8_16(-1.5) == 3);

    static_assert(fixed8_16( 1.5) * fixed8_16( 1.5) ==  2.25);
    static_assert(fixed8_16(-1.5) * fixed8_16( 1.5) == -2.25);
    static_assert(fixed8_16( 1.5) * fixed8_16(-1.5) == -2.25);
    static_assert(fixed8_16(-1.5) * fixed8_16(-1.5) ==  2.25);

    static_assert(fixed8_16( 1.25) * fixed8_16( 1.25) ==  1.5625);
    static_assert(fixed8_16(-1.25) * fixed8_16( 1.25) == -1.5625);
    static_assert(fixed8_16( 1.25) * fixed8_16(-1.25) == -1.5625);
    static_assert(fixed8_16(-1.25) * fixed8_16(-1.25) ==  1.5625);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(0) * fixed16_8(1.5) == 0);
    static_assert(fixed16_8(1) * fixed16_8(1.5) == 1.5);
    static_assert(fixed16_8(2) * fixed16_8(1.5) == 3);

    static_assert(fixed16_8(-0) * fixed16_8(1.5) == -0);
    static_assert(fixed16_8(-1) * fixed16_8(1.5) == -1.5);
    static_assert(fixed16_8(-2) * fixed16_8(1.5) == -3);

    static_assert(fixed16_8(0) * fixed16_8(-1.5) == -0);
    static_assert(fixed16_8(1) * fixed16_8(-1.5) == -1.5);
    static_assert(fixed16_8(2) * fixed16_8(-1.5) == -3);

    static_assert(fixed16_8(-0) * fixed16_8(-1.5) == 0);
    static_assert(fixed16_8(-1) * fixed16_8(-1.5) == 1.5);
    static_assert(fixed16_8(-2) * fixed16_8(-1.5) == 3);

    static_assert(fixed16_8( 1.5) * fixed16_8( 1.5) ==  2.25);
    static_assert(fixed16_8(-1.5) * fixed16_8( 1.5) == -2.25);
    static_assert(fixed16_8( 1.5) * fixed16_8(-1.5) == -2.25);
    static_assert(fixed16_8(-1.5) * fixed16_8(-1.5) ==  2.25);

    static_assert(fixed16_8( 1.25) * fixed16_8( 1.25) ==  1.5625);
    static_assert(fixed16_8(-1.25) * fixed16_8( 1.25) == -1.5625);
    static_assert(fixed16_8( 1.25) * fixed16_8(-1.25) == -1.5625);
    static_assert(fixed16_8(-1.25) * fixed16_8(-1.25) ==  1.5625);
#pragma endregion
}
#endif

//TODO Division checks
