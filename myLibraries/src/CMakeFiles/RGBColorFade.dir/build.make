# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /common/workspaces/arduino/myLibraries/RGBColorFade

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /common/workspaces/arduino/myLibraries

# Include any dependencies generated for this target.
include src/CMakeFiles/RGBColorFade.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/RGBColorFade.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/RGBColorFade.dir/flags.make

src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o: src/CMakeFiles/RGBColorFade.dir/flags.make
src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o: RGBColorFade/src/RGBColorFader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/common/workspaces/arduino/myLibraries/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o"
	cd /common/workspaces/arduino/myLibraries/src && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o -c /common/workspaces/arduino/myLibraries/RGBColorFade/src/RGBColorFader.cpp

src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.i"
	cd /common/workspaces/arduino/myLibraries/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /common/workspaces/arduino/myLibraries/RGBColorFade/src/RGBColorFader.cpp > CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.i

src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.s"
	cd /common/workspaces/arduino/myLibraries/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /common/workspaces/arduino/myLibraries/RGBColorFade/src/RGBColorFader.cpp -o CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.s

src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.requires:

.PHONY : src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.requires

src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.provides: src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RGBColorFade.dir/build.make src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.provides.build
.PHONY : src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.provides

src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.provides.build: src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o


# Object files for target RGBColorFade
RGBColorFade_OBJECTS = \
"CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o"

# External object files for target RGBColorFade
RGBColorFade_EXTERNAL_OBJECTS =

src/libRGBColorFade.a: src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o
src/libRGBColorFade.a: src/CMakeFiles/RGBColorFade.dir/build.make
src/libRGBColorFade.a: src/CMakeFiles/RGBColorFade.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/common/workspaces/arduino/myLibraries/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRGBColorFade.a"
	cd /common/workspaces/arduino/myLibraries/src && $(CMAKE_COMMAND) -P CMakeFiles/RGBColorFade.dir/cmake_clean_target.cmake
	cd /common/workspaces/arduino/myLibraries/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RGBColorFade.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/RGBColorFade.dir/build: src/libRGBColorFade.a

.PHONY : src/CMakeFiles/RGBColorFade.dir/build

src/CMakeFiles/RGBColorFade.dir/requires: src/CMakeFiles/RGBColorFade.dir/RGBColorFader.cpp.o.requires

.PHONY : src/CMakeFiles/RGBColorFade.dir/requires

src/CMakeFiles/RGBColorFade.dir/clean:
	cd /common/workspaces/arduino/myLibraries/src && $(CMAKE_COMMAND) -P CMakeFiles/RGBColorFade.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/RGBColorFade.dir/clean

src/CMakeFiles/RGBColorFade.dir/depend:
	cd /common/workspaces/arduino/myLibraries && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /common/workspaces/arduino/myLibraries/RGBColorFade /common/workspaces/arduino/myLibraries/RGBColorFade/src /common/workspaces/arduino/myLibraries /common/workspaces/arduino/myLibraries/src /common/workspaces/arduino/myLibraries/src/CMakeFiles/RGBColorFade.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/RGBColorFade.dir/depend
