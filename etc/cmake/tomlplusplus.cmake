if(ENABLE_TOMLPLUSPLUS)
  add_definitions(-DENABLE_TOMLPLUSPLUS_IN_LIBRARY)
  set(TOMLPLUSPLUS_TAG v3.4.0)
  FetchContent_Declare(
    tomplpusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG ${TOMLPLUSPLUS_TAG} # commit 30172438cee64926dc41fdd9c11fb3ba5b2ba9de
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(tomplpusplus)
  message(STATUS "tomplpusplus ${TOMLPLUSPLUS_TAG} enabled and loaded - use tomplpusplus in your target_link_library calls")
endif()
