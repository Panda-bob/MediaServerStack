# the name of the project
project(mediaserver)

cmake_minimum_required(VERSION 2.8)

# find and setup threads library for the project
find_package(Threads)

# Set verbose output to make
#set(CMAKE_VERBOSE_MAKEFILE ON)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON) 

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
     set(CMAKE_CXX_FLAGS "-g -std=gnu++11")
     ADD_DEFINITIONS(-DGNU -D_GNU_SOURCE -D_REENTRANT -DSOCKLEN_T=socklen_t -DNO_SSTREAM=1 -DLARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES Windows)
	ADD_DEFINITIONS(/D"WIN32" /D"_WINDOWS")
	set(CMAKE_CXX_FLAGS "/EHsc /MP")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/Zi /Od /Ob0 /FR")
	set(CMAKE_C_FLAGS_RELWITHDEBINFO "/Zi /Od /Ob0 /FR")
	set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "/debug /INCREMENTAL:NO")
	set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/debug /INCREMENTAL:NO")
endif()

if (UNIX)
	ADD_DEFINITIONS(-g)
	#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
	SET(MAJOR_VERSION 1)
	SET(MINOR_VERSION 0)
	SET(PATCH_VERSION 0)
	SET(CPACK_GENERATOR "DEB")
	SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
	SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
	SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
	SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6)")
	SET(CPACK_PACKAGE_DESCRIPTION "media service")
	SET(CPACK_PACKAGE_CONTACT "support@panda.com")
	SET(CPACK_PACK_FILE_NAME)
	#include(CPack)	
endif (UNIX)

# tell cmake to process CMakeLists.txt in the subdirectories
#add_subdirectory(test)
add_subdirectory(jrtplib)
#add_subdirectory(rtpransferformat)
#add_subdirectory(log)
#add_subdirectory(watchdog)

#cpack files and install
if (UNIX)
	#SET(LIBS_DIR "$ENV{DBXML_DIR}/lib")
	#INSTALL(FILES ${CMAKE_SOURCE_DIR}/n-mix-cc.conf DESTINATION /etc/init)
	#INSTALL(FILES ${LIBS_DIR}/libdb-4.8.so ${LIBS_DIR}/libdbxml-2.5.so ${LIBS_DIR}/libxerces-c-3.0.so ${LIBS_DIR}/libxqilla.so.5 ${LIBS_DIR}/libxqilla.so.5.0.2  DESTINATION /usr/lib)
	#SET(LIBS_DIR "$ENV{DBXML_DIR}/lib")
	#INSTALL(FILES ${CMAKE_SOURCE_DIR}/cfg/n-mix-cc.conf DESTINATION /etc/init)
	#INSTALL(FILES ${LIBS_DIR}/libdb-6.1.so ${LIBS_DIR}/libdb-6.so ${LIBS_DIR}/libdb_cxx-6.1.so ${LIBS_DIR}/libdb_cxx-6.so ${LIBS_DIR}/libdb_cxx.so ${LIBS_DIR}/libdb.so  ${LIBS_DIR}/libdbxml.so ${LIBS_DIR}/libdbxml-6.0.so ${LIBS_DIR}/libxerces-c-3.1.so ${LIBS_DIR}/libxerces-c.so ${LIBS_DIR}/libxqilla.so.6.0.0 ${LIBS_DIR}/libxqilla.so.6 ${LIBS_DIR}/libxqilla.so DESTINATION /usr/lib)
endif (UNIX)

