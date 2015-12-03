cmake_minimum_required(VERSION 3.2)
project(Virtual_Tennis CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt4 REQUIRED QtGui)

add_executable(VirtualTennis main.cpp mainwindow.h mainwindow.cpp gameview.h gameview.cpp gameengine.h gameengine.cpp model.h model.cpp ballobj.h ballobj.cpp paddleobj.h paddleobj.cpp)
target_link_libraries(VirtualTennis Qt4::QtGui)
############ TESTING #################
find_package(Qt4 REQUIRED QtTest)

add_executable(mytest tennistest.cpp mainwindow.h mainwindow.cpp gameview.h gameview.cpp gameengine.h gameengine.cpp model.h model.cpp ballobj.h ballobj.cpp paddleobj.h paddleobj.cpp)
target_link_libraries(mytest Qt4::QtTest Qt4::QtGui)

enable_testing()
add_test(mytest mytest)
