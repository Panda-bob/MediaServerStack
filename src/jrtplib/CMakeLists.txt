# the name of the project
project(jrtplib)

cmake_minimum_required(VERSION 2.8)

# find and setup threads library for the project
find_package(Threads)

# Set verbose output to make
#set(CMAKE_VERBOSE_MAKEFILE ON)

set(JTHREAD_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/jrtplib/jthread/src")

set(JTHREAD_LIBRARIES ${CMAKE_SOURCE_DIR}/jrtplib/jthread/src)

# Set defines
if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
	ADD_DEFINITIONS(-DGNU -D_GNU_SOURCE -D_REENTRANT -DSOCKLEN_T=socklen_t -DNO_SSTREAM=1 -DLARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64)
endif()

# tell cmake to process CMakeLists.txt in the subdirectories

add_subdirectory(jthread)
add_subdirectory(jrtplib)