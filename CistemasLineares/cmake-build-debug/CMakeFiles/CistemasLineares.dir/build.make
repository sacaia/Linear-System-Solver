# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\CistemasLineares.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\CistemasLineares.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CistemasLineares.dir\flags.make

CMakeFiles\CistemasLineares.dir\main.c.obj: CMakeFiles\CistemasLineares.dir\flags.make
CMakeFiles\CistemasLineares.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CistemasLineares.dir/main.c.obj"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\CistemasLineares.dir\main.c.obj /FdCMakeFiles\CistemasLineares.dir\ /FS -c "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\main.c"
<<

CMakeFiles\CistemasLineares.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CistemasLineares.dir/main.c.i"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\CistemasLineares.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\main.c"
<<

CMakeFiles\CistemasLineares.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CistemasLineares.dir/main.c.s"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\CistemasLineares.dir\main.c.s /c "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\main.c"
<<

# Object files for target CistemasLineares
CistemasLineares_OBJECTS = \
"CMakeFiles\CistemasLineares.dir\main.c.obj"

# External object files for target CistemasLineares
CistemasLineares_EXTERNAL_OBJECTS =

CistemasLineares.exe: CMakeFiles\CistemasLineares.dir\main.c.obj
CistemasLineares.exe: CMakeFiles\CistemasLineares.dir\build.make
CistemasLineares.exe: CMakeFiles\CistemasLineares.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable CistemasLineares.exe"
	"C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\CistemasLineares.dir --manifests  -- C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\CistemasLineares.dir\objects1.rsp @<<
 /out:CistemasLineares.exe /implib:CistemasLineares.lib /pdb:"C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug\CistemasLineares.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\CistemasLineares.dir\build: CistemasLineares.exe

.PHONY : CMakeFiles\CistemasLineares.dir\build

CMakeFiles\CistemasLineares.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CistemasLineares.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CistemasLineares.dir\clean

CMakeFiles\CistemasLineares.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares" "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares" "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug" "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug" "C:\Users\Lucas R\Documents\GitHub\Sistemas-Lineares\CistemasLineares\cmake-build-debug\CMakeFiles\CistemasLineares.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\CistemasLineares.dir\depend
