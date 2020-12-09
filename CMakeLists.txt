# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required (VERSION 3.8)

project ("EmscriptenProjects")

if(EMSCRIPTEN)
	set(CMAKE_BUILD_TYPE "Emscripten")
endif()


# LOCATE RAYLIB LIBRARY
# =============================================================================
if(MSVC)
	set(RAYLIB_DIR "${CMAKE_HOME_DIRECTORY}/libs/Raylib3")
	set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
	set(RAYLIB_LIBRARY_DIR "${RAYLIB_DIR}/bin/x64/${CMAKE_BUILD_TYPE}/")
	set(RAYLIB_LIBRARIES "winmm.lib;${RAYLIB_LIBRARY_DIR}/raylib.lib;")
elseif(EMSCRIPTEN)
	set(RAYLIB_DIR "${CMAKE_HOME_DIRECTORY}/libs/Raylib3")
	set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
	set(RAYLIB_LIBRARY_DIR "${RAYLIB_DIR}/bin/Emscripten")
	set(RAYLIB_LIBRARIES "${RAYLIB_LIBRARY_DIR}/libraylib.a;")
endif()
# =============================================================================


# Include sub-projects.
# =============================================================================
add_subdirectory ("projects/HelloRaylib")

# TODO: add any additional sub projects here!

# =============================================================================




