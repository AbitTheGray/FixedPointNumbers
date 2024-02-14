#include "fixed.hpp"

namespace fpn
{
    static_assert(fixed8_8("0") == fixed8_8(0));

    static_assert(fixed8_8("1")     == fixed8_8(  1));
    static_assert(fixed8_8("2")     == fixed8_8(  2));
    static_assert(fixed8_8("3")     == fixed8_8(  3));
    static_assert(fixed8_8("10")    == fixed8_8( 10));
    static_assert(fixed8_8("127")   == fixed8_8(127));
    static_assert(fixed8_8("1'0")   == fixed8_8( 10));
    static_assert(fixed8_8("1'2'7") == fixed8_8(127));

    static_assert(fixed8_8("0.5").operator double() == fixed8_8(0.5).operator double());
    static_assert(fixed8_8("0.25").operator double() == fixed8_8(0.25).operator double());
    static_assert(fixed8_8("0.125").operator double() == fixed8_8(0.125).operator double());
    static_assert(fixed8_8("0.0625").operator double() == fixed8_8(0.0625).operator double());

    static_assert(fixed8_8("0.5")          == fixed8_8(0.5));
    static_assert(fixed8_8("0.25")         == fixed8_8(0.25));
    static_assert(fixed8_8("0.125")        == fixed8_8(0.125));
    static_assert(fixed8_8("0.0625")       == fixed8_8(0.0625));
    static_assert(fixed8_8("0.03125")      == fixed8_8(0.03125));
    static_assert(fixed8_8("0.015625")     == fixed8_8(0.015625));
    static_assert(fixed8_8("0.0078125")    == fixed8_8(0.0078125));
    static_assert(fixed8_8("0.00390625")   == fixed8_8(0.00390625));

    static_assert(fixed8_8(".5")           == fixed8_8(0.5));
    static_assert(fixed8_8(".25")          == fixed8_8(0.25));
    static_assert(fixed8_8(".125")         == fixed8_8(0.125));
    static_assert(fixed8_8(".0625")        == fixed8_8(0.0625));
    static_assert(fixed8_8(".03125")       == fixed8_8(0.03125));
    static_assert(fixed8_8(".015625")      == fixed8_8(0.015625));
    static_assert(fixed8_8(".0078125")     == fixed8_8(0.0078125));
    static_assert(fixed8_8(".00390625")    == fixed8_8(0.00390625));

    static_assert(fixed8_8("0.5")          == fixed8_8(0.5));
    static_assert(fixed8_8("0.25")         == fixed8_8(0.25));
    static_assert(fixed8_8("0.125")        == fixed8_8(0.125));
    static_assert(fixed8_8("0.062'5")      == fixed8_8(0.0625));
    static_assert(fixed8_8("0.031'25")     == fixed8_8(0.03125));
    static_assert(fixed8_8("0.015'625")    == fixed8_8(0.015625));
    static_assert(fixed8_8("0.007'812'5")  == fixed8_8(0.0078125));
    static_assert(fixed8_8("0.003'906'25") == fixed8_8(0.00390625));

    static_assert(fixed8_8("1.5")          == fixed8_8(1.5));
    static_assert(fixed8_8("1.25")         == fixed8_8(1.25));
    static_assert(fixed8_8("1.125")        == fixed8_8(1.125));
    static_assert(fixed8_8("1.062'5")      == fixed8_8(1.0625));
    static_assert(fixed8_8("1.031'25")     == fixed8_8(1.03125));
    static_assert(fixed8_8("1.015'625")    == fixed8_8(1.015625));
    static_assert(fixed8_8("1.007'812'5")  == fixed8_8(1.0078125));
    static_assert(fixed8_8("1.003'906'25") == fixed8_8(1.00390625));

    static_assert(fixed8_8("12.5")          == fixed8_8(12.5));
    static_assert(fixed8_8("12.25")         == fixed8_8(12.25));
    static_assert(fixed8_8("12.125")        == fixed8_8(12.125));
    static_assert(fixed8_8("12.062'5")      == fixed8_8(12.0625));
    static_assert(fixed8_8("12.031'25")     == fixed8_8(12.03125));
    static_assert(fixed8_8("12.015'625")    == fixed8_8(12.015625));
    static_assert(fixed8_8("12.007'812'5")  == fixed8_8(12.0078125));
    static_assert(fixed8_8("12.003'906'25") == fixed8_8(12.00390625));

    static_assert(fixed8_8("0.515'625")     == fixed8_8(0.515625));

    static_assert(fixed8_8("0.5")           == fixed8_8(0.500000001));
}
