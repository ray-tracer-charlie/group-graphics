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
include external/glfw/src/CMakeFiles/glfw.dir/depend.make

# Include the progress variables for this target.
include external/glfw/src/CMakeFiles/glfw.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw/src/CMakeFiles/glfw.dir/flags.make

external/glfw/src/CMakeFiles/glfw.dir/context.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/context.c.o: ../external/glfw/src/context.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/context.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/context.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/context.c

external/glfw/src/CMakeFiles/glfw.dir/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/context.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/context.c > CMakeFiles/glfw.dir/context.c.i

external/glfw/src/CMakeFiles/glfw.dir/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/context.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/context.c -o CMakeFiles/glfw.dir/context.c.s

external/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/context.c.o

external/glfw/src/CMakeFiles/glfw.dir/init.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/init.c.o: ../external/glfw/src/init.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/init.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/init.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/init.c

external/glfw/src/CMakeFiles/glfw.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/init.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/init.c > CMakeFiles/glfw.dir/init.c.i

external/glfw/src/CMakeFiles/glfw.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/init.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/init.c -o CMakeFiles/glfw.dir/init.c.s

external/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/init.c.o

external/glfw/src/CMakeFiles/glfw.dir/input.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/input.c.o: ../external/glfw/src/input.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/input.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/input.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/input.c

external/glfw/src/CMakeFiles/glfw.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/input.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/input.c > CMakeFiles/glfw.dir/input.c.i

external/glfw/src/CMakeFiles/glfw.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/input.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/input.c -o CMakeFiles/glfw.dir/input.c.s

external/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/input.c.o

external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: ../external/glfw/src/monitor.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/monitor.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/monitor.c

external/glfw/src/CMakeFiles/glfw.dir/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/monitor.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/monitor.c > CMakeFiles/glfw.dir/monitor.c.i

external/glfw/src/CMakeFiles/glfw.dir/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/monitor.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/monitor.c -o CMakeFiles/glfw.dir/monitor.c.s

external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o

external/glfw/src/CMakeFiles/glfw.dir/window.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/window.c.o: ../external/glfw/src/window.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/window.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/window.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/window.c

external/glfw/src/CMakeFiles/glfw.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/window.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/window.c > CMakeFiles/glfw.dir/window.c.i

external/glfw/src/CMakeFiles/glfw.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/window.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/window.c -o CMakeFiles/glfw.dir/window.c.s

external/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/window.c.o

external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o: ../external/glfw/src/x11_init.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/x11_init.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/x11_init.c

external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_init.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/x11_init.c > CMakeFiles/glfw.dir/x11_init.c.i

external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_init.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/x11_init.c -o CMakeFiles/glfw.dir/x11_init.c.s

external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o

external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o: ../external/glfw/src/x11_monitor.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/x11_monitor.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/x11_monitor.c

external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_monitor.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/x11_monitor.c > CMakeFiles/glfw.dir/x11_monitor.c.i

external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_monitor.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/x11_monitor.c -o CMakeFiles/glfw.dir/x11_monitor.c.s

external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o

external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o: ../external/glfw/src/x11_window.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/x11_window.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/x11_window.c

external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_window.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/x11_window.c > CMakeFiles/glfw.dir/x11_window.c.i

external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_window.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/x11_window.c -o CMakeFiles/glfw.dir/x11_window.c.s

external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o

external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: ../external/glfw/src/xkb_unicode.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/xkb_unicode.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/xkb_unicode.c

external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/xkb_unicode.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/xkb_unicode.c > CMakeFiles/glfw.dir/xkb_unicode.c.i

external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/xkb_unicode.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/xkb_unicode.c -o CMakeFiles/glfw.dir/xkb_unicode.c.s

external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o

external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o: ../external/glfw/src/linux_joystick.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/linux_joystick.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/linux_joystick.c

external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/linux_joystick.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/linux_joystick.c > CMakeFiles/glfw.dir/linux_joystick.c.i

external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/linux_joystick.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/linux_joystick.c -o CMakeFiles/glfw.dir/linux_joystick.c.s

external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o

external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o: ../external/glfw/src/posix_time.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/posix_time.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/posix_time.c

external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_time.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/posix_time.c > CMakeFiles/glfw.dir/posix_time.c.i

external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_time.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/posix_time.c -o CMakeFiles/glfw.dir/posix_time.c.s

external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o

external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: ../external/glfw/src/posix_tls.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/posix_tls.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/posix_tls.c

external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_tls.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/posix_tls.c > CMakeFiles/glfw.dir/posix_tls.c.i

external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_tls.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/posix_tls.c -o CMakeFiles/glfw.dir/posix_tls.c.s

external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o

external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o: external/glfw/src/CMakeFiles/glfw.dir/flags.make
external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o: ../external/glfw/src/glx_context.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cs148/Desktop/group-graphics/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/glfw.dir/glx_context.c.o   -c /home/cs148/Desktop/group-graphics/external/glfw/src/glx_context.c

external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/glx_context.c.i"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cs148/Desktop/group-graphics/external/glfw/src/glx_context.c > CMakeFiles/glfw.dir/glx_context.c.i

external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/glx_context.c.s"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cs148/Desktop/group-graphics/external/glfw/src/glx_context.c -o CMakeFiles/glfw.dir/glx_context.c.s

external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires:
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires

external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides: external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires
	$(MAKE) -f external/glfw/src/CMakeFiles/glfw.dir/build.make external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides.build
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides

external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides.build: external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o

# Object files for target glfw
glfw_OBJECTS = \
"CMakeFiles/glfw.dir/context.c.o" \
"CMakeFiles/glfw.dir/init.c.o" \
"CMakeFiles/glfw.dir/input.c.o" \
"CMakeFiles/glfw.dir/monitor.c.o" \
"CMakeFiles/glfw.dir/window.c.o" \
"CMakeFiles/glfw.dir/x11_init.c.o" \
"CMakeFiles/glfw.dir/x11_monitor.c.o" \
"CMakeFiles/glfw.dir/x11_window.c.o" \
"CMakeFiles/glfw.dir/xkb_unicode.c.o" \
"CMakeFiles/glfw.dir/linux_joystick.c.o" \
"CMakeFiles/glfw.dir/posix_time.c.o" \
"CMakeFiles/glfw.dir/posix_tls.c.o" \
"CMakeFiles/glfw.dir/glx_context.c.o"

# External object files for target glfw
glfw_EXTERNAL_OBJECTS =

external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/context.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/init.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/input.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/window.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/build.make
external/glfw/src/libglfw3.a: external/glfw/src/CMakeFiles/glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libglfw3.a"
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean_target.cmake
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw/src/CMakeFiles/glfw.dir/build: external/glfw/src/libglfw3.a
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/build

external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires
external/glfw/src/CMakeFiles/glfw.dir/requires: external/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/requires

external/glfw/src/CMakeFiles/glfw.dir/clean:
	cd /home/cs148/Desktop/group-graphics/build/external/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean.cmake
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/clean

external/glfw/src/CMakeFiles/glfw.dir/depend:
	cd /home/cs148/Desktop/group-graphics/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs148/Desktop/group-graphics /home/cs148/Desktop/group-graphics/external/glfw/src /home/cs148/Desktop/group-graphics/build /home/cs148/Desktop/group-graphics/build/external/glfw/src /home/cs148/Desktop/group-graphics/build/external/glfw/src/CMakeFiles/glfw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw/src/CMakeFiles/glfw.dir/depend

