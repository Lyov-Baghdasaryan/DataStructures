#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct PushBackTest
  {
    PushBackTest()
    {
  	  Vector<int> vec;
  	  vec.push_back(1);
  	  vec.push_back(2);
  	  vec.push_back(3);
  
  	  assertEqual(vec.size(), 3, __LINE__, __FILE__);
  	  assertEqual(vec[0], 1, __LINE__, __FILE__);
  	  assertEqual(vec[1], 2, __LINE__, __FILE__);
  	  assertEqual(vec[2], 3, __LINE__, __FILE__);
  
  	  for(std::size_t i = 0; i < 10; ++i)
  		  vec.push_back(7);
  	  
  	  assertEqual(vec.size(), 13, __LINE__, __FILE__);
  	  for(std::size_t i = 3; i < vec.size(); ++i)
  		assertEqual(vec[i], 7, __LINE__, __FILE__);
    }
  };

  static PushBackTest pushBackTest;
}