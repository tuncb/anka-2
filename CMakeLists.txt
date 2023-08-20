cmake_minimum_required(VERSION 3.1...3.23)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(
  AnkaLang
  VERSION 0.0.1
  LANGUAGES CXX)

add_executable(anka
  ./src/anka2/anka2.cpp
  ./src/anka2/Dialect.h)

set(LLVM_DIR C:/work/lib/llvm-project/build/lib/cmake/llvm)
set(MLIR_DIR C:/work/lib/llvm-project/build/lib/cmake/mlir)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Found LLVNMConfig.cmake in: ${LLVM_DIR}")

find_package(MLIR REQUIRED CONFIG)

message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")

set(LLVM_LINK_COMPONENTS
  Core
  Support
  nativecodegen
  OrcJIT)

# set(LLVM_TARGET_DEFINITIONS ./src/anka2/mlir_tablegen/anka_ops.td)
# mlir_tablegen(ToyCombine.inc -gen-rewriters)
# add_public_tablegen_target(ToyCh6CombineIncGen)

include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)
get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
get_property(extension_libs GLOBAL PROPERTY MLIR_EXTENSION_LIBS)
target_link_libraries(anka
  PRIVATE
    ${dialect_libs}
    ${conversion_libs}
    ${extension_libs}
    MLIRAnalysis
    MLIRBuiltinToLLVMIRTranslation
    MLIRCallInterfaces
    MLIRCastInterfaces
    MLIRExecutionEngine
    MLIRIR
    MLIRLLVMCommonConversion
    MLIRLLVMDialect
    MLIRLLVMToLLVMIRTranslation
    MLIRMemRefDialect
    MLIRParser
    MLIRPass
    MLIRSideEffectInterfaces
    MLIRSupport
    MLIRTargetLLVMIRExport
    MLIRTransforms
    )