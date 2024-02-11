add_custom_target(coverage
  DEPENDS run_tests
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Running gcovr to process coverage - open build/coverage/coverage_details.html to inspect results"
  COMMAND gcovr --config gcovr.cfg --exclude _deps --exclude ../test --html-details -o coverage/ --exclude-unreachable-branches --decisions .
)
message(STATUS "Added coverage target")
