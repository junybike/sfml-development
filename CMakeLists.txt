cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB SOURCE
        src/*.cpp
)
file(GLOB INCLUDE
        include/*.h
)

# Define the executable
add_executable(main
        ${SOURCE} ${INCLUDE}
)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

# Define the source directory and image path
set(IMAGE_PATH ${CMAKE_SOURCE_DIR}/img/mushroom.png)
set(FONT_PATH ${CMAKE_SOURCE_DIR}/font/arial.ttf)
set(FILE_PATH ${CMAKE_SOURCE_DIR}/file/keys.cfg)

# Add custom command to copy the image to the build output directory
add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${IMAGE_PATH} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mushroom.png
)

add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${FONT_PATH} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/arial.ttf
)

add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${FILE_PATH} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/keys.cfg
)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
