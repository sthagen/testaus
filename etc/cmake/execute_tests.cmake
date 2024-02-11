add_custom_target(execute_tests
  DEPENDS tests
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Running ctest to excute tests"
  COMMAND ctest
)
message(STATUS "Added execute_tests target")
