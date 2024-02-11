if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
      execute_process(
          COMMAND xcrun --find gcov
          OUTPUT_VARIABLE GCOV_EXECUTABLE
          OUTPUT_STRIP_TRAILING_WHITESPACE
      )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
      find_program(LLVM_COV_EXECUTABLE llvm-cov REQUIRED)
      file(CREATE_LINK ${LLVM_COV_EXECUTABLE} ${CMAKE_BINARY_DIR}/gcov SYMBOLIC)
      set(GCOV_EXECUTABLE "${LLVM_COV_EXECUTABLE} gcov")
else()  # Assuming gcc for this example
      find_program(GCOV_EXECUTABLE gcov REQUIRED)
endif()
configure_file(etc/gcovr.cfg.in gcovr.cfg @ONLY)
message(STATUS "gcovr configured (cf. build/gcovr.cfg)")
