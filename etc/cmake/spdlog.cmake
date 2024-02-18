if(ENABLE_SPDLOG)
  add_definitions(-DENABLE_SPDLOG_IN_LIBRARY)
  set(SPDLOG_TAG v1.13.0)
  FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG ${SPDLOG_TAG} # commit 7c02e204c92545f869e2f04edaab1f19fe8b19fd
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(spdlog)
  message(STATUS "spdlog ${SPDLOG_TAG} enabled and loaded - use spdlog::spdlog in your target_link_library calls")
endif()
