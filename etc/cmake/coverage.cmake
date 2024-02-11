set(coverage_folder coverage/)
set(coverage_filter_options --exclude _deps --exclude ../test --exclude-unreachable-branches --decisions --html-details)
set(coverage_index_path ${CMAKE_BINARY_DIR}/${coverage_folder}coverage_details.html)
add_custom_target(coverage
  DEPENDS execute_tests
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Executing gcovr to process coverage - open ${coverage_index_path} to inspect results"
  COMMAND gcovr --config gcovr.cfg ${coverage_filter_options} -o ${coverage_folder} .
)
message(STATUS "Added coverage target")
