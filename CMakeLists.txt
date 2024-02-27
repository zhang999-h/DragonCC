cmake_minimum_required(VERSION 3.0.0)
project(DragonCC VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

aux_source_directory(src/parser PARSER_SOURCES)
add_executable(DragonCC main.cpp ${PARSER_SOURCES})

#  target_sources(DragonCC PRIVATE ${PARSER_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
