add_custom_target(process_coverage
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMENT "Running gcovr to process coverage results"
      COMMAND gcovr --config gcovr.cfg --exclude ../doctest --exclude ../main --exclude ../test_ --html-details -o coverage/ --exclude-unreachable-branches --decisions .
)
