cmake_minimum_required(VERSION 3.23...3.28)
include(FetchContent)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/etc/cmake")
include(cxx_language_version)

option(ENABLE_DOCTESTS "Include doctest based tests in the library.
  Setting this to OFF will remove all doctest related code.
  Tests in tests/*.cpp will still be enabled."
  ON)
message(STATUS "ENABLE_DOCTESTS is (${ENABLE_DOCTESTS})")
include(doctest)

option(ENABLE_CATCH2 "Include Catch2 based tests in the library.
  Setting this to OFF will remove all catch2 related code.
  Tests in tests/*.cpp will still be enabled."
  OFF)
message(STATUS "ENABLE_CATCH2 is (${ENABLE_CATCH2})")
include(catch2)

option(ENABLE_BENCHMARK "Include benchmark functionality in tests."
   OFF)
message(STATUS "ENABLE_BENCHMARK is (${ENABLE_BENCHMARK})")
include(benchmark)

option(ENABLE_FAST_FLOAT "Include fast_float parsing functionality in the library."
   ON)
message(STATUS "ENABLE_FAST_FLOAT is (${ENABLE_FAST_FLOAT})")
include(fast_float)

option(ENABLE_FMT "Include fmt format functionality in the library."
   OFF)
message(STATUS "ENABLE_FMT is (${ENABLE_FMT})")
include(fmt)

option(ENABLE_GLAZE "Include glaze json functionality in the library."
   ON)
message(STATUS "ENABLE_GLAZE is (${ENABLE_GLAZE})")
include(glaze)

option(ENABLE_PUGIXML "Include pugixml xml functionality in the library."
   ON)
message(STATUS "ENABLE_PUGIXML is (${ENABLE_PUGIXML})")
include(pugixml)

option(ENABLE_TOMLPLUSPLUS "Include tomlplusplus toml functionality in the library."
   ON)
message(STATUS "ENABLE_TOMLPLUSPLUS is (${ENABLE_TOMLPLUSPLUS})")
include(tomlplusplus)

option(ENABLE_YAML_CPP "Include yaml-cpp yaml functionality in the library."
   ON)
message(STATUS "ENABLE_YAML_CPP is (${ENABLE_YAML_CPP})")
include(yaml-cpp)

option(ENABLE_STDUUID "Include stduuid UUID functionality in the library."
   ON)
message(STATUS "ENABLE_STDUUID is (${ENABLE_STDUUID})")
include(stduuid)

option(ENABLE_ARGPARSE "Include argparse argument parser functionality in the library."
   ON)
message(STATUS "ENABLE_ARGPARSE is (${ENABLE_ARGPARSE})")
include(argparse)

option(ENABLE_SPDLOG "Include spdlog log functionality in the library."
   ON)
message(STATUS "ENABLE_SPDLOG is (${ENABLE_SPDLOG})")
include(spdlog)

project(
  implementation
  VERSION 2024.2.18
  DESCRIPTION "Small multiple files cmake and third-party lib inclusion training example."
  LANGUAGES CXX)

include(CTest)
option(ENABLE_COVERAGE "Enable coverage options. Setting this to OFF will disable coverage."
  ON)
include(coverage_compiler_options)
enable_testing()

add_library(implementation STATIC src/implementation.cpp)

if(ENABLE_FAST_FLOAT)
  target_link_libraries(implementation PUBLIC fast_float)
endif()

if(ENABLE_FMT)
  target_link_libraries(implementation PUBLIC fmt)
endif()

if(ENABLE_GLAZE)
  target_link_libraries(implementation PUBLIC glaze::glaze)
endif()

if(ENABLE_PUGIXML)
  target_link_libraries(implementation PUBLIC pugixml)
endif()

if(ENABLE_TOMLPLUSPLUS)
  add_library(tomlplusplus INTERFACE)
  target_include_directories(tomlplusplus INTERFACE ${tomlplusplus_SOURCE_DIR}/include/)
  message("-- Added ${tomlplusplus_SOURCE_DIR}/include/ as include")
  target_link_libraries(implementation PUBLIC tomlplusplus)
endif()

if(ENABLE_YAML_CPP)
  target_link_libraries(implementation PUBLIC yaml-cpp)
endif()

if(ENABLE_STDUUID)
  target_link_libraries(implementation PUBLIC stduuid)
endif()

if(ENABLE_ARGPARSE)
  target_link_libraries(implementation PUBLIC argparse)
endif()

if(ENABLE_SPDLOG)
  target_link_libraries(implementation PUBLIC spdlog::spdlog)
endif()

add_executable(example example/main.cpp)
target_link_libraries(example PRIVATE implementation)

if(BUILD_TESTING)
  if(ENABLE_DOCTESTS)
    add_executable(tests
      test/test_main.cpp
      test/test_implementation.cpp)
    target_link_libraries(tests PRIVATE doctest::doctest implementation)
    add_test(NAME tests COMMAND tests)
  endif()

  if(ENABLE_CATCH2)
    add_executable(tests_catch2 test/test_implementation_catch2.cpp)
    target_link_libraries(tests_catch2 PRIVATE Catch2::Catch2WithMain implementation)
    add_test(NAME tests_catch2 COMMAND tests_catch2)
  endif()
endif()

include(gcovr)
include(execute_tests)
include(coverage)
include(analysis)
