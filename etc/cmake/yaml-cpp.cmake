if(ENABLE_YAML_CPP)
  add_definitions(-DENABLE_YAML_CPP_IN_LIBRARY)
  set(YAML_CPP_TAG 0.8.0)
  FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG ${YAML_CPP_TAG} # commit f7320141120f720aecc4c32be25586e7da9eb978
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(yaml-cpp)
  message(STATUS "yaml-cpp ${YAML_CPP_TAG} enabled and loaded - use yaml-cpp in your target_link_library calls")
endif()
