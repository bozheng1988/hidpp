# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build"

# Include any dependencies generated for this target.
include src/tools/CMakeFiles/hidpp20-write-data.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/tools/CMakeFiles/hidpp20-write-data.dir/compiler_depend.make

# Include the progress variables for this target.
include src/tools/CMakeFiles/hidpp20-write-data.dir/progress.make

# Include the compile flags for this target's objects.
include src/tools/CMakeFiles/hidpp20-write-data.dir/flags.make

src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o: src/tools/CMakeFiles/hidpp20-write-data.dir/flags.make
src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o: ../src/tools/hidpp20-write-data.cpp
src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o: src/tools/CMakeFiles/hidpp20-write-data.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o"
	cd "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o -MF CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o.d -o CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o -c "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/src/tools/hidpp20-write-data.cpp"

src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.i"
	cd "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/src/tools/hidpp20-write-data.cpp" > CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.i

src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.s"
	cd "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/src/tools/hidpp20-write-data.cpp" -o CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.s

# Object files for target hidpp20-write-data
hidpp20__write__data_OBJECTS = \
"CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o"

# External object files for target hidpp20-write-data
hidpp20__write__data_EXTERNAL_OBJECTS = \
"/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools/CMakeFiles/common.dir/common/common.cpp.o" \
"/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools/CMakeFiles/common.dir/common/Option.cpp.o" \
"/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools/CMakeFiles/common.dir/common/CommonOptions.cpp.o"

src/tools/hidpp20-write-data: src/tools/CMakeFiles/hidpp20-write-data.dir/hidpp20-write-data.cpp.o
src/tools/hidpp20-write-data: src/tools/CMakeFiles/common.dir/common/common.cpp.o
src/tools/hidpp20-write-data: src/tools/CMakeFiles/common.dir/common/Option.cpp.o
src/tools/hidpp20-write-data: src/tools/CMakeFiles/common.dir/common/CommonOptions.cpp.o
src/tools/hidpp20-write-data: src/tools/CMakeFiles/hidpp20-write-data.dir/build.make
src/tools/hidpp20-write-data: src/libhidpp/libhidpp.dylib
src/tools/hidpp20-write-data: src/tools/CMakeFiles/hidpp20-write-data.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hidpp20-write-data"
	cd "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hidpp20-write-data.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tools/CMakeFiles/hidpp20-write-data.dir/build: src/tools/hidpp20-write-data
.PHONY : src/tools/CMakeFiles/hidpp20-write-data.dir/build

src/tools/CMakeFiles/hidpp20-write-data.dir/clean:
	cd "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools" && $(CMAKE_COMMAND) -P CMakeFiles/hidpp20-write-data.dir/cmake_clean.cmake
.PHONY : src/tools/CMakeFiles/hidpp20-write-data.dir/clean

src/tools/CMakeFiles/hidpp20-write-data.dir/depend:
	cd "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp" "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/src/tools" "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build" "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools" "/Users/Noah/Documents/Projekte/Programmieren/Xcode/Xcode Projekte/Mac Mouse Fix/hidpp/build/src/tools/CMakeFiles/hidpp20-write-data.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/tools/CMakeFiles/hidpp20-write-data.dir/depend

