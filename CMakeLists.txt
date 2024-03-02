cmake_minimum_required(VERSION 3.0.0)
project(DragonCC VERSION 0.1.0 LANGUAGES C CXX)
# set(CMAKE_CXX_STANDARD 14)
 message(STATUS " C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
include(CTest)
enable_testing()
include_directories(src/parser src/ast src/define src/CodeGen)
aux_source_directory(src/parser PARSER_SOURCES)
aux_source_directory(src/ast AST_SOURCES)
aux_source_directory(src/define DEF_SOURCES)
aux_source_directory(src/CodeGen CODEGEN_SOURCES)
add_executable(DragonCC src/main.cpp ${PARSER_SOURCES} ${AST_SOURCES} ${DEF_SOURCES} 
                                    ${CODEGEN_SOURCES})

#  target_sources(DragonCC PRIVATE ${PARSER_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
