#pragma once
#include "../RationalNumber.h"
#include "Utils/CustomAsserts.h"

namespace test 
{
struct Test7 
{
  Test7() {
    myrn::RationalNumber<int> rationalNumber8(399999999, 1000010197);
    myrn::RationalNumber<int> rationalNumber9(1199999997, 2000020394);
    assertLexicallyEqual(rationalNumber8 + rationalNumber9, "1999999995/2000020394", __LINE__, __FILE__);

    myrn::RationalNumber<unsigned long long> rationalNumber10(2305843009213693951, 1000010197);
    myrn::RationalNumber<unsigned long long> rationalNumber11(2000020394, 2305843009213693951);
    assertLexicallyEqual(rationalNumber10 * rationalNumber11, "2/1", __LINE__, __FILE__);
  }
};

static Test7 test7;
} // namespace test
