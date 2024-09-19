#pragma once
#include "../RationalNumber.h"
#include "Utils/CustomAsserts.h"

namespace test 
{
struct Test8 
{
  Test8()
  {
    // literals must be a namespace inside yourname namespace.
    using namespace myrn::literals;

    // In order to understand this part read about user-defined literals.
    myrn::RationalNumber<unsigned long long> rationalNumber12 = 10_r;
    myrn::RationalNumber<unsigned long long> rationalNumber13 = 7_r / 8_r;
    assertLexicallyEqual(rationalNumber12, "10/1", __LINE__, __FILE__);
    assertLexicallyEqual(rationalNumber13, "7/8", __LINE__, __FILE__);

    auto rationalNumber14 = 7_r / 5_r;
    auto rationalNumber15 = 2_r / 10_r;
    assertEqual(rationalNumber14 + rationalNumber15, 8_r / 5_r, __LINE__, __FILE__);
  }
};

static Test8 test8;
} // namespace test
