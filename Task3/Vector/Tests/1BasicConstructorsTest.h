#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct BasicConstructorsTest
  {
    BasicConstructorsTest()
    {
  	  Vector<int> vec1;
  	  Vector<double> vec2(10);
  	  Vector<char> vec3(30, 'x');
  	  
  	  assertEqual(vec1.size(), 0, __LINE__, __FILE__);
  	  assertEqual(vec2.size(), 10, __LINE__, __FILE__);
  	  assertEqual(vec3.size(), 30, __LINE__, __FILE__);
    }
  };
  
  static BasicConstructorsTest basicConstructorsTest;
}