file(GLOB_RECURSE lib_source LIST_DIRECTORIES true *.cpp *.h)

add_library(raid STATIC ${lib_source})
target_link_libraries(raid ${GTKMM_LIBRARIES})

install(TARGETS raid)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/raid DESTINATION include FILES_MATCHING PATTERN "*.h")