#pragma once

#include <cassert>
#include <iostream>
#include <sstream>

namespace test {

template <typename T1, typename T2>
void assertEqual(const T1 &value, const T2 &expectedValue, int line,
                 char const *file) {
  if (value != expectedValue) {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The expected value was " << expectedValue << ", but got "
              << value << " instead.\n\n";
    std::cerr << "Line: " << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}

template <typename T1, typename T2>
void assertFloatEqual(const T1 &value, const T2 &expectedValue, int line,
                 char const *file) 
{
  static constexpr auto c_precision = 0.00001;
  if (std::abs(value - expectedValue) > c_precision) 
  {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The expected value was " << expectedValue << ", but got "
              << value << " instead.\n\n";
    std::cerr << "Line: " << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}

template <typename T1, typename T2>
void assertGreater(const T1 &value, const T2 &expectedValue, int line,
                   char const *file) {
  if (value <= expectedValue) {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The value was expected to be greater than " << expectedValue
              << ", but was " << value << " instead.\n\n";
    std::cerr << "Line:" << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}

template <typename T1, typename T2>
void assertLess(const T1 &value, const T2 &expectedValue, int line,
                char const *file) {
  if (value >= expectedValue) {
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    std::cerr << "The value was expected to be less than " << expectedValue
              << ", but was " << value << " instead.\n\n";
    std::cerr << "Line:" << line << "\n";
    std::cerr << "File: " << file << "\n";
    std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    assert(false);
  }
}

template <typename T>
void assertLexicallyEqual(const T &actual, const std::string &expected,
                          int line, char const *file) {
  std::stringstream ss;
  ss << actual;
  assertEqual(ss.str(), expected, line, file);
}

void assertBool(bool condition, int line, char const *file);

} // namespace test