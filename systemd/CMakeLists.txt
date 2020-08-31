cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core WebSockets DBus)

add_executable(
  ${CMAKE_PROJECT_NAME}
  main.cpp
  TestController.cpp
  TestController.h
)
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::WebSockets Qt5::DBus)
