if(ENABLE_PUGIXML)
  add_definitions(-DENABLE_PUGIXML_IN_LIBRARY)
  set(PUGIXML_TAG v1.14)
  FetchContent_Declare(
    pugixml
    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    GIT_TAG ${PUGIXML_TAG} # commit db78afc2b7d8f043b4bc6b185635d949ea2ed2a8
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS)

  FetchContent_MakeAvailable(pugixml)
  message(STATUS "pugixml ${PUGIXML_TAG} enabled and loaded - use pugixml in your target_link_library calls")
endif()
