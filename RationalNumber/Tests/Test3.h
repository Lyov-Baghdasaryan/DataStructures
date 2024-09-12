#pragma once
#include "../RationalNumber.h"
#include "Utils/CustomAsserts.h"

namespace test 
{
struct Test3 
{
  Test3() 
  {
    myrn::RationalNumber<int> rationalNumber3(4, 15);
    assertLexicallyEqual(1 + rationalNumber3, "19/15", __LINE__, __FILE__);
    assertLexicallyEqual(3 * rationalNumber3, "4/5", __LINE__, __FILE__);
    assertLexicallyEqual(+rationalNumber3, "4/15", __LINE__, __FILE__);
    assertLexicallyEqual(-rationalNumber3, "-4/15", __LINE__, __FILE__);
  }
};

static Test3 test3;
} // namespace test
