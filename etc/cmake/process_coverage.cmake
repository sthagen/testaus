add_custom_target(process_coverage
      DEPENDS run_tests
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMENT "Running gcovr to process coverage results"
      COMMAND gcovr --config gcovr.cfg --exclude _deps --exclude ../test --html-details -o coverage/ --exclude-unreachable-branches --decisions .
)
