#include <iostream>
#include "fixed.hpp"
#include "fixed_math.hpp"

int main()
{
    fpn::fixed8_8 value = 0;
    value += 3.0;
    value *= 2;

    fpn::fixed8_8 sine = fpn::sin(value);
    std::cout << sine << std::endl;
}
