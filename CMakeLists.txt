cmake_minimum_required(VERSION 3.15...3.28)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/etc/cmake")

include(FetchContent)

include(doctest)
include(compilers)

project(
  doctest-covr-training
  VERSION 2024.2.10
  DESCRIPTION "Small multiple files doctest with gcovr training example."
  LANGUAGES CXX)

include(CTest)
include(coverage)
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
include(run_tests)
include(process_coverage)
include(run_analysis)
