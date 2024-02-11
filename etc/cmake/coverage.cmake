set(COVERAGE_FOLDER coverage/)
set(COVERAGE_FILTER_OPTIONS
    --exclude
    _deps
    --exclude
    ../test
    --exclude-unreachable-branches
    --decisions
    --html-details)
set(COVERAGE_INDEX_PATH ${CMAKE_BINARY_DIR}/${COVERAGE_FOLDER}coverage_details.html)
add_custom_target(
  coverage
  DEPENDS execute_tests
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Executing gcovr to process coverage - open ${COVERAGE_INDEX_PATH} to inspect results"
  COMMAND gcovr --config gcovr.cfg ${COVERAGE_FILTER_OPTIONS} -o ${COVERAGE_FOLDER} .)
message(STATUS "Added coverage target")
