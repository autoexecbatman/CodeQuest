
cmake_minimum_required (VERSION 3.19)

project("Pong")

# C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
FILE(GLOB Proj_C_Files src/*.c)
FILE(GLOB Proj_CPP_Files src/*.cpp)
FILE(GLOB Proj_H_Files inc/*.h)
FILE(GLOB Proj_HPP_Files inc/*.hpp)
add_executable (${PROJECT_NAME} ${Proj_C_Files} ${Proj_CPP_Files} ${Proj_H_Files} ${Proj_HPP_Files})

include_directories("inc;")

# DEFINE OUTPUT DIRECTORY
# =============================================================================
if (EMSCRIPTEN)
	
	set(USE_FLAGS "-s USE_GLFW=3 -s ASSERTIONS=1 -s ASYNCIFY --preload-file ${CMAKE_HOME_DIRECTORY}/projects/${PROJECT_NAME}/assets/@/assets/")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}")

	set(CMAKE_EXECUTABLE_SUFFIX ".html")

endif()

set(CMAKE_BINARY_DIR "${CMAKE_HOME_DIRECTORY}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}/")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# =============================================================================


# Reference 3rd Party Libraries
# =============================================================================

include_directories("${RAYLIB_INCLUDE_DIR};")
target_link_libraries(${PROJECT_NAME} "${RAYLIB_LIBRARIES}")
include_directories("${JSON_INCLUDE_DIR};")
include_directories("${ENTT_INCLUDE_DIR};")

# =============================================================================

# BUILD STEPS - Copy assets
# =============================================================================
if (EMSCRIPTEN)
	#
	# no custom copy actions needed    
	# 
elseif(MSVC)

	# copy asset directory to output folder
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD   
		COMMAND ${CMAKE_COMMAND} -E copy_directory 
		"${CMAKE_HOME_DIRECTORY}/projects/${PROJECT_NAME}/assets" "${EXECUTABLE_OUTPUT_PATH}/assets")
endif()

# Copy JSON files to build directory.
set(JSON_FILES
	"${PROJECT_SOURCE_DIR}/json/strength.json"
	"${PROJECT_SOURCE_DIR}/json/dexterity.json"
	"${PROJECT_SOURCE_DIR}/json/constitution.json"
	"${PROJECT_SOURCE_DIR}/json/wisdom.json"
	"${PROJECT_SOURCE_DIR}/json/intelligence.json"
	"${PROJECT_SOURCE_DIR}/json/charisma.json"
)

foreach(JSON_FILE ${JSON_FILES})
	get_filename_component(JSON_FILENAME ${JSON_FILE} NAME)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
					   COMMAND ${CMAKE_COMMAND} -E echo "Copying ${JSON_FILE} to ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${JSON_FILENAME}"
					   COMMAND ${CMAKE_COMMAND} -E copy_if_different
							   ${JSON_FILE}
							   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${JSON_FILENAME})
endforeach()