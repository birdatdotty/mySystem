cmake_minimum_required(VERSION 3.5)

project(untitled16 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets DBus REQUIRED)

add_executable(untitled16
  main.cpp
  MainWindow.cpp
  MainWindow.h
  resource.qrc
  Widget.cpp
  Widget.h
)
target_link_libraries(untitled16 Qt5::Core Qt5::Widgets Qt5::DBus)
