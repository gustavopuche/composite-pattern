cmake_minimum_required(VERSION 3.15)
project( composite )
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable( composite composite.cpp )
add_custom_target(run)
# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (composite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( TARGET run
	POST_BUILD COMMAND ./composite)
