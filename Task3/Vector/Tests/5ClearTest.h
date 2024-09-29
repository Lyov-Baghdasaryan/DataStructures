#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct ClearTest
  {
    ClearTest()
    {
  	  Vector<int> vec(3, 10);
  	  assertEqual(vec[0], 10, __LINE__, __FILE__);
  	  assertEqual(vec[1], 10, __LINE__, __FILE__);
  	  assertEqual(vec[2], 10, __LINE__, __FILE__);
  	  vec.clear();
  
  	  assertBool(vec.empty(), __LINE__, __FILE__);
    }
  };
  
  static ClearTest clearTest;
}