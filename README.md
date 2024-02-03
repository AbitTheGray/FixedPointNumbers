# Fixed Point Numbers

![Github Actions](https://github.com/AbitTheGray/FixedPointNumbers/actions/workflows/cmake.yml/badge.svg)

Library to allow working with fixed-point numbers.

## Features

- Fixed-point numbers up to 64-bit total
- Mathematical operations and functions
    - Some implemented using fallback cast to double
    - `constexpr` where possible
- Typedefs for fixed-point GLM vectors and matrices

## Example

```cpp
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
```
