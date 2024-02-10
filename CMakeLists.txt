cmake_minimum_required(VERSION 3.15...3.28)

project(
  doctest-covr-training
  VERSION 2024.2.10
  DESCRIPTION "Small multiple files doctest with gcovr training example."
  LANGUAGES CXX)

enable_testing()

# Require C++20, but let a parent project ask for something higher
if(DEFINED CMAKE_CXX_STANDARD)
  if(CMAKE_CXX_STANDARD MATCHES "^(90|99)$" OR CMAKE_CXX_STANDARD LESS 20)
    message(FATAL_ERROR "This project requires at least C++20")
  endif()
else()
  set(CMAKE_CXX_STANDARD 20)
endif()

# Always enforce the language constraint
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# We don't need compiler extensions, but let a parent ask for them
if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

include(FetchContent)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG v2.4.11 # commit ae7a13539fb71f270b87eb2e874fbac80bc8dda2
  FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(doctest)

add_library(implementation STATIC implementation.cpp)

add_executable(tests test_implementation.cpp)
target_link_libraries(tests PRIVATE doctest::doctest implementation)
