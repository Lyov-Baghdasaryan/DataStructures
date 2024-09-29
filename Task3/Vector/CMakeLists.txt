cmake_minimum_required(VERSION 3.29)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Tests)
include_directories(Tests/Fixtures)

add_executable(Vector
    Tests/Fixtures/CustomAsserts.cpp
    Tests/Fixtures/CustomAsserts.h
    Tests/10SwapTest.h
    Tests/11SubscriptOperatorTest.h:w
    Tests/12DestructorCallTest.h
    Tests/13EmplaceBackTest.h
    Tests/14ClassWithoutDefaultConstructorTest.h
    Tests/15ClassWithoutCopyConstructorTest.h
    Tests/16MoveConstructorAndMoveAssignmentOperatorTest.h
    Tests/1BasicConstructorsTest.h
    Tests/2InitializerListConstructorTest.h
    Tests/3PushBackTest.h
    Tests/4PopBackTest.h
    Tests/5ClearTest.h
    Tests/6CopyConstructorTest.h
    Tests/7AssignmentOperatorTest.h
    Tests/8AccessFunctionsTest.h
    Tests/9ReserveAndShrinkToFitTest.h
    main.cpp
    Vector.h)
