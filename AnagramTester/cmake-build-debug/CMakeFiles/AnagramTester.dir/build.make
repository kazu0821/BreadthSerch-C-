# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kazukikanke/CLionProjects/AnagramTester

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AnagramTester.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AnagramTester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AnagramTester.dir/flags.make

CMakeFiles/AnagramTester.dir/main.cpp.o: CMakeFiles/AnagramTester.dir/flags.make
CMakeFiles/AnagramTester.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AnagramTester.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AnagramTester.dir/main.cpp.o -c /Users/kazukikanke/CLionProjects/AnagramTester/main.cpp

CMakeFiles/AnagramTester.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnagramTester.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kazukikanke/CLionProjects/AnagramTester/main.cpp > CMakeFiles/AnagramTester.dir/main.cpp.i

CMakeFiles/AnagramTester.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnagramTester.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kazukikanke/CLionProjects/AnagramTester/main.cpp -o CMakeFiles/AnagramTester.dir/main.cpp.s

# Object files for target AnagramTester
AnagramTester_OBJECTS = \
"CMakeFiles/AnagramTester.dir/main.cpp.o"

# External object files for target AnagramTester
AnagramTester_EXTERNAL_OBJECTS =

AnagramTester: CMakeFiles/AnagramTester.dir/main.cpp.o
AnagramTester: CMakeFiles/AnagramTester.dir/build.make
AnagramTester: CMakeFiles/AnagramTester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AnagramTester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AnagramTester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AnagramTester.dir/build: AnagramTester

.PHONY : CMakeFiles/AnagramTester.dir/build

CMakeFiles/AnagramTester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AnagramTester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AnagramTester.dir/clean

CMakeFiles/AnagramTester.dir/depend:
	cd /Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kazukikanke/CLionProjects/AnagramTester /Users/kazukikanke/CLionProjects/AnagramTester /Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug /Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug /Users/kazukikanke/CLionProjects/AnagramTester/cmake-build-debug/CMakeFiles/AnagramTester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AnagramTester.dir/depend

