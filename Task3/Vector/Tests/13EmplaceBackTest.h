#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{

  struct TestClassWithDefaultConstructor
  {
    int val1;
    double val2;
    char val3;
  
    TestClassWithDefaultConstructor()
      : val1{}
      , val2{}
      , val3{}
    {
    }
    
    TestClassWithDefaultConstructor(int val1, double val2, char val3)
      : val1(val1)
      , val2(val2)
      , val3(val3)
    {
    }
    
    TestClassWithDefaultConstructor(char val3, int val1)
      : val1(val1)
      , val2(0.)
      , val3(val3)
    {
    }
  
  };
  
  struct EmplaceBackTest
  {
    EmplaceBackTest()
    {
  	  Vector<TestClassWithDefaultConstructor> vec1;
      
  	  vec1.emplace_back(10, 20.3, 'x');
  	  vec1.emplace_back();
  	  vec1.emplace_back('s', 10);
  
  	  assertEqual(vec1.size(), 3, __LINE__, __FILE__);
    }
  };
  
  static EmplaceBackTest emplaceBackTest;
}