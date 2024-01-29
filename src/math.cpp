#include "fixed_math.hpp"

namespace fpn
{
#pragma region Basic operations
    static_assert(abs(fixed8_8(0))    == 0);
    static_assert(abs(fixed8_8(1))    == 1);
    static_assert(abs(fixed8_8(2))    == 2);
    static_assert(abs(fixed8_8(127))  == 127);
    static_assert(abs(fixed8_8(-1))   == 1);
    static_assert(abs(fixed8_8(-2))   == 2);
    static_assert(abs(fixed8_8(-127)) == 127);
    static_assert(abs(fixed8_8(-128)) == -128);

    static_assert(min(fixed8_8( 0), fixed8_8( 1)) ==  0);
    static_assert(min(fixed8_8(-1), fixed8_8( 0)) == -1);
    static_assert(min(fixed8_8(-1), fixed8_8( 1)) == -1);
    static_assert(min(fixed8_8(-1), fixed8_8( 2)) == -1);
    static_assert(min(fixed8_8(-2), fixed8_8( 1)) == -2);
    static_assert(min(fixed8_8(-2), fixed8_8( 2)) == -2);
    static_assert(min(fixed8_8(-1), fixed8_8(-2)) == -2);
    static_assert(min(fixed8_8(-2), fixed8_8(-1)) == -2);
    static_assert(min(fixed8_8( 1), fixed8_8( 2)) ==  1);
    static_assert(min(fixed8_8( 2), fixed8_8( 1)) ==  1);

    static_assert(max(fixed8_8( 0), fixed8_8( 1)) ==  1);
    static_assert(max(fixed8_8(-1), fixed8_8( 0)) ==  0);
    static_assert(max(fixed8_8(-1), fixed8_8( 1)) ==  1);
    static_assert(max(fixed8_8(-1), fixed8_8( 2)) ==  2);
    static_assert(max(fixed8_8(-2), fixed8_8( 1)) ==  1);
    static_assert(max(fixed8_8(-2), fixed8_8( 2)) ==  2);
    static_assert(max(fixed8_8(-1), fixed8_8(-2)) == -1);
    static_assert(max(fixed8_8(-2), fixed8_8(-1)) == -1);
    static_assert(max(fixed8_8( 1), fixed8_8( 2)) ==  2);
    static_assert(max(fixed8_8( 2), fixed8_8( 1)) ==  2);

    static_assert(dim(fixed8_8( 0), fixed8_8( 1)) == 1);
    static_assert(dim(fixed8_8(-1), fixed8_8( 0)) == 1);
    static_assert(dim(fixed8_8(-1), fixed8_8( 1)) == 2);
    static_assert(dim(fixed8_8(-1), fixed8_8( 2)) == 3);
    static_assert(dim(fixed8_8(-2), fixed8_8( 1)) == 3);
    static_assert(dim(fixed8_8(-2), fixed8_8( 2)) == 4);
    static_assert(dim(fixed8_8(-1), fixed8_8(-2)) == 1);
    static_assert(dim(fixed8_8(-2), fixed8_8(-1)) == 1);
    static_assert(dim(fixed8_8( 1), fixed8_8( 2)) == 1);
    static_assert(dim(fixed8_8( 2), fixed8_8( 1)) == 1);

    static_assert(sign(fixed8_8( 0)) ==  0);
    static_assert(sign(fixed8_8( 1)) ==  1);
    static_assert(sign(fixed8_8( 2)) ==  1);
    static_assert(sign(fixed8_8( 3)) ==  1);
    static_assert(sign(fixed8_8(-1)) == -1);
    static_assert(sign(fixed8_8(-2)) == -1);
    static_assert(sign(fixed8_8(-3)) == -1);
#pragma endregion
#pragma region Exponential functions
    //TODO
#pragma endregion
#pragma region Power functions
    //TODO
#pragma endregion
#pragma region Trigonometric functions
    //TODO
#pragma endregion
#pragma region Hyperbolic functions
    //TODO
#pragma endregion
#pragma region Error and gamma functions
    //TODO
#pragma endregion
#pragma region Nearest integer operations
    static_assert(floor(fixed8_8(0))    == 0);
    static_assert(floor(fixed8_8(0.1))  == 0);
    static_assert(floor(fixed8_8(0.5))  == 0);
    static_assert(floor(fixed8_8(0.9))  == 0);
    static_assert(floor(fixed8_8(1))    == 1);
    static_assert(floor(fixed8_8(-0.1)) == -1);
    static_assert(floor(fixed8_8(-0.5)) == -1);
    static_assert(floor(fixed8_8(-0.9)) == -1);
    static_assert(floor(fixed8_8(-1))   == -1);

    static_assert(ceil(fixed8_8(0))    == 0);
    static_assert(ceil(fixed8_8(0.1))  == 1);
    static_assert(ceil(fixed8_8(0.5))  == 1);
    static_assert(ceil(fixed8_8(0.9))  == 1);
    static_assert(ceil(fixed8_8(1))    == 1);
    static_assert(ceil(fixed8_8(-0.1)) == 0);
    static_assert(ceil(fixed8_8(-0.5)) == 0);
    static_assert(ceil(fixed8_8(-0.9)) == 0);
    static_assert(ceil(fixed8_8(-1))   == -1);

    static_assert(trunc(fixed8_8(0))    == 0);
    static_assert(trunc(fixed8_8(0.1))  == 0);
    static_assert(trunc(fixed8_8(0.5))  == 0);
    static_assert(trunc(fixed8_8(0.9))  == 0);
    static_assert(trunc(fixed8_8(1))    == 1);
    static_assert(trunc(fixed8_8(-0.1)) == 0);
    static_assert(trunc(fixed8_8(-0.5)) == 0);
    static_assert(trunc(fixed8_8(-0.9)) == 0);
    static_assert(trunc(fixed8_8(-1))   == -1);

    static_assert(round(fixed8_8(0))    == 0);
    static_assert(round(fixed8_8(0.1))  == 0);
    static_assert(round(fixed8_8(0.5))  == 1);
    static_assert(round(fixed8_8(0.9))  == 1);
    static_assert(round(fixed8_8(1))    == 1);
    static_assert(round(fixed8_8(-0.1)) == 0);
    static_assert(round(fixed8_8(-0.5)) == -1);
    static_assert(round(fixed8_8(-0.9)) == -1);
    static_assert(round(fixed8_8(-1))   == -1);
#pragma endregion
}
