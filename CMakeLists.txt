cmake_minimum_required(VERSION 3.28.3 FATAL_ERROR)
 

set(wxBUILD_SHARED OFF)

project(TakeAwayIDE2)

add_executable(TakeAwayIDE2 WIN32 src/main.cpp)

add_subdirectory(lib/wxWidgets)

target_link_libraries(TakeAwayIDE2 PRIVATE wx::net wx::core wx::base)


