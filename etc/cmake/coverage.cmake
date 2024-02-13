set(COVERAGE_FOLDER coverage/)
set(COVERAGE_FOLDER_PATH ${CMAKE_BINARY_DIR}/${COVERAGE_FOLDER})
set(COVERAGE_FILTER_OPTIONS
    --exclude
    _deps
    --exclude
    ../test
    --exclude-unreachable-branches
    --decisions
    --json-pretty
    --json
    --json-summary-pretty
    --json-summary
    --html-details)
set(COVERAGE_IMPLEMENTATION
    gcovr
    --config
    gcovr.cfg
    ${COVERAGE_FILTER_OPTIONS}
    -o
    ${COVERAGE_FOLDER}
    .)
set(COVERAGE_INDEX_PATH ${COVERAGE_FOLDER_PATH}coverage_details.html)
add_custom_target(
  coverage
  DEPENDS execute_tests
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Executing gcovr to process coverage - open ${COVERAGE_INDEX_PATH} to inspect results"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/${COVERAGE_FOLDER}"
  COMMAND ${COVERAGE_IMPLEMENTATION})
message(STATUS "Added coverage target")
