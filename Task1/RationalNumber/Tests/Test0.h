#pragma once
#include "../RationalNumber.h"
#include <iostream>

namespace test
{
struct Test0
{
  Test0() 
  {
    // Represents 4/3.
    myrn::RationalNumber<int> rationalNumber1(4, 3);
    // Represents 5/1.
    myrn::RationalNumber<int> rationalNumber2(5);
    // Represents 0/1
    myrn::RationalNumber<int> rationalNumber3;

    rationalNumber1 += rationalNumber2;
    std::cout << rationalNumber1 << "\n"; // 19/3

    rationalNumber1 -= rationalNumber2;
    std::cout << rationalNumber1 << "\n"; // 4/3

    rationalNumber1 *= rationalNumber2;
    std::cout << rationalNumber1 << "\n"; // 20/3

    rationalNumber1 /= rationalNumber2;
    std::cout << rationalNumber1 << "\n"; // 4/3

    std::cout << rationalNumber3++ << "\n"; // 0/1
    std::cout << ++rationalNumber3 << "\n"; // 2/1
  }
};

static Test0 test0;
} // namespace test
