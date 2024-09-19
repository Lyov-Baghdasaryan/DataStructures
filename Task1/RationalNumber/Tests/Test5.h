#pragma once
#include "../RationalNumber.h"
#include "Utils/CustomAsserts.h"

namespace test 
{
struct Test5
{
  Test5()
  {
    myrn::RationalNumber<int> rationalNumber4(10, 120);
    myrn::RationalNumber<int> rationalNumber5(-7, -2);
    myrn::RationalNumber<int> rationalNumber6(-5, 4);
    myrn::RationalNumber<int> rationalNumber7(9, -10);

    assertLexicallyEqual(rationalNumber4, "1/12", __LINE__, __FILE__);
    assertLexicallyEqual(rationalNumber5, "7/2", __LINE__, __FILE__);
    assertLexicallyEqual(rationalNumber6, "-5/4", __LINE__, __FILE__);
    assertLexicallyEqual(rationalNumber7, "-9/10", __LINE__, __FILE__);
  }
};

static Test5 test5;
} // namespace test
