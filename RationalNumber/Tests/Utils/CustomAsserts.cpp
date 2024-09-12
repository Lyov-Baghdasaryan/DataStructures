#include "CustomAsserts.h"

namespace test
{
  void assertBool(bool condition, int line, char const* file)
  {
    if(!condition)
    {
      std::cerr << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
      std::cerr << "The condition was expected to be true, but was false instead.\n\n";
      std::cerr << "Line: " << line << "\n";
    std::cerr << "File: " << file << "\n";
      std::cerr << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
      assert(false);
    }
  }
  
}// namespace test