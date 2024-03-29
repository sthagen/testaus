if(ENABLE_COVERAGE)
  if(PROJECT_IS_TOP_LEVEL AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS_COVERAGE " -g -O0 --coverage ")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      string(APPEND CMAKE_CXX_FLAGS_COVERAGE
             " -fkeep-inline-functions -fprofile-abs-path -fno-inline -fno-default-inline -fno-inline-small-functions ")
    endif()
    set(CMAKE_EXE_LINKER_FLAGS_COVERAGE " --coverage ")
    set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE " --coverage ")
    set(CMAKE_MODULE_LINKER_FLAGS_COVERAGE " --coverage ")
    message(STATUS "coverage options set - use include(gcovr) or similar for processing of test coverage data")
  else()
    message(
      WARNING
        "coverage option setting failed, but either not top level or compiler with id(${CMAKE_CXX_COMPILER_ID}) unknown"
    )
  endif()
endif()
