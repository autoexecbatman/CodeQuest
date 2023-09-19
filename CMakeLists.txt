# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required (VERSION 3.19)

project ("EmscriptenProjects")

# C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(EMSCRIPTEN)
	set(CMAKE_BUILD_TYPE "Emscripten")
endif()

# LOCATE LIBRARY
# =============================================================================
# Raylib
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/libs/Raylib3")
set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
set(RAYLIB_LIBRARY_DIR "${RAYLIB_DIR}/bin")
# Json
set(JSON_DIR "${CMAKE_SOURCE_DIR}/libs/json")
set(JSON_INCLUDE_DIR "${JSON_DIR}/include")
# EnTT
set(ENTT_DIR "${CMAKE_SOURCE_DIR}/libs/ecs")
set(ENTT_INCLUDE_DIR "${ENTT_DIR}/include")

if(MSVC)
# MSVC libraries
	set(RAYLIB_LIBRARIES "winmm.lib;${RAYLIB_LIBRARY_DIR}/x64/${CMAKE_BUILD_TYPE}/raylib.lib;")
elseif(EMSCRIPTEN)
# Emscripten libraries
	set(RAYLIB_LIBRARIES "${RAYLIB_LIBRARY_DIR}/Emscripten/libraylib.a;")
endif()
# =============================================================================

# Include sub-projects.
# =============================================================================
add_subdirectory ("projects/HelloRaylib")
add_subdirectory ("projects/Pong")

# TODO: add any additional sub projects here!

# =============================================================================
