set(analysis_folder analysis/)
set(analysis_filter_options --enable=all --suppress=missingIncludeSystem --inconclusive --inline-suppr --language=c++ --std=c++20 --xml)
set(analysis_folder_path ${CMAKE_BINARY_DIR}/${analysis_folder})
set(coverage_implementation mkdir -p ${analysis_folder_path} && cppcheck ${analysis_filter_options} example/ src/ 1>${analysis_folder_path}cppcheck.log.txt 2>${analysis_folder_path}cppcheck.report.xml && cppcheck-codequality -i ${analysis_folder_path}cppcheck.report.xml -o ${analysis_folder_path}cppcheck.report.json)
add_custom_target(analysis
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Running cppcheck for analysis - writing reports and logs to ${analysis_folder_path}cppcheck.{log,report}.*"
  COMMAND ${coverage_implementation}
)
message(STATUS "Added analysis target")
