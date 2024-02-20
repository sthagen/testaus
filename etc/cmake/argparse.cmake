if(ENABLE_ARGPARSE)
  add_definitions(-DENABLE_ARGPARSE_IN_LIBRARY)
  set(ARGPARSE_TAG v3.0)
  FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
    GIT_TAG ${ARGPARSE_TAG} # commit af442b4da0cd7a07b56fa709bd16571889dc7fda
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(argparse)
  message(STATUS "argparse ${ARGPARSE_TAG} enabled and loaded - use argparse in your target_link_library calls")
endif()
