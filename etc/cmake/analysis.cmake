set(ANALYSIS_FOLDER analysis/)
set(ANALYSIS_FILTER_OPTIONS
    --enable=all
    --suppress=missingIncludeSystem
    --inconclusive
    --inline-suppr
    --language=c++
    --std=c++20
    --xml)
set(ANALYSIS_FOLDER_PATH ${CMAKE_BINARY_DIR}/${ANALYSIS_FOLDER})
set(COVERAGE_IMPLEMENTATION
    mkdir
    -p
    ${ANALYSIS_FOLDER_PATH}
    &&
    cppcheck
    ${ANALYSIS_FILTER_OPTIONS}
    example/
    src/
    1>${ANALYSIS_FOLDER_PATH}cppcheck.log.txt
    2>${ANALYSIS_FOLDER_PATH}cppcheck.report.xml
    &&
    cppcheck-codequality
    -i
    ${ANALYSIS_FOLDER_PATH}cppcheck.report.xml
    -o
    ${ANALYSIS_FOLDER_PATH}cppcheck.report.json)
add_custom_target(
  analysis
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Running cppcheck for analysis - writing reports and logs to ${ANALYSIS_FOLDER_PATH}cppcheck.{log,report}.*"
  COMMAND ${COVERAGE_IMPLEMENTATION})
message(STATUS "Added analysis target")
