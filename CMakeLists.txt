cmake_minimum_required(VERSION 3.7)
set(PROJECT OpenMugen)
project(${PROJECT})

# Add global definitions
add_definitions("-Wall")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Using C++98
add_executable(${PROJECT} ${SOURCE_FILES})
set_property(TARGET ${PROJECT} PROPERTY CXX_STANDARD 98)
set_property(TARGET ${PROJECT} PROPERTY CXX_STANDARD_REQUIRED 98)

message("CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions("-g -O0 -Wall -Wextra -Wpedantic -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif ()

# ExternalProject for SDL, SDL_image, and SDL_gfx
include(ExternalProject)
set(EXTERNAL_INSTALL_DIR ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.32.0
    GIT_SHALLOW 1
    PREFIX ${EXTERNAL_INSTALL_DIR}
    CMAKE_ARGS 
    -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_DIR}
    -DSDL_STATIC=ON
    -DSDL_SHARED=OFF
)

ExternalProject_Add(SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.5
    GIT_SHALLOW 1
    PREFIX ${EXTERNAL_INSTALL_DIR}
    CMAKE_ARGS 
    -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_DIR}
    -DSDL2_DIR=${EXTERNAL_INSTALL_DIR}
    -DSDL2IMAGE_TESTS=OFF
    -DSDL2IMAGE_SAMPLES=OFF
    -DSDL2IMAGE_WEBP=OFF
    -DBUILD_SHARED_LIBS=OFF
    DEPENDS SDL2
)

ExternalProject_Add(SDL2_gfx
    GIT_REPOSITORY https://github.com/mupfdev/SDL2_gfx.git
    GIT_TAG main
    GIT_SHALLOW 1
    PREFIX ${EXTERNAL_INSTALL_DIR}
    INSTALL_COMMAND ${CMAKE_COMMAND} -E copy <BINARY_DIR>/libSDL2_gfx.a ${EXTERNAL_INSTALL_DIR}/lib
    DEPENDS SDL2
)

# Include and link paths
include_directories(${EXTERNAL_INSTALL_DIR}/include/SDL2 src)
link_directories(${EXTERNAL_INSTALL_DIR}/lib)

add_dependencies(${PROJECT} SDL2 SDL2_image SDL2_gfx)

# Link libraries
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    find_library(COREHAPTICS_LIBRARY CoreHaptics)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    find_library(FORCEFEEDBACK_LIBRARY ForceFeedback)

    add_definitions(-DGL_SILENCE_DEPRECATION)
    target_link_libraries(${PROJECT} ${COREHAPTICS_LIBRARY} 
                                     ${COREVIDEO_LIBRARY} 
                                     "-liconv -framework Carbon -framework CoreServices -framework Metal -framework Cocoa -framework CoreAudio -framework AudioToolbox -framework CoreFoundation -framework ForceFeedback -framework CoreHaptics -framework GameController -framework IOKit")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Building on Linux")
endif ()

target_link_libraries(${PROJECT}
    -liconv
    ${EXTERNAL_INSTALL_DIR}/lib/libSDL2.a
    ${EXTERNAL_INSTALL_DIR}/lib/libSDL2_image.a
    ${EXTERNAL_INSTALL_DIR}/lib/libSDL2_gfx.a
)
