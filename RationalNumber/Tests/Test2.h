#pragma once
#include "../RationalNumber.h"
#include "Utils/CustomAsserts.h"

namespace test 
{
struct Test2 
{
  Test2() 
  {
    myrn::RationalNumber<int> rationalNumber1(4, 3);
    myrn::RationalNumber<int> rationalNumber2(5);
    myrn::RationalNumber<int> rationalNumber3;

    rationalNumber3 = rationalNumber1 + rationalNumber2; 
    assertLexicallyEqual(rationalNumber3, "19/3", __LINE__, __FILE__);

    rationalNumber3 = rationalNumber1 - rationalNumber2;
    assertLexicallyEqual(rationalNumber3, "-11/3", __LINE__, __FILE__);

    rationalNumber3 = rationalNumber1 * rationalNumber2;
    assertLexicallyEqual(rationalNumber3, "20/3", __LINE__, __FILE__);

    rationalNumber3 = rationalNumber1 / rationalNumber2;
    assertLexicallyEqual(rationalNumber3, "4/15", __LINE__, __FILE__);
  }
};

static Test2 test2;
} // namespace test
