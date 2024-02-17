if(ENABLE_GLAZE)
  add_definitions(-DENABLE_GLAZE_IN_LIBRARY)
  set(GLAZE_TAG v2.1.4)
  FetchContent_Declare(
    glaze
    GIT_REPOSITORY https://github.com/stephenberry/glaze.git
    GIT_TAG ${GLAZE_TAG} # commit 39ca20905ad1746864501c431a298746c65eaef3
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(glaze)
  message(STATUS "glaze ${GLAZE_TAG} enabled and loaded - use glaze::glaze in your target_link_library calls")
endif()
