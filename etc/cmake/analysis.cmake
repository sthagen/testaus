add_custom_target(analysis
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Running cppcheck for analysis - writing XML report to build/cppcheck.report.xml"
  COMMAND cppcheck example/ src/ --enable=all --suppress=missingIncludeSystem --inconclusive --inline-suppr --language=c++ --std=c++20 --xml ../src 1>build/cppcheck.log.txt 2>build/cppcheck.report.xml && cppcheck-codequality -i build/cppcheck.report.xml -o build/cppcheck.report.json
)
message(STATUS "Added analysis target")
