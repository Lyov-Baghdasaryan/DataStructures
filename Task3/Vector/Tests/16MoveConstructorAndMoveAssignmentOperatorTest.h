#pragma once
#include "../Vector.h"
#include "Fixtures/CustomAsserts.h"

namespace test
{
  struct TestClassWithOneField
  {
    int val;
    
    TestClassWithOneField(int val)
      : val(val)
    {
    }
    
    TestClassWithOneField(const TestClassWithOneField& other) = delete;
    
    TestClassWithOneField(const TestClassWithOneField&& other)
      : val(other.val)
    {
    }
  
  };
  
  struct MoveConstructorAndMoveAssignmentOperatorTest
  {
    MoveConstructorAndMoveAssignmentOperatorTest()
    {
  	  Vector<test::TestClassWithOneField> vec1;
  	  vec1.emplace_back(1);
  	  vec1.emplace_back(2);
  	  vec1.emplace_back(3);
  	  
  	  // move constructor must be called for the line below.
  	  Vector<test::TestClassWithOneField> vec2(std::move(vec1)); 
  	  assertEqual(vec2[0].val, 1, __LINE__, __FILE__);
  	  assertEqual(vec2[1].val, 2, __LINE__, __FILE__);
  	  assertEqual(vec2[2].val, 3, __LINE__, __FILE__);
  	  
  	  // move assignment operator must be called for the line below.
  	  vec1 = std::move(vec2);  
  	  assertEqual(vec1[0].val, 1, __LINE__, __FILE__);
  	  assertEqual(vec1[1].val, 2, __LINE__, __FILE__);
  	  assertEqual(vec1[2].val, 3, __LINE__, __FILE__);
    }
  };
  
  static MoveConstructorAndMoveAssignmentOperatorTest moveConstructorAndMoveAssignmentOperatorTest;
}