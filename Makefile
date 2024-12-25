# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benjamin/Desktop/CGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benjamin/Desktop/CGame

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/benjamin/Desktop/CGame/CMakeFiles /home/benjamin/Desktop/CGame//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/benjamin/Desktop/CGame/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CGame

# Build rule for target.
CGame: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 CGame
.PHONY : CGame

# fast build rule for target.
CGame/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/build
.PHONY : CGame/fast

src/GameWindow.o: src/GameWindow.cpp.o
.PHONY : src/GameWindow.o

# target to build an object file
src/GameWindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/GameWindow.cpp.o
.PHONY : src/GameWindow.cpp.o

src/GameWindow.i: src/GameWindow.cpp.i
.PHONY : src/GameWindow.i

# target to preprocess a source file
src/GameWindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/GameWindow.cpp.i
.PHONY : src/GameWindow.cpp.i

src/GameWindow.s: src/GameWindow.cpp.s
.PHONY : src/GameWindow.s

# target to generate assembly for a file
src/GameWindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/GameWindow.cpp.s
.PHONY : src/GameWindow.cpp.s

src/Shader.o: src/Shader.cpp.o
.PHONY : src/Shader.o

# target to build an object file
src/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/Shader.cpp.o
.PHONY : src/Shader.cpp.o

src/Shader.i: src/Shader.cpp.i
.PHONY : src/Shader.i

# target to preprocess a source file
src/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/Shader.cpp.i
.PHONY : src/Shader.cpp.i

src/Shader.s: src/Shader.cpp.s
.PHONY : src/Shader.s

# target to generate assembly for a file
src/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/Shader.cpp.s
.PHONY : src/Shader.cpp.s

src/gl.o: src/gl.c.o
.PHONY : src/gl.o

# target to build an object file
src/gl.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/gl.c.o
.PHONY : src/gl.c.o

src/gl.i: src/gl.c.i
.PHONY : src/gl.i

# target to preprocess a source file
src/gl.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/gl.c.i
.PHONY : src/gl.c.i

src/gl.s: src/gl.c.s
.PHONY : src/gl.s

# target to generate assembly for a file
src/gl.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/gl.c.s
.PHONY : src/gl.c.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CGame.dir/build.make CMakeFiles/CGame.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... CGame"
	@echo "... src/GameWindow.o"
	@echo "... src/GameWindow.i"
	@echo "... src/GameWindow.s"
	@echo "... src/Shader.o"
	@echo "... src/Shader.i"
	@echo "... src/Shader.s"
	@echo "... src/gl.o"
	@echo "... src/gl.i"
	@echo "... src/gl.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

