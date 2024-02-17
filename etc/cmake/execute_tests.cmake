add_custom_target(execute_tests
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Running ctest to excute tests"
  COMMAND ctest --output-on-failure
)

if(ENABLE_DOCTESTS)
  add_dependencies(execute_tests tests)
endif()
if(ENABLE_CATCH2)
  add_dependencies(execute_tests tests_catch2)
endif()

message(STATUS "Added execute_tests target")
