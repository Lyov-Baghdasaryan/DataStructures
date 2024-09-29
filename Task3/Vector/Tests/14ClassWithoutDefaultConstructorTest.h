#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  
  struct TestClassWithoutDefaultConstructor
  {
    int val1;
    double val2;
    char val3;
    
    TestClassWithoutDefaultConstructor(int val1, double val2, char val3)
      : val1(val1)
      , val2(val2)
      , val3(val3)
    {
    }
  
  };
  
  struct ClassWithoutDefaultConstructorTest
  {
    ClassWithoutDefaultConstructorTest()
    {
  	  Vector<test::TestClassWithoutDefaultConstructor> vec2;
  	  vec2.emplace_back(10, 20.3, 'x');
  	  vec2.push_back(test::TestClassWithoutDefaultConstructor(7, 3.14, 'k'));
  	  vec2.reserve(100);
  
  	  test::assertEqual(vec2.size(), 2, __LINE__, __FILE__);
    }
  };
  
  static ClassWithoutDefaultConstructorTest classWithoutDefaultConstructorTest;
}