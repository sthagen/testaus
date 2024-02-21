if(ENABLE_BENCHMARK)
  add_definitions(-DENABLE_BENCHMARK_IN_LIBRARY)
  set(BENCHMARK_TAG v1.8.3)
  FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG ${BENCHMARK_TAG} # commit 344117638c8ff7e239044fd0fa7085839fc03021
    GIT_SHALLOW TRUE
    OPTIONS
      "BENCHMARK_ENABLE_GTEST_TESTS OFF"
      "BENCHMARK_ENABLE_TESTING OFF"
      "BENCHMARK_USE_BUNDLED_GTEST OFF"
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(benchmark)
  message(STATUS "benchmark ${BENCHMARK_TAG} enabled and loaded - use benchmark in your target_link_library calls")
endif()
