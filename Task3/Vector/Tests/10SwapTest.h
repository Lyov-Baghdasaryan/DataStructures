#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct SwapTest
  {
    SwapTest()
    {
  	  Vector<int> vec1 = {1, 2, 3};
  	  Vector<int> vec2 = {4, 5};
  
  	  vec1.swap(vec2);
  
  	  assertEqual(vec1.size(), 2, __LINE__, __FILE__);
  	  assertEqual(vec1[0], 4, __LINE__, __FILE__);
  	  assertEqual(vec1[1], 5, __LINE__, __FILE__);
  
  	  assertEqual(vec2.size(), 3, __LINE__, __FILE__);
  	  assertEqual(vec2[0], 1, __LINE__, __FILE__);
  	  assertEqual(vec2[1], 2, __LINE__, __FILE__);
  	  assertEqual(vec2[2], 3, __LINE__, __FILE__);
    }
  };
  
  static SwapTest swapTest;
}