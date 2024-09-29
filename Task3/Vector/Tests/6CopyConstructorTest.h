#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct CopyConstructorTest
  {
    CopyConstructorTest()
    {
  	  Vector<int> vec1 = {1, 2, 3};
  	  Vector<int> vec2(vec1);
  
  	  assertEqual(vec1.size(), vec2.size(), __LINE__, __FILE__);
  	  assertBool(vec1 == vec2, __LINE__, __FILE__);
  
  	  vec1[1] = 10;
  	  assertBool(vec1 != vec2, __LINE__, __FILE__);
  	  assertEqual(vec1[0], 1, __LINE__, __FILE__);
  	  assertEqual(vec1[1], 10, __LINE__, __FILE__);
  	  assertEqual(vec1[2], 3, __LINE__, __FILE__);
  
  	  assertEqual(vec2[0], 1, __LINE__, __FILE__);
  	  assertEqual(vec2[1], 2, __LINE__, __FILE__);
  	  assertEqual(vec2[2], 3, __LINE__, __FILE__);
    }
  };
  
  static CopyConstructorTest copyConstructorTest;
}