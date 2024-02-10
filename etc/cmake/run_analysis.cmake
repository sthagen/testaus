add_custom_target(run_analysis
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      COMMENT "Running cppcheck for static analysis"
      COMMAND cppcheck implementation.*
)
