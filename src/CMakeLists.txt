find_package(PkgConfig)

file(GLOB_RECURSE lib_source LIST_DIRECTORIES true *.cpp *.h)

pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_library(raid STATIC ${lib_source})
target_link_libraries(raid ${GTKMM_LIBRARIES})

install(TARGETS raid)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/raid DESTINATION include FILES_MATCHING PATTERN "*.h")