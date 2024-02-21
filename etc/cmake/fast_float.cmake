if(ENABLE_FAST_FLOAT)
  add_definitions(-DENABLE_FMT_IN_LIBRARY)
  set(FAST_FLOAT_TAG v6.1.0)
  FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fastfloat/fast_float.git
    GIT_TAG ${FAST_FLOAT_TAG} # commit 8378916ed814bebc4bcbf519c66f7c38c8374594
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(fmt)
  message(STATUS "fast_float ${FAST_FLOAT_TAG} enabled and loaded - use fast_float in your target_link_library calls")
endif()