# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cs148/Desktop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs148/Desktop/group-graphics

# Include any dependencies generated for this target.
include external/glew-cmake/CMakeFiles/libglew_static.dir/depend.make

# Include the progress variables for this target.
include external/glew-cmake/CMakeFiles/libglew_static.dir/progress.make

# Include the compile flags for this target's objects.
include external/glew-cmake/CMakeFiles/libglew_static.dir/flags.make

external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o: external/glew-cmake/CMakeFiles/libglew_static.dir/flags.make
external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o: ../external/glew-cmake/src/glew.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o"
	cd /home/cs148/Desktop/group-graphics/external/glew-cmake && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/libglew_static.dir/src/glew.c.o   -c /home/cs148/Desktop/external/glew-cmake/src/glew.c

external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libglew_static.dir/src/glew.c.i"
	cd /home/cs148/Desktop/group-graphics/external/glew-cmake && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/external/glew-cmake/src/glew.c > CMakeFiles/libglew_static.dir/src/glew.c.i

external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libglew_static.dir/src/glew.c.s"
	cd /home/cs148/Desktop/group-graphics/external/glew-cmake && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/external/glew-cmake/src/glew.c -o CMakeFiles/libglew_static.dir/src/glew.c.s

external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.requires:
.PHONY : external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.requires

external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.provides: external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.requires
	$(MAKE) -f external/glew-cmake/CMakeFiles/libglew_static.dir/build.make external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.provides.build
.PHONY : external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.provides

external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.provides.build: external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o

# Object files for target libglew_static
libglew_static_OBJECTS = \
"CMakeFiles/libglew_static.dir/src/glew.c.o"

# External object files for target libglew_static
libglew_static_EXTERNAL_OBJECTS =

lib/libglew.a: external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o
lib/libglew.a: external/glew-cmake/CMakeFiles/libglew_static.dir/build.make
lib/libglew.a: external/glew-cmake/CMakeFiles/libglew_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library ../../lib/libglew.a"
	cd /home/cs148/Desktop/group-graphics/external/glew-cmake && $(CMAKE_COMMAND) -P CMakeFiles/libglew_static.dir/cmake_clean_target.cmake
	cd /home/cs148/Desktop/group-graphics/external/glew-cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libglew_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glew-cmake/CMakeFiles/libglew_static.dir/build: lib/libglew.a
.PHONY : external/glew-cmake/CMakeFiles/libglew_static.dir/build

external/glew-cmake/CMakeFiles/libglew_static.dir/requires: external/glew-cmake/CMakeFiles/libglew_static.dir/src/glew.c.o.requires
.PHONY : external/glew-cmake/CMakeFiles/libglew_static.dir/requires

external/glew-cmake/CMakeFiles/libglew_static.dir/clean:
	cd /home/cs148/Desktop/group-graphics/external/glew-cmake && $(CMAKE_COMMAND) -P CMakeFiles/libglew_static.dir/cmake_clean.cmake
.PHONY : external/glew-cmake/CMakeFiles/libglew_static.dir/clean

external/glew-cmake/CMakeFiles/libglew_static.dir/depend:
	cd /home/cs148/Desktop/group-graphics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs148/Desktop /home/cs148/Desktop/external/glew-cmake /home/cs148/Desktop/group-graphics /home/cs148/Desktop/group-graphics/external/glew-cmake /home/cs148/Desktop/group-graphics/external/glew-cmake/CMakeFiles/libglew_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glew-cmake/CMakeFiles/libglew_static.dir/depend

