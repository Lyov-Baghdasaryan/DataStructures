#pragma once
#include "../RationalNumber.h"
#include "Utils/CustomAsserts.h"

namespace test 
{
struct Test1 
{
  Test1() 
  {
    // Represents 4/3.
    myrn::RationalNumber<int> rationalNumber1(4, 3);
    // Represents 5/1.
    myrn::RationalNumber<int> rationalNumber2(5);
    // Represents 0/1
    myrn::RationalNumber<int> rationalNumber3;

    rationalNumber1 += rationalNumber2;
    assertLexicallyEqual(rationalNumber1, "19/3", __LINE__, __FILE__);

    rationalNumber1 -= rationalNumber2;
    assertLexicallyEqual(rationalNumber1, "4/3", __LINE__, __FILE__);

    rationalNumber1 *= rationalNumber2;
    assertLexicallyEqual(rationalNumber1, "20/3", __LINE__, __FILE__);

    rationalNumber1 /= rationalNumber2;
    assertLexicallyEqual(rationalNumber1, "4/3", __LINE__, __FILE__);

    assertLexicallyEqual(rationalNumber3++, "0/1", __LINE__, __FILE__);
    assertLexicallyEqual(++rationalNumber3, "2/1", __LINE__, __FILE__);
  }
};

static Test1 test1;
} // namespace test
