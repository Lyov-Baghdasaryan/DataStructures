#pragma once

#include <cassert>
#include <iostream>

namespace test
{

template <typename T1, typename T2>
void assertEqual(const T1& value, const T2& expectedValue, int line, char const* file)
{
  if(value != expectedValue)
  {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The expected value was " << expectedValue << ", but got " << value << " instead.\n\n";
    std::cerr << "Line: " << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}


template <typename T1, typename T2>
void assertGreater(const T1& value, const T2& expectedValue, int line, char const* file)
{
  if(value <= expectedValue)
  {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The value was expected to be greater than " << expectedValue << ", but was " << value << " instead.\n\n";
    std::cerr << "Line:" << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}
  
template <typename T1, typename T2>
void assertLess(const T1& value, const T2& expectedValue, int line, char const* file)
{
  if(value >= expectedValue)
  {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The value was expected to be less than " << expectedValue << ", but was " << value << " instead.\n\n";
    std::cerr << "Line:" << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}

void assertBool(bool condition, int line, char const* file);
  
}// namespace test