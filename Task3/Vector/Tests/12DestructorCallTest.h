#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct TestClassForDestructor
  {
    std::size_t* destructorCallCounterPtr;
  
    TestClassForDestructor()
      : destructorCallCounterPtr(nullptr)
    {
    }
  
    TestClassForDestructor(std::size_t* destructorCallCounterPtr)
      : destructorCallCounterPtr(destructorCallCounterPtr)
    {
    }
  
    ~TestClassForDestructor()
    {
      if(destructorCallCounterPtr)
        ++(*destructorCallCounterPtr);
    }
  };
  
  struct DestructorCallTest
  {
    DestructorCallTest()
    {
  	  std::size_t destructorCallCounter = 0;
  	  TestClassForDestructor destructorTestClassObj(&destructorCallCounter);
  
  	  // The code below is written between 2 brackets because after this brackets the 
  	  // object `vec` must be destroyed and hence the destructor of vector must be called.
  	  {
  		Vector<TestClassForDestructor> vec(10);
  
  		for(std::size_t i = 0; i < 20; ++i)
  		  vec.push_back(TestClassForDestructor());
  
  		for(std::size_t i = 0; i < vec.size(); ++i)
  		  vec[i] = destructorTestClassObj;
  	  }
  	  assertEqual(destructorCallCounter, 30, __LINE__, __FILE__);
  	  
  	  destructorCallCounter = 0;
  	  
  	  {
  		Vector<TestClassForDestructor> vec(10);
  
  		for(std::size_t i = 0; i < 100; ++i)
  		  vec.push_back(destructorTestClassObj);
  	  }
  	  assertGreater(destructorCallCounter, 100, __LINE__, __FILE__);
  	  assertLess(destructorCallCounter, 1000, __LINE__, __FILE__);
    }
  };
  
  static DestructorCallTest destructorCallTest;
}