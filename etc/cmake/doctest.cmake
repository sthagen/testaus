if(ENABLE_DOCTESTS)
  add_definitions(-DENABLE_DOCTEST_IN_LIBRARY)
  FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG v2.4.11 # commit ae7a13539fb71f270b87eb2e874fbac80bc8dda2
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(doctest)
  message(STATUS "doctest enabled and loaded - use doctest::doctest in your target_link_library calls")
endif()
