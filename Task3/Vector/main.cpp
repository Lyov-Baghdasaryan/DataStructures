/*
The tests are made via header files. When you include the header file the corresponding test starts to execute. Feel free to comment the corresponding "#include <Header.h>" to ensure that it will not compile during your test.

All your code must be in "Vector.h"
*/

#include "Tests/1BasicConstructorsTest.h"
#include "Tests/2InitializerListConstructorTest.h"
#include "Tests/3PushBackTest.h"
#include "Tests/4PopBackTest.h"
#include "Tests/5ClearTest.h"
#include "Tests/6CopyConstructorTest.h"
#include "Tests/7AssignmentOperatorTest.h"
#include "Tests/8AccessFunctionsTest.h"
#include "Tests/9ReserveAndShrinkToFitTest.h"
#include "Tests/10SwapTest.h"
#include "Tests/11SubscriptOperatorTest.h"
#include "Tests/12DestructorCallTest.h"
//#include "Tests/13EmplaceBackTest.h"
// #include "Tests/13EmplaceBackTest.h"    <---- For example if you don't want this bad boy to be executed just don't include it.
//#include "Tests/14ClassWithoutDefaultConstructorTest.h"
//#include "Tests/15ClassWithoutCopyConstructorTest.h"
//#include "Tests/16MoveConstructorAndMoveAssignmentOperatorTest.h"

#include "Vector.h"
#include <iostream>

int main() 
{

  std::cout << "All tests passed!";
  return 0;
}
