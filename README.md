# doctest-gcovr-training

This repository demonstrates a possible structure and operation of tests, coverage, and analysis for C++ code.

The implementation is simplistic and is more a library as there is no real client code.
This results in warnings on unused functions, of course.

## Setup

We use some python based tools for coverage, analysis result transforms, and cmake files linting and formating:

Install these tools:

```console
% pip install -r test/requirements.txt
```

## Development

We use out-of-source builds to keep the repository clean and simple.

Configurations belong into `etc`. So, CMake modules are inside `etc/cmake/` and the gcovr configuration file template is inside `etc/`.

All results relate to a specific build type and thus are placed inside the selected build folder (selected by the developer initializing CMmake).

Using the default build backends and preparing coverage (leading to instrumented artifacts you will not want to deliver to production):

```console
% cmake -DCMAKE_BUILD_TYPE=Coverage -S . -B build-coverage -Wno-dev
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (2.3s)
-- Generating done (0.4s)
-- Build files have been written to: /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage
```

Using the Ninja backend and setting a release with debug symbols build type:

```console
% cmake -G Ninja -DCMAKE_BUILD_TYPE=ReleaseWithDeb -S . -B build -Wno-dev
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (2.8s)
-- Generating done (0.0s)
-- Build files have been written to: /Some/place/on/clone/machine/doctest-gcovr-training/build
```

After changes in anything impacting the build generator you can do the following (picking the coverage instrumented build type):

Build tests, execute tests, process the coverage, and generate a report:

```console
% cmake --build build-coverage --target coverage
[ 16%] Building CXX object CMakeFiles/implementation.dir/src/implementation.cpp.o
[ 33%] Linking CXX static library libimplementation.a
[ 33%] Built target implementation
[ 50%] Building CXX object CMakeFiles/tests.dir/test/test_implementation.cpp.o
[ 66%] Linking CXX executable tests
[ 66%] Built target tests
[ 83%] Running ctest to excute tests
Test project /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage
    Start 1: tests
1/1 Test #1: tests ............................   Passed    0.22 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.22 sec
[ 83%] Built target execute_tests
[100%] Executing gcovr to process coverage - open \
  /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage/coverage/coverage_details.html to inspect results
(INFO) - MainThread - Reading coverage data...
(INFO) - MainThread - Writing coverage report...
[100%] Built target coverage
```

Analyze the source code:

```console
% cmake --build build-coverage --target analysis
[100%] Running cppcheck for analysis - writing reports and logs to \
  /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage/analysis/cppcheck.{log,report}.*
[33] cppcheck_codequality INFO: No file location. Skipping the below issue:
  Active checkers: 172/592 (use --checkers-report=<filename> to see details)
[33] cppcheck_codequality INFO: Converted 3 CppCheck issues
[100%] Built target analysis
```

Display any analysis results (log and report):

```console
% bat /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage/analysis/cppcheck.{log,report}.*
───────┬──────────────────────────────────────────────────────────────────────────────────────────────────
       │ File: /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage/analysis/cppcheck.log.txt
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────
   1   │ Checking example/main.cpp ...
   2   │ 1/2 files checked 19% done
   3   │ Checking src/implementation.cpp ...
   4   │ 2/2 files checked 100% done
───────┴──────────────────────────────────────────────────────────────────────────────────────────────────
───────┬──────────────────────────────────────────────────────────────────────────────────────────────────
       │ File: /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage/analysis/cppcheck.report.json
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────
   1   │ [{"type": "issue", "severity": "minor", "check_name": "cppcheck[duplicateBreak]", "description":
       │ "Consecutive return, break, continue, goto or throw statements are unnecessary. (CWE-561)", "cate
       │ gories": ["Style"], "fingerprint": "01233e41246747993fa03469a2b5bf7e", "location": {"path": "src/
       │ implementation.cpp", "positions": {"begin": {"line": 57, "column": 13}}}, "content": {"body": ""}
       │ }, {"type": "issue", "severity": "minor", "check_name": "cppcheck[unusedFunction]", "description"
       │ : "The function 'spread_logic' is never used. (CWE-561)", "categories": ["Style"], "fingerprint":
       │  "6afadc466183a1f2f53e2c0829e4a9fb", "location": {"path": "src/implementation.cpp", "positions":
       │ {"begin": {"line": 7, "column": 0}}}, "content": {"body": ""}}, {"type": "issue", "severity": "mi
       │ nor", "check_name": "cppcheck[unusedFunction]", "description": "The function 'switch_logic' is ne
       │ ver used. (CWE-561)", "categories": ["Style"], "fingerprint": "b9f9d46be398dbf597620e7794dd945d",
       │  "location": {"path": "src/implementation.cpp", "positions": {"begin": {"line": 23, "column": 0}}
       │ }, "content": {"body": ""}}]
───────┴──────────────────────────────────────────────────────────────────────────────────────────────────
───────┬──────────────────────────────────────────────────────────────────────────────────────────────────
       │ File: /Some/place/on/clone/machine/doctest-gcovr-training/build-coverage/analysis/cppcheck.report.xml
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────
   1   │ <?xml version="1.0" encoding="UTF-8"?>
   2   │ <results version="2">
   3   │     <cppcheck version="2.13.0"/>
   4   │     <errors>
   5   │         <error id="duplicateBreak" severity="style" msg="Consecutive return, break, continue, got
       │ o or throw statements are unnecessary." verbose="Consecutive return, break, continue, goto or thr
       │ ow statements are unnecessary. The second statement can never be executed, and so should be remov
       │ ed." cwe="561" file0="src/implementation.cpp">
   6   │             <location file="src/implementation.cpp" line="57" column="13"/>
   7   │         </error>
   8   │         <error id="unusedFunction" severity="style" msg="The function &apos;spread_logic&apos; is
       │  never used." verbose="The function &apos;spread_logic&apos; is never used." cwe="561">
   9   │             <location file="src/implementation.cpp" line="7" column="0"/>
  10   │             <symbol>spread_logic</symbol>
  11   │         </error>
  12   │         <error id="unusedFunction" severity="style" msg="The function &apos;switch_logic&apos; is
       │  never used." verbose="The function &apos;switch_logic&apos; is never used." cwe="561">
  13   │             <location file="src/implementation.cpp" line="23" column="0"/>
  14   │             <symbol>switch_logic</symbol>
  15   │         </error>
  16   │         <error id="checkersReport" severity="information" msg="Active checkers: 172/592 (use --ch
       │ eckers-report=&lt;filename&gt; to see details)" verbose="Active checkers: 172/592 (use --checkers
       │ -report=&lt;filename&gt; to see details)"/>
  17   │     </errors>
  18   │ </results>
───────┴──────────────────────────────────────────────────────────────────────────────────────────────────
```

## Status

Experimental.

**Note**: The default branch is `default`.
