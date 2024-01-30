#include "fixed_math.hpp"

// Addition
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

// Subtraction
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

//THINK Compile-time multiplication and division
// Multiplication (whole numbers)
/*
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(0) * fixed8_8(0) == 0);
    static_assert(fixed8_8(0) * fixed8_8(1) == 1);
    static_assert(fixed8_8(1) * fixed8_8(0) == 0);
    static_assert(fixed8_8(1) * fixed8_8(1) == 1);
    static_assert(fixed8_8(2) * fixed8_8(2) == 2);

    static_assert(fixed8_8(-0) * fixed8_8(1) ==  1);
    static_assert(fixed8_8(-1) * fixed8_8(0) == -1);
    static_assert(fixed8_8(-1) * fixed8_8(1) == -1);
    static_assert(fixed8_8(-2) * fixed8_8(2) == -4);

    static_assert(fixed8_8(0) * fixed8_8(-1) == -1);
    static_assert(fixed8_8(1) * fixed8_8(-0) ==  1);
    static_assert(fixed8_8(1) * fixed8_8(-1) == -1);
    static_assert(fixed8_8(2) * fixed8_8(-2) == -4);

    static_assert(fixed8_8(-0) * fixed8_8(-1) == -1);
    static_assert(fixed8_8(-1) * fixed8_8(-0) == -1);
    static_assert(fixed8_8(-1) * fixed8_8(-1) ==  1);
    static_assert(fixed8_8(-2) * fixed8_8(-2) ==  4);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed8_16(0) * fixed8_16(0) == 0);
    static_assert(fixed8_16(0) * fixed8_16(1) == 1);
    static_assert(fixed8_16(1) * fixed8_16(0) == 0);
    static_assert(fixed8_16(1) * fixed8_16(1) == 1);
    static_assert(fixed8_16(2) * fixed8_16(2) == 2);

    static_assert(fixed8_16(-0) * fixed8_16(1) ==  1);
    static_assert(fixed8_16(-1) * fixed8_16(0) == -1);
    static_assert(fixed8_16(-1) * fixed8_16(1) == -1);
    static_assert(fixed8_16(-2) * fixed8_16(2) == -4);

    static_assert(fixed8_16(0) * fixed8_16(-1) == -1);
    static_assert(fixed8_16(1) * fixed8_16(-0) ==  1);
    static_assert(fixed8_16(1) * fixed8_16(-1) == -1);
    static_assert(fixed8_16(2) * fixed8_16(-2) == -4);

    static_assert(fixed8_16(-0) * fixed8_16(-1) == -1);
    static_assert(fixed8_16(-1) * fixed8_16(-0) == -1);
    static_assert(fixed8_16(-1) * fixed8_16(-1) ==  1);
    static_assert(fixed8_16(-2) * fixed8_16(-2) ==  4);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(0) * fixed16_8(0) == 0);
    static_assert(fixed16_8(0) * fixed16_8(1) == 1);
    static_assert(fixed16_8(1) * fixed16_8(0) == 0);
    static_assert(fixed16_8(1) * fixed16_8(1) == 1);
    static_assert(fixed16_8(2) * fixed16_8(2) == 2);

    static_assert(fixed16_8(-0) * fixed16_8(1) ==  1);
    static_assert(fixed16_8(-1) * fixed16_8(0) == -1);
    static_assert(fixed16_8(-1) * fixed16_8(1) == -1);
    static_assert(fixed16_8(-2) * fixed16_8(2) == -4);

    static_assert(fixed16_8(0) * fixed16_8(-1) == -1);
    static_assert(fixed16_8(1) * fixed16_8(-0) ==  1);
    static_assert(fixed16_8(1) * fixed16_8(-1) == -1);
    static_assert(fixed16_8(2) * fixed16_8(-2) == -4);

    static_assert(fixed16_8(-0) * fixed16_8(-1) == -1);
    static_assert(fixed16_8(-1) * fixed16_8(-0) == -1);
    static_assert(fixed16_8(-1) * fixed16_8(-1) ==  1);
    static_assert(fixed16_8(-2) * fixed16_8(-2) ==  4);
#pragma endregion
}
*/
