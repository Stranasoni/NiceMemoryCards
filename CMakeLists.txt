cmake_minimum_required(VERSION 3.28.3 FATAL_ERROR)
 

set(wxBUILD_SHARED OFF)

project(MemoryCards)

add_executable(MemoryCards WIN32 src/main.cpp src/mainFrame.cpp src/mainFrame.h usefulClasses/myRandom.cpp usefulClasses/myRandom.h  )

add_subdirectory(lib/wxWidgets)


target_link_libraries(MemoryCards PRIVATE wx::net wx::core wx::base)


