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
CMAKE_SOURCE_DIR = /home/cs148/Desktop/group-graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs148/Desktop/group-graphics/build

# Include any dependencies generated for this target.
include external/SOIL/CMakeFiles/SOIL_Dylib.dir/depend.make

# Include the progress variables for this target.
include external/SOIL/CMakeFiles/SOIL_Dylib.dir/progress.make

# Include the compile flags for this target's objects.
include external/SOIL/CMakeFiles/SOIL_Dylib.dir/flags.make

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o: external/SOIL/CMakeFiles/SOIL_Dylib.dir/flags.make
external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o: ../external/SOIL/src/image_helper.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o   -c /home/cs148/Desktop/group-graphics/external/SOIL/src/image_helper.c

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/SOIL/src/image_helper.c > CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.i

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/SOIL/src/image_helper.c -o CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.s

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.requires:
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.requires

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.provides: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.requires
	$(MAKE) -f external/SOIL/CMakeFiles/SOIL_Dylib.dir/build.make external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.provides.build
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.provides

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.provides.build: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o: external/SOIL/CMakeFiles/SOIL_Dylib.dir/flags.make
external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o: ../external/SOIL/src/stb_image_aug.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o   -c /home/cs148/Desktop/group-graphics/external/SOIL/src/stb_image_aug.c

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/SOIL/src/stb_image_aug.c > CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.i

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/SOIL/src/stb_image_aug.c -o CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.s

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.requires:
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.requires

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.provides: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.requires
	$(MAKE) -f external/SOIL/CMakeFiles/SOIL_Dylib.dir/build.make external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.provides.build
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.provides

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.provides.build: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o: external/SOIL/CMakeFiles/SOIL_Dylib.dir/flags.make
external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o: ../external/SOIL/src/image_DXT.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o   -c /home/cs148/Desktop/group-graphics/external/SOIL/src/image_DXT.c

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/SOIL/src/image_DXT.c > CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.i

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/SOIL/src/image_DXT.c -o CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.s

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.requires:
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.requires

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.provides: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.requires
	$(MAKE) -f external/SOIL/CMakeFiles/SOIL_Dylib.dir/build.make external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.provides.build
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.provides

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.provides.build: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o: external/SOIL/CMakeFiles/SOIL_Dylib.dir/flags.make
external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o: ../external/SOIL/src/SOIL.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o   -c /home/cs148/Desktop/group-graphics/external/SOIL/src/SOIL.c

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/SOIL/src/SOIL.c > CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.i

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/SOIL/src/SOIL.c -o CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.s

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.requires:
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.requires

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.provides: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.requires
	$(MAKE) -f external/SOIL/CMakeFiles/SOIL_Dylib.dir/build.make external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.provides.build
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.provides

external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.provides.build: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o

# Object files for target SOIL_Dylib
SOIL_Dylib_OBJECTS = \
"CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o" \
"CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o" \
"CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o" \
"CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o"

# External object files for target SOIL_Dylib
SOIL_Dylib_EXTERNAL_OBJECTS =

external/SOIL/libSOIL.so.1.07: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o
external/SOIL/libSOIL.so.1.07: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o
external/SOIL/libSOIL.so.1.07: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o
external/SOIL/libSOIL.so.1.07: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o
external/SOIL/libSOIL.so.1.07: external/SOIL/CMakeFiles/SOIL_Dylib.dir/build.make
external/SOIL/libSOIL.so.1.07: external/SOIL/CMakeFiles/SOIL_Dylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library libSOIL.so"
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SOIL_Dylib.dir/link.txt --verbose=$(VERBOSE)
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && $(CMAKE_COMMAND) -E cmake_symlink_library libSOIL.so.1.07 libSOIL.so.1 libSOIL.so

external/SOIL/libSOIL.so.1: external/SOIL/libSOIL.so.1.07
	@$(CMAKE_COMMAND) -E touch_nocreate external/SOIL/libSOIL.so.1

external/SOIL/libSOIL.so: external/SOIL/libSOIL.so.1.07
	@$(CMAKE_COMMAND) -E touch_nocreate external/SOIL/libSOIL.so

# Rule to build all files generated by this target.
external/SOIL/CMakeFiles/SOIL_Dylib.dir/build: external/SOIL/libSOIL.so
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/build

external/SOIL/CMakeFiles/SOIL_Dylib.dir/requires: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_helper.c.o.requires
external/SOIL/CMakeFiles/SOIL_Dylib.dir/requires: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/stb_image_aug.c.o.requires
external/SOIL/CMakeFiles/SOIL_Dylib.dir/requires: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/image_DXT.c.o.requires
external/SOIL/CMakeFiles/SOIL_Dylib.dir/requires: external/SOIL/CMakeFiles/SOIL_Dylib.dir/src/SOIL.c.o.requires
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/requires

external/SOIL/CMakeFiles/SOIL_Dylib.dir/clean:
	cd /home/cs148/Desktop/group-graphics/build/external/SOIL && $(CMAKE_COMMAND) -P CMakeFiles/SOIL_Dylib.dir/cmake_clean.cmake
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/clean

external/SOIL/CMakeFiles/SOIL_Dylib.dir/depend:
	cd /home/cs148/Desktop/group-graphics/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs148/Desktop/group-graphics /home/cs148/Desktop/group-graphics/external/SOIL /home/cs148/Desktop/group-graphics/build /home/cs148/Desktop/group-graphics/build/external/SOIL /home/cs148/Desktop/group-graphics/build/external/SOIL/CMakeFiles/SOIL_Dylib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/SOIL/CMakeFiles/SOIL_Dylib.dir/depend
