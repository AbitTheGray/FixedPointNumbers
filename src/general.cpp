#include "fixed.hpp"

namespace fpn
{
#pragma region Basic constructor tests
    static_assert(fixed8_8() == 0);

    static_assert(fixed8_8(0)   == 0);
    static_assert(fixed8_8(1)   == 1);
    static_assert(fixed8_8(2)   == 2);
    static_assert(fixed8_8(-1)  == -1);
    static_assert(-fixed8_8(1)  == fixed8_8(-1));
    static_assert(-fixed8_8(1)  == -1);
    static_assert(-fixed8_8(-1) == 1);

    static_assert(fixed8_8(0u) == 0);
    static_assert(fixed8_8(1u) == 1);
    static_assert(fixed8_8(2u) == 2);
#pragma endregion

#pragma region Integral + Fractional Values
    static_assert(fixed8_8( 0  ).IntegralValue().operator double() ==  0);
    static_assert(fixed8_8( 1  ).IntegralValue().operator double() ==  1);
    static_assert(fixed8_8( 2  ).IntegralValue().operator double() ==  2);
    static_assert(fixed8_8(-1  ).IntegralValue().operator double() == -1);
    static_assert(fixed8_8(-2  ).IntegralValue().operator double() == -2);
#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.5).IntegralValue().operator double() ==  0);
    static_assert(fixed8_8( 1.5).IntegralValue().operator double() ==  1);
    static_assert(fixed8_8( 2.5).IntegralValue().operator double() ==  2);
    static_assert(fixed8_8(-1.5).IntegralValue().operator double() == -2);
    static_assert(fixed8_8(-2.5).IntegralValue().operator double() == -3);

    static_assert(fixed8_8( 0.0  ).FractionalValue().operator double() == 0.0);
    static_assert(fixed8_8( 0.125).FractionalValue().operator double() == 0.125);
    static_assert(fixed8_8( 0.5  ).FractionalValue().operator double() == 0.5);
    static_assert(fixed8_8( 0.875).FractionalValue().operator double() == 0.875);
    static_assert(fixed8_8( 1.0  ).FractionalValue().operator double() == 0.0);
    static_assert(fixed8_8(-0.125).FractionalValue().operator double() == 0.875);
    static_assert(fixed8_8(-0.5  ).FractionalValue().operator double() == 0.5);
    static_assert(fixed8_8(-0.875).FractionalValue().operator double() == 0.125);
    static_assert(fixed8_8(-1.0  ).FractionalValue().operator double() == 0.0);
#endif
#pragma endregion
#pragma region Integral + Fractional Parts
    static_assert(fixed8_8( 0).IntegralPart() ==  0);
    static_assert(fixed8_8( 1).IntegralPart() ==  1);
    static_assert(fixed8_8( 2).IntegralPart() ==  2);
    static_assert(fixed8_8(-1).IntegralPart() == -1);
    static_assert(fixed8_8(-2).IntegralPart() == -2);
#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( 0.5).IntegralPart() ==  0);
    static_assert(fixed8_8( 1.5).IntegralPart() ==  1);
    static_assert(fixed8_8( 2.5).IntegralPart() ==  2);
    static_assert(fixed8_8(-1.5).IntegralPart() == -2);
    static_assert(fixed8_8(-2.5).IntegralPart() == -3);

    static_assert(fixed8_8( 0.0  ).FractionalPart() == 0);
    static_assert(fixed8_8( 0.125).FractionalPart() == 32);
    static_assert(fixed8_8( 0.5  ).FractionalPart() == 128);
    static_assert(fixed8_8( 0.875).FractionalPart() == 224);
    static_assert(fixed8_8( 1.0  ).FractionalPart() == 0);
    static_assert(fixed8_8(-0.125).FractionalPart() == 224);
    static_assert(fixed8_8(-0.5  ).FractionalPart() == 128);
    static_assert(fixed8_8(-0.875).FractionalPart() == 32);
    static_assert(fixed8_8(-1.0  ).FractionalPart() == 0);
#endif
#pragma endregion
#pragma region Integral + Fractional Constructor
    static_assert(fixed8_8( fixed8_8( 0).IntegralPart(), fixed8_8( 0).FractionalPart()) ==  0);
    static_assert(fixed8_8( fixed8_8( 1).IntegralPart(), fixed8_8( 1).FractionalPart()) ==  1);
    static_assert(fixed8_8( fixed8_8( 2).IntegralPart(), fixed8_8( 2).FractionalPart()) ==  2);
    static_assert(fixed8_8( fixed8_8(-1).IntegralPart(), fixed8_8(-1).FractionalPart()) == -1);
    static_assert(fixed8_8( fixed8_8(-2).IntegralPart(), fixed8_8(-2).FractionalPart()) == -2);
#if FPN_CONSTEXPR_HAS == 1
    static_assert(fixed8_8( fixed8_8( 0.5).IntegralPart(), fixed8_8( 0.5).FractionalPart()) ==  0.5);
    static_assert(fixed8_8( fixed8_8( 1.5).IntegralPart(), fixed8_8( 1.5).FractionalPart()) ==  1.5);
    static_assert(fixed8_8( fixed8_8( 2.5).IntegralPart(), fixed8_8( 2.5).FractionalPart()) ==  2.5);
    static_assert(fixed8_8( fixed8_8(-1.5).IntegralPart(), fixed8_8(-1.5).FractionalPart()) == -1.5);
    static_assert(fixed8_8( fixed8_8(-2.5).IntegralPart(), fixed8_8(-2.5).FractionalPart()) == -2.5);

    static_assert(fixed8_8( fixed8_8( 0.0  ).IntegralPart(), fixed8_8( 0.0  ).FractionalPart()) ==  0.0  );
    static_assert(fixed8_8( fixed8_8( 0.125).IntegralPart(), fixed8_8( 0.125).FractionalPart()) ==  0.125);
    static_assert(fixed8_8( fixed8_8( 0.5  ).IntegralPart(), fixed8_8( 0.5  ).FractionalPart()) ==  0.5  );
    static_assert(fixed8_8( fixed8_8( 0.875).IntegralPart(), fixed8_8( 0.875).FractionalPart()) ==  0.875);
    static_assert(fixed8_8( fixed8_8( 1.0  ).IntegralPart(), fixed8_8( 1.0  ).FractionalPart()) ==  1.0  );
    static_assert(fixed8_8( fixed8_8(-0.125).IntegralPart(), fixed8_8(-0.125).FractionalPart()) == -0.125);
    static_assert(fixed8_8( fixed8_8(-0.5  ).IntegralPart(), fixed8_8(-0.5  ).FractionalPart()) == -0.5  );
    static_assert(fixed8_8( fixed8_8(-0.875).IntegralPart(), fixed8_8(-0.875).FractionalPart()) == -0.875);
    static_assert(fixed8_8( fixed8_8(-1.0  ).IntegralPart(), fixed8_8(-1.0  ).FractionalPart()) == -1.0  );
#endif
#pragma endregion

#pragma region Min + Max values
    static_assert(fixed8_8::MinValue().IntegralValue() == -128);
    static_assert(fixed8_8::MaxValue().IntegralValue() == 127);

    static_assert(fixed8_8::MinValue().operator double() == -128);

    static_assert(fixed8_8::MaxValue().operator double() > 127.9);
    static_assert(fixed8_8::MaxValue().operator double() < 128);

    static_assert(fixed<8, 1>::MinIncrement().operator double() == 0.5);
    static_assert(fixed<8, 2>::MinIncrement().operator double() == 0.25);
    static_assert(fixed<8, 3>::MinIncrement().operator double() == 0.125);
    static_assert(fixed<8, 4>::MinIncrement().operator double() == 0.0625);
    static_assert(fixed<8, 5>::MinIncrement().operator double() == 0.03125);
    static_assert(fixed<8, 6>::MinIncrement().operator double() == 0.015625);
    static_assert(fixed<8, 7>::MinIncrement().operator double() == 0.0078125);
    static_assert(fixed<8, 8>::MinIncrement().operator double() == 0.00390625);
#pragma endregion

#pragma region Hashes
    static_assert(std::hash<fixed8_8>{}(fixed8_8{0}) == 0);
    static_assert(std::hash<fixed8_8>{}(fixed8_8{1}) == 1 << 8);
    static_assert(std::hash<fixed8_8>{}(fixed8_8{2}) == 2 << 8);

    static_assert(std::hash<fixed8_16>{}(fixed8_16{0}) == 0 << 16);
    static_assert(std::hash<fixed8_16>{}(fixed8_16{1}) == 1 << 16);
    static_assert(std::hash<fixed8_16>{}(fixed8_16{2}) == 2 << 16);

    static_assert(std::hash<fixed16_8>{}(fixed16_8{0}) == 0 << 8);
    static_assert(std::hash<fixed16_8>{}(fixed16_8{1}) == 1 << 8);
    static_assert(std::hash<fixed16_8>{}(fixed16_8{2}) == 2 << 8);
#pragma endregion
}
