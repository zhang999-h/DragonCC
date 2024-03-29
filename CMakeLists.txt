cmake_minimum_required(VERSION 3.0.0)
project(DragonCC VERSION 0.1.0 LANGUAGES C CXX)
# set(CMAKE_CXX_STANDARD 14)
 message(STATUS " C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
include(CTest)
enable_testing()
include_directories(src/parser src/ast src/define src/CodeGen src/backend)
aux_source_directory(src/parser PARSER_SOURCES)
aux_source_directory(src/ast AST_SOURCES)
aux_source_directory(src/define DEF_SOURCES)
aux_source_directory(src/CodeGen CODEGEN_SOURCES)
aux_source_directory(src/backend BACKEND_SOURCES)
add_executable(DragonCC src/main.cpp ${PARSER_SOURCES} ${AST_SOURCES} ${DEF_SOURCES} 
                                    ${CODEGEN_SOURCES} ${BACKEND_SOURCES})


# 查找 LLVM
find_package(LLVM REQUIRED CONFIG)
# 将 LLVM 的 include 目录添加到头文件搜索路径
include_directories(${LLVM_INCLUDE_DIRS})

# #执行llvm-config --libs all命令，并将输出保存到llvm_libraries变量中
execute_process(COMMAND llvm-config --libs all
                OUTPUT_VARIABLE llvm_libraries)


# # 去除 llvm_libraries 变量中的前导和尾随空白字符
string(STRIP ${llvm_libraries} llvm_libraries)
# 去除 llvm_libraries 变量中的 '-' 前缀
string(REPLACE "-l" "" llvm_libraries "${llvm_libraries}")
#要加; 要不然在变量里识别不了
string(REPLACE " " ";" llvm_libraries "${llvm_libraries}")

# 获取 LLVM 的链接信息
 llvm_map_components_to_libnames(LLVM_LIBS support core irreader)
 # 链接 LLVM 库
target_link_libraries(DragonCC ${llvm_libraries})

#  target_sources(DragonCC PRIVATE ${PARSER_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
