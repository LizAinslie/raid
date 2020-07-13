cmake_minimum_required(VERSION 3.16)
project(raid CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(examples)

#########
# Tests #
#########
enable_testing()

file(GLOB test_files "tests/test_*.cpp")
foreach(file ${test_files})
    string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" file_without_ext ${file})
    add_executable(${file_without_ext} ${file})
    target_link_libraries(${file_without_ext} PUBLIC raid)
    target_include_directories(${file_without_ext} PUBLIC "${PROJECT_BINARY_DIR}")
    add_test(${file_without_ext} ${file_without_ext})
endforeach()