if(ENABLE_FMT)
  add_definitions(-DENABLE_FMT_IN_LIBRARY)
  set(FMT_TAG 10.2.1)
  FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG ${FMT_TAG} # commit e69e5f977d458f2650bb346dadf2ad30c5320281
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(fmt)
  message(STATUS "fmt ${FMT_TAG} enabled and loaded - use fmt in your target_link_library calls")
endif()