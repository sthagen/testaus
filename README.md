# Testaus

Testing (Finnish: testaus) is simple - legacy code is code without tests.

[![License](https://git.sr.ht/~sthagen/testaus/blob/default/docs/badges/license-spdx-mit.svg)](https://git.sr.ht/~sthagen/testaus/tree/default/item/LICENSE)
[![Country of Origin](https://git.sr.ht/~sthagen/testaus/blob/default/docs/badges/country-of-origin-name-switzerland-neutral.svg)](https://git.sr.ht/~sthagen/testaus/tree/default/item/COUNTRY-OF-ORIGIN)
[![Export Classification Control Number (ECCN)](https://git.sr.ht/~sthagen/testaus/blob/default/docs/badges/export-control-classification-number_eccn-ear99-neutral.svg)](https://git.sr.ht/~sthagen/testaus/tree/default/item/EXPORT-CONTROL-CLASSIFICATION-NUMBER)
[![Version](https://git.sr.ht/~sthagen/testaus/blob/default/docs/badges/latest-release.svg)](https://git.sr.ht/~sthagen/testaus/tree/default/item/VERSION)

This repository demonstrates a possible structure and operation of tests, coverage, and analysis for C++ code.

The implementation is simplistic and is more a library as there is no real client code.
This results in warnings on unused functions, of course.

## Bug Tracker

Any feature requests or bug reports shall go to the [todos of testaus](https://todo.sr.ht/~sthagen/testaus).

## Primary Source repository

The main source of `testaus` is on a mountain in central Switzerland.
We use distributed version control (git).
There is no central hub.
Every clone can become a new source for the benefit of all.
The preferred public clone of `testaus` is:

* [at sourcehut](https://git.sr.ht/~sthagen/testaus) - a collection of tools useful for software development.

## Contributions

Please do not submit "pull requests" (I found no way to disable that "feature" on GitHub).
If you like to share small changes under the repositories license please kindly do so by sending a patchset.
You can either send such a patchset per email using [git send-email](https://git-send-email.io) or
if you are a sourcehut user by selecting "Prepare a patchset" on the summary page of your fork at [sourcehut](https://git.sr.ht/).

## Support

Please kindly submit issues at https://todo.sr.ht/~sthagen/testaus or write plain text email to ~sthagen/testaus@lists.sr.ht to submit patches and request support. Thanks.

## Development

### Quickstart

There is a top level `Makefile` which you can use to bootstrap and trigger CMake commands:

Initialize the workspace after clone of this repository:

```console
% make setup
pip install -r test/requirements.txt
Collecting cmakelang==0.6.13 (from -r test/requirements.txt (line 1))
  Using cached cmakelang-0.6.13-py3-none-any.whl (159 kB)
Collecting gcovr==7.0 (from -r test/requirements.txt (line 2))
  Using cached gcovr-7.0-py2.py3-none-any.whl.metadata (9.5 kB)
Collecting cppcheck-codequality==1.4.1 (from -r test/requirements.txt (line 3))
  Using cached cppcheck_codequality-1.4.1-py3-none-any.whl.metadata (4.9 kB)
Requirement already satisfied: six>=1.13.0 in /some/local/python/install/site-packages (from cmakelang==0.6.13->-r test/requirements.txt (line 1)) (1.16.0)
Requirement already satisfied: jinja2 in /some/local/python/install/site-packages (from gcovr==7.0->-r test/requirements.txt (line 2)) (3.1.3)
Requirement already satisfied: lxml in /some/local/python/install/site-packages (from gcovr==7.0->-r test/requirements.txt (line 2)) (5.1.0)
Requirement already satisfied: pygments>=2.13.0 in /some/local/python/install/site-packages (from gcovr==7.0->-r test/requirements.txt (line 2)) (2.17.2)
Requirement already satisfied: xmltodict<0.14.0,>=0.13.0 in /some/local/python/install/site-packages (from cppcheck-codequality==1.4.1->-r test/requirements.txt (line 3)) (0.13.0)
Requirement already satisfied: MarkupSafe>=2.0 in /some/local/python/install/site-packages (from jinja2->gcovr==7.0->-r test/requirements.txt (line 2)) (2.1.5)
Using cached gcovr-7.0-py2.py3-none-any.whl (194 kB)
Using cached cppcheck_codequality-1.4.1-py3-none-any.whl (13 kB)
Installing collected packages: cppcheck-codequality, cmakelang, gcovr
Successfully installed cmakelang-0.6.13 cppcheck-codequality-1.4.1 gcovr-7.0
cmake -G Ninja -DCMAKE_BUILD_TYPE=Coverage -S . -B build-coverage -Wno-dev
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build_coverage__deps_catch2_src__
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build_coverage__deps_catch2_src__ - Success
-- catch2 v3.5.2 enabled and loaded - use e.g. Catch2::Catch2WithMain in your target_link_library call(s)
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (7.0s)
-- Generating done (0.0s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build-coverage
cmake -G Ninja -DCMAKE_BUILD_TYPE=ReleaseWithDeb -S . -B build -Wno-dev
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build__deps_catch2_src__
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build__deps_catch2_src__ - Success
-- catch2 v3.5.2 enabled and loaded - use e.g. Catch2::Catch2WithMain in your target_link_library call(s)
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (6.5s)
-- Generating done (0.0s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build
```

Running the example (without coverage instrumentation):

```console
% make example
cmake --build build --target example
[4/4] Linking CXX executable example
Please enter three integers separated by spaces: Thanks. Got it.
 triple_max(1, 2, 3) = 3
```

Static analysis of implementation:

```console
% make analysis
cmake --build build-coverage --target analysis
[1/1] Running cppcheck for analysis - writing reports and logs to /Some/place/on/clone/machine/testaus/build-coverage/analysis/cppcheck.{log,report}.*
[36] cppcheck_codequality INFO: No file location. Skipping the below issue:
  Active checkers: 172/592 (use --checkers-report=<filename> to see details)
[37] cppcheck_codequality INFO: Converted 3 CppCheck issues
[
    {
        "type": "issue",
        "severity": "minor",
        "check_name": "cppcheck[duplicateBreak]",
        "description": "Consecutive return, break, continue, goto or throw statements are unnecessary. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "01233e41246747993fa03469a2b5bf7e",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 57,
                    "column": 13
                }
            }
        },
        "content": {
            "body": ""
        }
    },
    {
        "type": "issue",
        "severity": "minor",
        "check_name": "cppcheck[unusedFunction]",
        "description": "The function 'spread_logic' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "6afadc466183a1f2f53e2c0829e4a9fb",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 7,
                    "column": 0
                }
            }
        },
        "content": {
            "body": ""
        }
    },
    {
        "type": "issue",
        "severity": "minor",
        "check_name": "cppcheck[unusedFunction]",
        "description": "The function 'switch_logic' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "b9f9d46be398dbf597620e7794dd945d",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 23,
                    "column": 0
                }
            }
        },
        "content": {
            "body": ""
        }
    }
]
```

Coverage target (implies building and executing the tests):

```console
% make coverage
cmake --build build-coverage --target coverage
[116/117] Running ctest to excute tests
Test project /Some/place/on/clone/machine/testaus/build-coverage
    Start 1: tests
1/2 Test #1: tests ............................   Passed    0.22 sec
    Start 2: tests_catch2
2/2 Test #2: tests_catch2 .....................   Passed    0.14 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.36 sec
[117/117] Executing gcovr to process coverage - open /Some/place/on/clone/machine/testaus/build-coverage/coverage/coverage_details.html to inspect results
(INFO) - MainThread - Reading coverage data...
(INFO) - MainThread - Writing coverage report...
{
    "branch_covered": 14,
    "branch_percent": 100.0,
    "branch_total": 14,
    "files": [
        {
            "branch_covered": 14,
            "branch_percent": 100.0,
            "branch_total": 14,
            "filename": "src/implementation.cpp",
            "function_covered": 3,
            "function_percent": 100.0,
            "function_total": 3,
            "line_covered": 19,
            "line_percent": 100.0,
            "line_total": 19
        }
    ],
    "function_covered": 3,
    "function_percent": 100.0,
    "function_total": 3,
    "gcovr/summary_format_version": "0.5",
    "line_covered": 19,
    "line_percent": 100.0,
    "line_total": 19,
    "root": "../.."
}
```

Note, that the Makefile has a rather simplistic idea on how to open an html file in a browser: it calls `open`.
This works fine on some systems, others prefer to call `start`.

### CMake Only Start (and Python)

We use some python based tools for coverage, analysis result transforms, and cmake files linting and formating:

As always it is best to use a modern python (that should be python 3.12 in 2024) and
a local virtual environment to isolate the needs of this repository from all other installs on the machine you cloned onto.
Please find else where how to do that. Some use simply `python -m venv my-env-name` others already have `pyenv` or ... in place to
construct such virtual environments.

Install these tools into the python environment of your choice:

```console
% pip install -r test/requirements.txt
```

We use out-of-source builds to keep the repository clean and simple.

Configurations belong into `etc`. So, CMake modules are inside `etc/cmake/` and the gcovr configuration file template is inside `etc/`.

All results relate to a specific build type and thus are placed inside the selected build folder (selected by the developer initializing CMmake).

Using the default generator as generator and preparing coverage (leading to instrumented artifacts you will not want to deliver to production):

```console
% cmake -DCMAKE_BUILD_TYPE=Coverage -S . -B build-coverage -Wno-dev
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build_coverage__deps_catch2_src__
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build_coverage__deps_catch2_src__ - Success
-- catch2 v3.5.2 enabled and loaded - use e.g. Catch2::Catch2WithMain in your target_link_library call(s)
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (6.9s)
-- Generating done (0.5s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build-coverage
```

Using the `Ninja` backend and setting a release with debug symbols build type:

```console
% cmake -G Ninja -DCMAKE_BUILD_TYPE=ReleaseWithDeb -S . -B build -Wno-dev
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build__deps_catch2_src__
-- Performing Test HAVE_FLAG__ffile_prefix_map__Some_place_on_clone_machine_testaus_build__deps_catch2_src__ - Success
-- catch2 v3.5.2 enabled and loaded - use e.g. Catch2::Catch2WithMain in your target_link_library call(s)
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (6.6s)
-- Generating done (0.0s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build
```

After changes in anything impacting the build generator you can do the following (picking the coverage instrumented build type):

Build tests, execute tests, process the coverage, and generate a report (default generator `UNIX Makefiles` on some machine
causes lengthy build - duration as well as log):

```console
% cmake --build build-coverage --target coverage
[  0%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/benchmark/catch_chronometer.cpp.o
[  1%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/benchmark/detail/catch_analyse.cpp.o
[  2%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/benchmark/detail/catch_benchmark_function.cpp.o
[  3%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/benchmark/detail/catch_run_for_at_least.cpp.o
[  4%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/benchmark/detail/catch_stats.cpp.o
[  4%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/generators/catch_generator_exception.cpp.o
[  5%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/generators/catch_generators.cpp.o
[  6%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/generators/catch_generators_random.cpp.o
[  7%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_automake.cpp.o
[  8%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_common_base.cpp.o
[  9%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_compact.cpp.o
[  9%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_console.cpp.o
[ 10%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_cumulative_base.cpp.o
[ 11%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_event_listener.cpp.o
[ 12%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_helpers.cpp.o
[ 13%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_json.cpp.o
[ 13%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_junit.cpp.o
[ 14%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_multi.cpp.o
[ 15%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_registrars.cpp.o
[ 16%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_sonarqube.cpp.o
[ 17%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_streaming_base.cpp.o
[ 18%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_tap.cpp.o
[ 18%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_teamcity.cpp.o
[ 20%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/reporters/catch_reporter_xml.cpp.o
[ 21%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_capture.cpp.o
[ 22%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_config.cpp.o
[ 23%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_exception.cpp.o
[ 23%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_generatortracker.cpp.o
[ 24%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_registry_hub.cpp.o
[ 25%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_reporter.cpp.o
[ 26%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_reporter_factory.cpp.o
[ 27%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/interfaces/catch_interfaces_testcase.cpp.o
[ 28%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_approx.cpp.o
[ 28%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_assertion_result.cpp.o
[ 29%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_config.cpp.o
[ 30%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_get_random_seed.cpp.o
[ 31%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_message.cpp.o
[ 32%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_registry_hub.cpp.o
[ 32%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_session.cpp.o
[ 33%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_tag_alias_autoregistrar.cpp.o
[ 34%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_test_case_info.cpp.o
[ 35%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_test_spec.cpp.o
[ 36%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_timer.cpp.o
[ 37%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_tostring.cpp.o
[ 37%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_totals.cpp.o
[ 38%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_translate_exception.cpp.o
[ 40%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/catch_version.cpp.o
[ 41%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_assertion_handler.cpp.o
[ 42%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_case_insensitive_comparisons.cpp.o
[ 42%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_clara.cpp.o
[ 43%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_commandline.cpp.o
[ 44%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_console_colour.cpp.o
[ 45%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_context.cpp.o
[ 46%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_debug_console.cpp.o
[ 47%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_debugger.cpp.o
[ 47%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_decomposer.cpp.o
[ 48%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_enforce.cpp.o
[ 49%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_enum_values_registry.cpp.o
[ 50%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_errno_guard.cpp.o
[ 51%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_exception_translator_registry.cpp.o
[ 52%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_fatal_condition_handler.cpp.o
[ 52%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_floating_point_helpers.cpp.o
[ 53%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_getenv.cpp.o
[ 54%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_istream.cpp.o
[ 55%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_jsonwriter.cpp.o
[ 56%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_lazy_expr.cpp.o
[ 56%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_leak_detector.cpp.o
[ 57%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_list.cpp.o
[ 58%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_message_info.cpp.o
[ 60%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_output_redirect.cpp.o
[ 61%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_parse_numbers.cpp.o
[ 62%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_polyfills.cpp.o
[ 62%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_random_number_generator.cpp.o
[ 63%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_random_seed_generation.cpp.o
[ 64%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_reporter_registry.cpp.o
[ 65%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_reporter_spec_parser.cpp.o
[ 66%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_result_type.cpp.o
[ 66%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_reusable_string_stream.cpp.o
[ 67%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_run_context.cpp.o
[ 68%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_section.cpp.o
[ 69%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_singletons.cpp.o
[ 70%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_source_line_info.cpp.o
[ 71%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_startup_exception_registry.cpp.o
[ 71%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_stdstreams.cpp.o
[ 72%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_string_manip.cpp.o
[ 73%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_stringref.cpp.o
[ 74%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_tag_alias_registry.cpp.o
[ 75%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_test_case_info_hasher.cpp.o
[ 75%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_test_case_registry_impl.cpp.o
[ 76%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_test_case_tracker.cpp.o
[ 77%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_test_failure_exception.cpp.o
[ 78%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_test_registry.cpp.o
[ 80%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_test_spec_parser.cpp.o
[ 81%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_textflow.cpp.o
[ 81%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_uncaught_exceptions.cpp.o
[ 82%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_wildcard_pattern.cpp.o
[ 83%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/internal/catch_xmlwriter.cpp.o
[ 84%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers.cpp.o
[ 85%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_container_properties.cpp.o
[ 85%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_exception.cpp.o
[ 86%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_floating_point.cpp.o
[ 87%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_predicate.cpp.o
[ 88%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_quantifiers.cpp.o
[ 89%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_string.cpp.o
[ 90%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/catch_matchers_templated.cpp.o
[ 90%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2.dir/catch2/matchers/internal/catch_matchers_impl.cpp.o
[ 91%] Linking CXX static library libCatch2.a
[ 91%] Built target Catch2
[ 92%] Building CXX object _deps/catch2-build/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.o
[ 93%] Linking CXX static library libCatch2Main.a
[ 93%] Built target Catch2WithMain
[ 93%] Building CXX object CMakeFiles/implementation.dir/src/implementation.cpp.o
[ 94%] Linking CXX static library libimplementation.a
[ 94%] Built target implementation
[ 95%] Building CXX object CMakeFiles/tests_catch2.dir/test/test_implementation_catch2.cpp.o
[ 96%] Linking CXX executable tests_catch2
[ 96%] Built target tests_catch2
[ 97%] Building CXX object CMakeFiles/tests.dir/test/test_implementation.cpp.o
[ 98%] Linking CXX executable tests
[ 98%] Built target tests
[100%] Running ctest to excute tests
Test project /Some/place/on/clone/machine/testaus/build-coverage
    Start 1: tests
1/2 Test #1: tests ............................   Passed    0.21 sec
    Start 2: tests_catch2
2/2 Test #2: tests_catch2 .....................   Passed    0.15 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.37 sec
[100%] Built target execute_tests
[100%] Executing gcovr to process coverage - open /Some/place/on/clone/machine/testaus/build-coverage/coverage/coverage_details.html to inspect results
(INFO) - MainThread - Reading coverage data...
(INFO) - MainThread - Writing coverage report...
[100%] Built target coverage
```

Analyze the source code (static analyzer cppcheck in this case):

```console
% cmake --build build-coverage --target analysis
[100%] Running cppcheck for analysis - writing reports and logs to /Some/place/on/clone/machine/testaus/build-coverage/analysis/cppcheck.{log,report}.*
[34] cppcheck_codequality INFO: No file location. Skipping the below issue:
  Active checkers: 172/592 (use --checkers-report=<filename> to see details)
[34] cppcheck_codequality INFO: Converted 3 CppCheck issues
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
