cmake_minimum_required(VERSION 3.15...3.28)
include(FetchContent)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/etc/cmake")
include(cxx_language_version)

option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
  Tests in tests/*.cpp will still be enabled." ON)
include(doctest)

project(
  doctest-covr-training
  VERSION 2024.2.10
  DESCRIPTION "Small multiple files doctest with gcovr training example."
  LANGUAGES CXX)

include(CTest)
option(ENABLE_COVERAGE "Enable coverage options. Setting this to OFF will disable coverage." ON)
include(coverage_compiler_options)
enable_testing()

add_library(implementation STATIC src/implementation.cpp)

add_executable(example example/main.cpp)
target_link_libraries(example PRIVATE implementation)

if(BUILD_TESTING)
  add_executable(tests test/test_implementation.cpp)
  target_link_libraries(tests PRIVATE doctest::doctest implementation)
  add_test(NAME tests COMMAND tests)
endif()

include(gcovr)
include(execute_tests)
include(coverage)
include(analysis)
