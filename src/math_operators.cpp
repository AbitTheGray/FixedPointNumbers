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

// Division (integers)
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(1) / fixed8_8(1) == 1);
    static_assert(fixed8_8(2) / fixed8_8(1) == 2);
    static_assert((fixed8_8(1) / fixed8_8(2)).operator double() == 0.5);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed16_8(1) / fixed16_8(1) == 1);
    static_assert(fixed16_8(2) / fixed16_8(1) == 2);
    static_assert((fixed16_8(1) / fixed16_8(2)).operator double() == 0.5);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(1) / fixed16_8(1) == 1);
    static_assert(fixed16_8(2) / fixed16_8(1) == 2);
    static_assert((fixed16_8(1) / fixed16_8(2)).operator double() == 0.5);
#pragma endregion
#pragma region fixed16_16
    static_assert(fixed16_16(1) / fixed16_16(1) == 1);
    static_assert(fixed16_16(2) / fixed16_16(1) == 2);
    static_assert((fixed16_16(1) / fixed16_16(2)).operator double() == 0.5);
#pragma endregion
#pragma region fixed32_16
    static_assert(fixed32_16(1) / fixed32_16(1) == 1);
    static_assert(fixed32_16(2) / fixed32_16(1) == 2);
    static_assert((fixed32_16(1) / fixed32_16(2)).operator double() == 0.5);
#pragma endregion
#pragma region fixed32_32
    static_assert(fixed32_32(1) / fixed32_32(1) == 1);
    static_assert(fixed32_32(2) / fixed32_32(1) == 2);
    static_assert((fixed32_32(1) / fixed32_32(2)).operator double() == 0.5);
#pragma endregion
}

// Division (integer + decimal, decimals)
#if FPN_CONSTEXPR_HAS == 1
namespace fpn
{
#pragma region fixed8_8
    static_assert(fixed8_8(1.5  ) / fixed8_8(1) == 1.5);
    static_assert(fixed8_8(1.125) / fixed8_8(1) == 1.125);

    static_assert(fixed8_8(1) / fixed8_8(2) == 0.5);
    static_assert(fixed8_8(1) / fixed8_8(4) == 0.25);
    static_assert(fixed8_8(1) / fixed8_8(8) == 0.125);

    static_assert(fixed8_8(4.5) / fixed8_8(1.5) == 3);
    static_assert(fixed8_8(58.125) / fixed8_8(23.25) == 2.5);
    static_assert((fixed8_8(1.5) / fixed8_8(1)).operator double() == 1.5);
    static_assert((fixed8_8(1.1484375) / fixed8_8(1.3125)).operator double() == 0.875);
#pragma endregion
#pragma region fixed8_16
    static_assert(fixed8_16(1.5  ) / fixed8_16(1) == 1.5);
    static_assert(fixed8_16(1.125) / fixed8_16(1) == 1.125);

    static_assert(fixed8_16(1) / fixed8_16(2) == 0.5);
    static_assert(fixed8_16(1) / fixed8_16(4) == 0.25);
    static_assert(fixed8_16(1) / fixed8_16(8) == 0.125);

    static_assert(fixed8_16(4.5) / fixed8_16(1.5) == 3);
    static_assert(fixed8_16(58.125) / fixed8_16(23.25) == 2.5);
    static_assert((fixed8_16(1.5) / fixed8_16(1)).operator double() == 1.5);
    static_assert((fixed8_16(1.1484375) / fixed8_16(1.3125)).operator double() == 0.875);
#pragma endregion
#pragma region fixed16_8
    static_assert(fixed16_8(1.5  ) / fixed16_8(1) == 1.5);
    static_assert(fixed16_8(1.125) / fixed16_8(1) == 1.125);

    static_assert(fixed16_8(1) / fixed16_8(2) == 0.5);
    static_assert(fixed16_8(1) / fixed16_8(4) == 0.25);
    static_assert(fixed16_8(1) / fixed16_8(8) == 0.125);

    static_assert(fixed16_8(4.5) / fixed16_8(1.5) == 3);
    static_assert(fixed16_8(58.125) / fixed16_8(23.25) == 2.5);
    static_assert((fixed16_8(1.5) / fixed16_8(1)).operator double() == 1.5);
    static_assert((fixed16_8(1.1484375) / fixed16_8(1.3125)).operator double() == 0.875);
#pragma endregion
}
#endif

// Inverse
#if FPN_CONSTEXPR_HAS == 1
namespace fpn
{
#pragma region fixed8_8
    static_assert(Inverse(fixed8_8( 1)) == 1     );
    static_assert(Inverse(fixed8_8( 2)) == 0.5   );
    static_assert(Inverse(fixed8_8( 4)) == 0.25  );
    static_assert(Inverse(fixed8_8( 8)) == 0.125 );
    static_assert(Inverse(fixed8_8(16)) == 0.0625);

    static_assert(Inverse(fixed8_8(0.5   )) ==  2);
    static_assert(Inverse(fixed8_8(0.25  )) ==  4);
    static_assert(Inverse(fixed8_8(0.125 )) ==  8);
    static_assert(Inverse(fixed8_8(0.0625)) == 16);
#pragma endregion
#pragma region fixed8_16
    static_assert(Inverse(fixed8_16( 1)) == 1     );
    static_assert(Inverse(fixed8_16( 2)) == 0.5   );
    static_assert(Inverse(fixed8_16( 4)) == 0.25  );
    static_assert(Inverse(fixed8_16( 8)) == 0.125 );
    static_assert(Inverse(fixed8_16(16)) == 0.0625);

    static_assert(Inverse(fixed8_16(0.5   )) ==  2);
    static_assert(Inverse(fixed8_16(0.25  )) ==  4);
    static_assert(Inverse(fixed8_16(0.125 )) ==  8);
    static_assert(Inverse(fixed8_16(0.0625)) == 16);
#pragma endregion
#pragma region fixed16_8
    static_assert(Inverse(fixed16_8( 1)) == 1     );
    static_assert(Inverse(fixed16_8( 2)) == 0.5   );
    static_assert(Inverse(fixed16_8( 4)) == 0.25  );
    static_assert(Inverse(fixed16_8( 8)) == 0.125 );
    static_assert(Inverse(fixed16_8(16)) == 0.0625);

    static_assert(Inverse(fixed16_8(0.5   )) ==  2);
    static_assert(Inverse(fixed16_8(0.25  )) ==  4);
    static_assert(Inverse(fixed16_8(0.125 )) ==  8);
    static_assert(Inverse(fixed16_8(0.0625)) == 16);
#pragma endregion
#pragma region fixed16_16
    static_assert(Inverse(fixed16_16( 1)) == 1     );
    static_assert(Inverse(fixed16_16( 2)) == 0.5   );
    static_assert(Inverse(fixed16_16( 4)) == 0.25  );
    static_assert(Inverse(fixed16_16( 8)) == 0.125 );
    static_assert(Inverse(fixed16_16(16)) == 0.0625);

    static_assert(Inverse(fixed16_16(0.5   )) ==  2);
    static_assert(Inverse(fixed16_16(0.25  )) ==  4);
    static_assert(Inverse(fixed16_16(0.125 )) ==  8);
    static_assert(Inverse(fixed16_16(0.0625)) == 16);
#pragma endregion
#pragma region fixed32_16
    static_assert(Inverse(fixed32_16( 1)) == 1     );
    static_assert(Inverse(fixed32_16( 2)) == 0.5   );
    static_assert(Inverse(fixed32_16( 4)) == 0.25  );
    static_assert(Inverse(fixed32_16( 8)) == 0.125 );
    static_assert(Inverse(fixed32_16(16)) == 0.0625);

    static_assert(Inverse(fixed32_16(0.5   )) ==  2);
    static_assert(Inverse(fixed32_16(0.25  )) ==  4);
    static_assert(Inverse(fixed32_16(0.125 )) ==  8);
    static_assert(Inverse(fixed32_16(0.0625)) == 16);
#pragma endregion
#pragma region fixed32_32
    static_assert(Inverse(fixed32_32( 1)) == 1     );
    static_assert(Inverse(fixed32_32( 2)) == 0.5   );
    static_assert(Inverse(fixed32_32( 4)) == 0.25  );
    static_assert(Inverse(fixed32_32( 8)) == 0.125 );
    static_assert(Inverse(fixed32_32(16)) == 0.0625);

    static_assert(Inverse(fixed32_32(0.5   )) ==  2);
    static_assert(Inverse(fixed32_32(0.25  )) ==  4);
    static_assert(Inverse(fixed32_32(0.125 )) ==  8);
    static_assert(Inverse(fixed32_32(0.0625)) == 16);
#pragma endregion
}
#endif
