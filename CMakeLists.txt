cmake_minimum_required(VERSION 3.6)

if (${CMAKE_SOURCE_DIR} STREQUAL "${PROJECT_SOURCE_DIR/src}")
    message(FATAL_ERROR "CMake generation is not allowed within the source directory!")
endif ()

project(basicEncryption
    VERSION 1.0
    LANGUAGES CXX
)

set(default_build_type "Release")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(source_dir src)
set(
        source_files
        ${source_dir}/main.cpp
)

set(build_dir "executable")
set(EXECUTABLE_OUTPUT_PATH ${build_dir})

set(
        support_files
        #LICENSE
)

file(COPY ${support_files} DESTINATION "${build_dir}")

add_executable(${PROJECT_NAME} ${source_files} ${support_files})

include_directories(/usr/local/include/) #This directory have headers files ftxui, on other device this may be different
set(                                     #This location static lib, on other device this may be different
    FTXUI_LIBRARIES
    /usr/local/lib/libftxui-component.a
    /usr/local/lib/libftxui-screen.a
    /usr/local/lib/libftxui-dom.a
)

target_link_libraries(${PROJECT_NAME} ${FTXUI_LIBRARIES})
