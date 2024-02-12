add_custom_target(execute_tests
  DEPENDS tests tests_catch2
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Running ctest to excute tests"
  COMMAND ctest --output-on-failure
)
message(STATUS "Added execute_tests target")
