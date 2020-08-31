cmake_minimum_required(VERSION 3.5)

project(wsUntitled17 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core WebSockets DBus)

add_executable(wsUntitled17
  main.cpp
  ws.cpp
  wsTxt.cpp
  ws.h
)
target_link_libraries(wsUntitled17 Qt5::Core Qt5::WebSockets Qt5::DBus)
