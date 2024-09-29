#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct PopBackTest
  {
    PopBackTest()
    {
  	  Vector<int> vec{1, 2, 3};
  	  vec.pop_back();
  	  
  	  assertEqual(vec.size(), 2, __LINE__, __FILE__);
  	  assertEqual(vec[0], 1, __LINE__, __FILE__);
  	  assertEqual(vec[1], 2, __LINE__, __FILE__);
    }
  };
  
  static PopBackTest popBackTest;
}