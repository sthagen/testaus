if(ENABLE_CATCH2)
  add_definitions(-DENABLE_CATCH2_IN_LIBRARY)
  set(CATCH2_TAG v3.5.2)
  FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG ${CATCH2_TAG} # commit 05e10dfccc28c7f973727c54f850237d07d5e10f
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(catch2)
  message(STATUS "catch2 ${CATCH2_TAG} enabled and loaded - use e.g. Catch2::Catch2WithMain in your target_link_library call(s)")
endif()
