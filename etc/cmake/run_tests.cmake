add_custom_target(run_tests
      DEPENDS tests
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMENT "Running ctest to generate coverage data"
      COMMAND ctest
)
