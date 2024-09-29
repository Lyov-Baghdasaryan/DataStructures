#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct AccessFunctionsTest
  {
    AccessFunctionsTest()
    {
  	  Vector<int> vec = {1, 2, 3};
  
  	  assertEqual(vec.at(0), 1, __LINE__, __FILE__);
  	  assertEqual(vec[1], 2, __LINE__, __FILE__);
  	  assertEqual(vec.front(), 1, __LINE__, __FILE__);
  	  assertEqual(vec.back(), 3, __LINE__, __FILE__);
  
  	  vec.at(1) = 7;
  	  vec.front() = 0;
  	  vec.back() = 4;
  	  assertEqual(vec[0], 0, __LINE__, __FILE__);
  	  assertEqual(vec[1], 7, __LINE__, __FILE__);
  	  assertEqual(vec[2], 4, __LINE__, __FILE__);
  
  	  int* data_ptr = vec.data();
  	  assertEqual(data_ptr[0], 0, __LINE__, __FILE__);
  	  assertEqual(data_ptr[1], 7, __LINE__, __FILE__);
  	  assertEqual(data_ptr[2], 4, __LINE__, __FILE__);
    }
  };
  
  static AccessFunctionsTest accessFunctionsTest;
}