# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/panda/workspace/JThread-1.3.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/panda/workspace/JThread-1.3.3/build

# Include any dependencies generated for this target.
include src/CMakeFiles/jthread-shared.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/jthread-shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/jthread-shared.dir/flags.make

src/CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.o: src/CMakeFiles/jthread-shared.dir/flags.make
src/CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.o: ../src/pthread/jmutex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panda/workspace/JThread-1.3.3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.o"
	cd /home/panda/workspace/JThread-1.3.3/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.o -c /home/panda/workspace/JThread-1.3.3/src/pthread/jmutex.cpp

src/CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.i"
	cd /home/panda/workspace/JThread-1.3.3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/panda/workspace/JThread-1.3.3/src/pthread/jmutex.cpp > CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.i

src/CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.s"
	cd /home/panda/workspace/JThread-1.3.3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/panda/workspace/JThread-1.3.3/src/pthread/jmutex.cpp -o CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.s

src/CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.o: src/CMakeFiles/jthread-shared.dir/flags.make
src/CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.o: ../src/pthread/jthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/panda/workspace/JThread-1.3.3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.o"
	cd /home/panda/workspace/JThread-1.3.3/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.o -c /home/panda/workspace/JThread-1.3.3/src/pthread/jthread.cpp

src/CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.i"
	cd /home/panda/workspace/JThread-1.3.3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/panda/workspace/JThread-1.3.3/src/pthread/jthread.cpp > CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.i

src/CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.s"
	cd /home/panda/workspace/JThread-1.3.3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/panda/workspace/JThread-1.3.3/src/pthread/jthread.cpp -o CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.s

# Object files for target jthread-shared
jthread__shared_OBJECTS = \
"CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.o" \
"CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.o"

# External object files for target jthread-shared
jthread__shared_EXTERNAL_OBJECTS =

src/libjthread.so.1.3.3: src/CMakeFiles/jthread-shared.dir/pthread/jmutex.cpp.o
src/libjthread.so.1.3.3: src/CMakeFiles/jthread-shared.dir/pthread/jthread.cpp.o
src/libjthread.so.1.3.3: src/CMakeFiles/jthread-shared.dir/build.make
src/libjthread.so.1.3.3: src/CMakeFiles/jthread-shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/panda/workspace/JThread-1.3.3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libjthread.so"
	cd /home/panda/workspace/JThread-1.3.3/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jthread-shared.dir/link.txt --verbose=$(VERBOSE)
	cd /home/panda/workspace/JThread-1.3.3/build/src && $(CMAKE_COMMAND) -E cmake_symlink_library libjthread.so.1.3.3 libjthread.so.1.3.3 libjthread.so

src/libjthread.so: src/libjthread.so.1.3.3
	@$(CMAKE_COMMAND) -E touch_nocreate src/libjthread.so

# Rule to build all files generated by this target.
src/CMakeFiles/jthread-shared.dir/build: src/libjthread.so

.PHONY : src/CMakeFiles/jthread-shared.dir/build

src/CMakeFiles/jthread-shared.dir/clean:
	cd /home/panda/workspace/JThread-1.3.3/build/src && $(CMAKE_COMMAND) -P CMakeFiles/jthread-shared.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/jthread-shared.dir/clean

src/CMakeFiles/jthread-shared.dir/depend:
	cd /home/panda/workspace/JThread-1.3.3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/panda/workspace/JThread-1.3.3 /home/panda/workspace/JThread-1.3.3/src /home/panda/workspace/JThread-1.3.3/build /home/panda/workspace/JThread-1.3.3/build/src /home/panda/workspace/JThread-1.3.3/build/src/CMakeFiles/jthread-shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/jthread-shared.dir/depend

