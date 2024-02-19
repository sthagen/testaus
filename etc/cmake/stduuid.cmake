if(ENABLE_STDUUID)
  add_definitions(-DENABLE_STDUUID_IN_LIBRARY)
  set(STDUUID_TAG v1.2.3)
  FetchContent_Declare(
    stduuid
    GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
    GIT_TAG ${STDUUID_TAG} # commit 3afe7193facd5d674de709fccc44d5055e144d7a
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(stduuid)
  message(STATUS "stduuid ${STDUUID_TAG} enabled and loaded - use stduuid in your target_link_library calls")
endif()
