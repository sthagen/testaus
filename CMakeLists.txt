cmake_minimum_required(VERSION 3.15...3.28)
include(FetchContent)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/etc/cmake")
include(cxx_language_version)

option(ENABLE_DOCTESTS "Include doctest based tests in the library.
  Setting this to OFF will remove all doctest related code.
  Tests in tests/*.cpp will still be enabled." ON)
include(doctest)

option(ENABLE_CATCH2 "Include Catch2 based tests in the library.
  Setting this to OFF will remove all doctest related code.
  Tests in tests/*.cpp will still be enabled." ON)
include(catch2)

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

  add_executable(tests_catch2 test/test_implementation_catch2.cpp)
  target_link_libraries(tests_catch2 PRIVATE Catch2::Catch2WithMain implementation)
  add_test(NAME tests_catch2 COMMAND tests_catch2)
endif()

include(gcovr)
include(execute_tests)
include(coverage)
include(analysis)
