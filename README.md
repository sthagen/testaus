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

The content of the `etc` directory tree and the top level cmake lists file is the backbone of this repository.

```console
❯ tree etc
etc
├── cmake
│   ├── analysis.cmake
│   ├── catch2.cmake
│   ├── coverage.cmake
│   ├── coverage_compiler_options.cmake
│   ├── cxx_language_version.cmake
│   ├── doctest.cmake
│   ├── execute_tests.cmake
│   ├── gcovr.cmake
│   ├── glaze.cmake
│   ├── pugixml.cmake
│   ├── spdlog.cmake
│   ├── stduuid.cmake
│   ├── tomlplusplus.cmake
│   └── yaml-cpp.cmake
└── gcovr
    └── gcovr.cfg.in

3 directories, 15 files
```

The other directories are suggestions that we have to make as the cmake dance requires specific names.

The header and implementation files are only examples to show coverage and static analysis mechanisms.

### TL; DR;

Executing the following command should clearly expose most material to inspect and provide a working starter example.

```console
make distclean setup coverage analysis
```

Executing this command on some random developer machine takes around 30 seconds.
In case you are in an enterprise compute environment this duration can easily become more than 10 minutes depending on the endpoint security tools.

Note: The existing `test/test_implementation_catch2.cpp` file is not used, because of the switch in the top level cmake lists file. That test file - if solely enabled instead of doctest harness - should result in very poor coverage.

### Quickstart

There is a top level `Makefile` which you can use to bootstrap and trigger CMake commands:

Initialize the workspace after clone of this repository:

```console
❯ make setup
pip install -r test/requirements.txt
Requirement already satisfied: cmakelang==0.6.13 in /some/local/python/install/site-packages (from -r test/requirements.txt (line 1)) (0.6.13)
Requirement already satisfied: gcovr==7.0 in //some/local/python/install/site-packages (from -r test/requirements.txt (line 2)) (7.0)
Requirement already satisfied: cppcheck-codequality==1.4.1 in /some/local/python/install/site-packages (from -r test/requirements.txt (line 3)) (1.4.1)
Requirement already satisfied: six>=1.13.0 in /some/local/python/install/site-packages (from cmakelang==0.6.13->-r test/requirements.txt (line 1)) (1.16.0)
Requirement already satisfied: jinja2 in /some/local/python/install/site-packages (from gcovr==7.0->-r test/requirements.txt (line 2)) (3.1.3)
Requirement already satisfied: lxml in /some/local/python/install/site-packages (from gcovr==7.0->-r test/requirements.txt (line 2)) (5.1.0)
Requirement already satisfied: pygments>=2.13.0 in /some/local/python/install/site-packages (from gcovr==7.0->-r test/requirements.txt (line 2)) (2.17.2)
Requirement already satisfied: xmltodict<0.14.0,>=0.13.0 in /some/local/python/install/site-packages (from cppcheck-codequality==1.4.1->-r test/requirements.txt (line 3)) (0.13.0)
Requirement already satisfied: MarkupSafe>=2.0 in /some/local/python/install/site-packages (from jinja2->gcovr==7.0->-r test/requirements.txt (line 2)) (2.1.5)
cmake -G Ninja -DCMAKE_BUILD_TYPE=Coverage -S . -B build-coverage -Wno-dev
-- ENABLE_DOCTESTS is (ON)
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- ENABLE_CATCH2 is (OFF)
-- ENABLE_GLAZE is (ON)
-- glaze v2.1.4 enabled and loaded - use glaze::glaze in your target_link_library calls
-- ENABLE_PUGIXML is (ON)
-- pugixml v1.14 enabled and loaded - use pugixml in your target_link_library calls
-- ENABLE_TOMLPLUSPLUS is (ON)
-- tomplpusplus v3.4.0 enabled and loaded - use tomplpusplus in your target_link_library calls
-- ENABLE_YAML_CPP is (ON)
-- yaml-cpp 0.8.0 enabled and loaded - use yaml-cpp in your target_link_library calls
-- ENABLE_STDUUID is (ON)
-- stduuid v1.2.3 enabled and loaded - use stduuid in your target_link_library calls
-- ENABLE_SPDLOG is (ON)
-- Build spdlog: 1.13.0
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Build type: Coverage
-- spdlog v1.13.0 enabled and loaded - use spdlog::spdlog in your target_link_library calls
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- Added /Some/place/on/clone/machine/testaus/build-coverage/_deps/tomplpusplus-src/include/ as include
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (12.7s)
-- Generating done (0.1s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build-coverage
cmake -G Ninja -DCMAKE_BUILD_TYPE=ReleaseWithDeb -S . -B build -Wno-dev
-- ENABLE_DOCTESTS is (ON)
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- ENABLE_CATCH2 is (OFF)
-- ENABLE_GLAZE is (ON)
-- glaze v2.1.4 enabled and loaded - use glaze::glaze in your target_link_library calls
-- ENABLE_PUGIXML is (ON)
-- pugixml v1.14 enabled and loaded - use pugixml in your target_link_library calls
-- ENABLE_TOMLPLUSPLUS is (ON)
-- tomplpusplus v3.4.0 enabled and loaded - use tomplpusplus in your target_link_library calls
-- ENABLE_YAML_CPP is (ON)
-- yaml-cpp 0.8.0 enabled and loaded - use yaml-cpp in your target_link_library calls
-- ENABLE_STDUUID is (ON)
-- stduuid v1.2.3 enabled and loaded - use stduuid in your target_link_library calls
-- ENABLE_SPDLOG is (ON)
-- Build spdlog: 1.13.0
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Build type: ReleaseWithDeb
-- spdlog v1.13.0 enabled and loaded - use spdlog::spdlog in your target_link_library calls
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- Added /Some/place/on/clone/machine/testaus/build/_deps/tomplpusplus-src/include/ as include
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (11.3s)
-- Generating done (0.0s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build
```

Running the example (without coverage instrumentation):

```console
❯ make example
cmake --build build --target example
[0/2] Re-checking globbed directories...
[46/46] Linking CXX executable example
Please enter three integers separated by spaces: Thanks. Got it.
 triple_max(1, 2, 3) = 3

YAML from JSON:
---
i: 287
hello: Hello World
arr:
  - 1
  - 2
  - 3
map:
  one: 1
  two: 2

YAML from XPath:
---
i: 287
hello: Hello World
arr:
  - 1
  - 2
  - 3
map:
  one: 1
  two: 2


```

Static analysis of implementation:

```console
❯ make analysis
cmake --build build-coverage --target analysis
[0/2] Re-checking globbed directories...
[1/1] Running cppcheck for analysis - writing reports and logs to /Some/place/on/clone/machine/testaus/build-coverage/analysis/cppcheck.{log,report}.*
[36] cppcheck_codequality INFO: No file location. Skipping the below issue:
  Active checkers: 172/592 (use --checkers-report=<filename> to see details)
[36] cppcheck_codequality INFO: Converted 10 CppCheck issues
[
    {
        "type": "issue",
        "severity": "minor",
        "check_name": "cppcheck[duplicateBreak]",
        "description": "Consecutive return, break, continue, goto or throw statements are unnecessary. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "913256335ec29be744ceb4da0f834240",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 68,
                    "column": 7
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
        "check_name": "cppcheck[passedByValue]",
        "description": "Function parameter 'obj' should be passed by const reference. (CWE-398)",
        "categories": [
            "Performance"
        ],
        "fingerprint": "239d3c469fa162515aacbfe9f1011ffc",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 94,
                    "column": 23
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
        "fingerprint": "6746f8ddb719bf869f749d96131b6a81",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 16,
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
        "fingerprint": "9b0b8c39a5c620412317ad004e831b2d",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 32,
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
        "description": "The function 'to_json' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "03eff5ce213d52acc16f728e7506f4e7",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 76,
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
        "description": "The function 'impluct_from_json' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "2f72f6957c7c7ddd0fcd834cf0345a76",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 81,
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
        "description": "The function 'confluct_from_toml' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "dfae1697d5c50304ad9351013c621e4c",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 118,
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
        "description": "The function 'confluct_from_yaml' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "8d06a868db587d62ca9aa6c0b84deca5",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 145,
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
        "description": "The function 'confluct_from_xml' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "a81f0a9f9b9adb2d7509627f5e6ce64d",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 156,
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
        "description": "The function 'uuid4' is never used. (CWE-561)",
        "categories": [
            "Style"
        ],
        "fingerprint": "33e042490425fe1d06a179fe3bf34255",
        "location": {
            "path": "src/implementation.cpp",
            "positions": {
                "begin": {
                    "line": 193,
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
❯ make coverage
cmake --build build-coverage --target coverage
[0/2] Re-checking globbed directories...
[48/49] Running ctest to excute tests
Test project /Some/place/on/clone/machine/testaus/build-coverage
    Start 1: tests
1/1 Test #1: tests ............................   Passed    0.22 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.22 sec
[49/49] Executing gcovr to process coverage - open 
        /Some/place/on/clone/machine/testaus/build-coverage/coverage/coverage_details.html to inspect results
(INFO) - MainThread - Reading coverage data...
(INFO) - MainThread - Writing coverage report...
Child returned 0
{
    "branch_covered": 89,
    "branch_percent": 56.7,
    "branch_total": 157,
    "files": [
        {
            "branch_covered": 88,
            "branch_percent": 56.8,
            "branch_total": 155,
            "filename": "src/implementation.cpp",
            "function_covered": 12,
            "function_percent": 100.0,
            "function_total": 12,
            "line_covered": 110,
            "line_percent": 100.0,
            "line_total": 110
        },
        {
            "branch_covered": 1,
            "branch_percent": 50.0,
            "branch_total": 2,
            "filename": "src/implementation.h",
            "function_covered": 4,
            "function_percent": 100.0,
            "function_total": 4,
            "line_covered": 2,
            "line_percent": 100.0,
            "line_total": 2
        }
    ],
    "function_covered": 16,
    "function_percent": 100.0,
    "function_total": 16,
    "gcovr/summary_format_version": "0.5",
    "line_covered": 112,
    "line_percent": 100.0,
    "line_total": 112,
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
❯ cmake -DCMAKE_BUILD_TYPE=Coverage -S . -B build-coverage -Wno-dev
-- ENABLE_DOCTESTS is (ON)
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- ENABLE_CATCH2 is (OFF)
-- ENABLE_GLAZE is (ON)
-- glaze v2.1.4 enabled and loaded - use glaze::glaze in your target_link_library calls
-- ENABLE_PUGIXML is (ON)
-- pugixml v1.14 enabled and loaded - use pugixml in your target_link_library calls
-- ENABLE_TOMLPLUSPLUS is (ON)
-- tomplpusplus v3.4.0 enabled and loaded - use tomplpusplus in your target_link_library calls
-- ENABLE_YAML_CPP is (ON)
-- yaml-cpp 0.8.0 enabled and loaded - use yaml-cpp in your target_link_library calls
-- ENABLE_STDUUID is (ON)
-- stduuid v1.2.3 enabled and loaded - use stduuid in your target_link_library calls
-- ENABLE_SPDLOG is (ON)
-- Build spdlog: 1.13.0
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Build type: Coverage
-- spdlog v1.13.0 enabled and loaded - use spdlog::spdlog in your target_link_library calls
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- Added /Some/place/on/clone/machine/testaus/build-coverage/_deps/tomplpusplus-src/include/ as include
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (11.9s)
-- Generating done (0.6s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build-coverage
```

Using the `Ninja` backend and setting a release with debug symbols build type:

```console
❯ cmake -G Ninja -DCMAKE_BUILD_TYPE=ReleaseWithDeb -S . -B build -Wno-dev
-- ENABLE_DOCTESTS is (ON)
-- The CXX compiler identification is AppleClang 15.0.0.15000100
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Some/System/Path/to/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- doctest v2.4.11 enabled and loaded - use doctest::doctest in your target_link_library calls
-- ENABLE_CATCH2 is (OFF)
-- ENABLE_GLAZE is (ON)
-- glaze v2.1.4 enabled and loaded - use glaze::glaze in your target_link_library calls
-- ENABLE_PUGIXML is (ON)
-- pugixml v1.14 enabled and loaded - use pugixml in your target_link_library calls
-- ENABLE_TOMLPLUSPLUS is (ON)
-- tomplpusplus v3.4.0 enabled and loaded - use tomplpusplus in your target_link_library calls
-- ENABLE_YAML_CPP is (ON)
-- yaml-cpp 0.8.0 enabled and loaded - use yaml-cpp in your target_link_library calls
-- ENABLE_STDUUID is (ON)
-- stduuid v1.2.3 enabled and loaded - use stduuid in your target_link_library calls
-- ENABLE_SPDLOG is (ON)
-- Build spdlog: 1.13.0
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Build type: ReleaseWithDeb
-- spdlog v1.13.0 enabled and loaded - use spdlog::spdlog in your target_link_library calls
-- coverage options set - use include(gcovr) or similar for processing of test coverage data
-- Added /Some/place/on/clone/machine/testaus/build/_deps/tomplpusplus-src/include/ as include
-- gcovr configured (cf. build/gcovr.cfg)
-- Added execute_tests target
-- Added coverage target
-- Added analysis target
-- Configuring done (11.3s)
-- Generating done (0.0s)
-- Build files have been written to: /Some/place/on/clone/machine/testaus/build
```

After changes in anything impacting the build generator you can do the following (picking the coverage instrumented build type):

Build tests, execute tests, process the coverage, and generate a report (default generator `UNIX Makefiles` on some machine
causes lengthy build - duration as well as log):

```console
❯ cmake --build build-coverage --target coverage
[  2%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/spdlog.cpp.o
[  4%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o
[  6%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o
[  8%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o
[ 10%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/async.cpp.o
[ 12%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/cfg.cpp.o
[ 14%] Building CXX object _deps/spdlog-build/CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o
[ 16%] Linking CXX static library libspdlog.a
[ 16%] Built target spdlog
[ 18%] Building CXX object _deps/pugixml-build/CMakeFiles/pugixml-static.dir/src/pugixml.cpp.o
[ 20%] Linking CXX static library libpugixml.a
[ 20%] Built target pugixml-static
[ 22%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/contrib/graphbuilder.cpp.o
[ 24%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/contrib/graphbuilderadapter.cpp.o
[ 26%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/binary.cpp.o
[ 28%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/convert.cpp.o
[ 30%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/depthguard.cpp.o
[ 32%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/directives.cpp.o
[ 34%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/emit.cpp.o
[ 36%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/emitfromevents.cpp.o
[ 38%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/emitter.cpp.o
[ 40%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/emitterstate.cpp.o
[ 42%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/emitterutils.cpp.o
[ 44%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/exceptions.cpp.o
[ 46%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/exp.cpp.o
[ 48%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/memory.cpp.o
[ 51%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/node.cpp.o
[ 53%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/node_data.cpp.o
[ 55%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/nodebuilder.cpp.o
[ 57%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/nodeevents.cpp.o
[ 59%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/null.cpp.o
[ 61%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/ostream_wrapper.cpp.o
[ 63%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/parse.cpp.o
[ 65%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/parser.cpp.o
[ 67%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/regex_yaml.cpp.o
[ 69%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/scanner.cpp.o
[ 71%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/scanscalar.cpp.o
[ 73%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/scantag.cpp.o
[ 75%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/scantoken.cpp.o
[ 77%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/simplekey.cpp.o
[ 79%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/singledocparser.cpp.o
[ 81%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/stream.cpp.o
[ 83%] Building CXX object _deps/yaml-cpp-build/CMakeFiles/yaml-cpp.dir/src/tag.cpp.o
[ 85%] Linking CXX static library libyaml-cpp.a
[ 85%] Built target yaml-cpp
[ 87%] Building CXX object CMakeFiles/implementation.dir/src/implementation.cpp.o
[ 89%] Linking CXX static library libimplementation.a
[ 89%] Built target implementation
[ 91%] Building CXX object CMakeFiles/tests.dir/test/test_main.cpp.o
[ 93%] Building CXX object CMakeFiles/tests.dir/test/test_implementation.cpp.o
[ 95%] Linking CXX executable tests
[ 95%] Built target tests
[ 97%] Running ctest to excute tests
Test project /Some/place/on/clone/machine/testaus/build-coverage
    Start 1: tests
1/1 Test #1: tests ............................   Passed    0.23 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.23 sec
[ 97%] Built target execute_tests
[100%] Executing gcovr to process coverage - open /Some/place/on/clone/machine/build-coverage/coverage/coverage_details.html to inspect results
(INFO) - MainThread - Reading coverage data...
(INFO) - MainThread - Writing coverage report...
[100%] Built target coverage
```

Analyze the source code (static analyzer cppcheck in this case):

```console
❯ cmake --build build-coverage --target analysis
[100%] Running cppcheck for analysis - writing reports and logs to /Some/place/on/clone/machine/testaus/build-coverage/analysis/cppcheck.{log,report}.*
[33] cppcheck_codequality INFO: No file location. Skipping the below issue:
  Active checkers: 172/592 (use --checkers-report=<filename> to see details)
[34] cppcheck_codequality INFO: Converted 10 CppCheck issues
[100%] Built target analysis
```

Display any analysis results (log and report):

```console
❯ bat build-coverage/analysis/cppcheck.log.txt
───────┬─────────────────────────────────────────────────────────────────────────────────────────
       │ File: build-coverage/analysis/cppcheck.log.txt
───────┼─────────────────────────────────────────────────────────────────────────────────────────
   1   │ Checking example/main.cpp ...
   2   │ 1/2 files checked 25% done
   3   │ Checking src/implementation.cpp ...
   4   │ 2/2 files checked 100% done
───────┴─────────────────────────────────────────────────────────────────────────────────────────
```

```console
❯ jq . build-coverage/analysis/cppcheck.report.json | bat -l json
───────┬─────────────────────────────────────────────────────────────────────────────────────────
       │ STDIN
───────┼─────────────────────────────────────────────────────────────────────────────────────────
   1   │ [
   2   │   {
   3   │     "type": "issue",
   4   │     "severity": "minor",
   5   │     "check_name": "cppcheck[duplicateBreak]",
   6   │     "description": "Consecutive return, break, continue, goto or throw statements are un
       │ necessary. (CWE-561)",
   7   │     "categories": [
   8   │       "Style"
   9   │     ],
  10   │     "fingerprint": "913256335ec29be744ceb4da0f834240",
  11   │     "location": {
  12   │       "path": "src/implementation.cpp",
  13   │       "positions": {
  14   │         "begin": {
  15   │           "line": 68,
  16   │           "column": 7
  17   │         }
  18   │       }
  19   │     },
  20   │     "content": {
  21   │       "body": ""
  22   │     }
  23   │   },
 ...
 200   │   {
 201   │     "type": "issue",
 202   │     "severity": "minor",
 203   │     "check_name": "cppcheck[unusedFunction]",
 204   │     "description": "The function 'uuid4' is never used. (CWE-561)",
 205   │     "categories": [
 206   │       "Style"
 207   │     ],
 208   │     "fingerprint": "33e042490425fe1d06a179fe3bf34255",
 209   │     "location": {
 210   │       "path": "src/implementation.cpp",
 211   │       "positions": {
 212   │         "begin": {
 213   │           "line": 193,
 214   │           "column": 0
 215   │         }
 216   │       }
 217   │     },
 218   │     "content": {
 219   │       "body": ""
 220   │     }
 221   │   }
 222   │ ]
 ```

```console
❯ bat build-coverage/analysis/cppcheck.report.xml
───────┬─────────────────────────────────────────────────────────────────────────────────────────
       │ File: build-coverage/analysis/cppcheck.report.xml
───────┼─────────────────────────────────────────────────────────────────────────────────────────
   1   │ <?xml version="1.0" encoding="UTF-8"?>
   2   │ <results version="2">
   3   │     <cppcheck version="2.13.0"/>
   4   │     <errors>
   5   │         <error id="duplicateBreak" severity="style" msg="Consecutive return, break, cont
       │ inue, goto or throw statements are unnecessary." verbose="Consecutive return, break, con
       │ tinue, goto or throw statements are unnecessary. The second statement can never be execu
       │ ted, and so should be removed." cwe="561" file0="src/implementation.cpp">
   6   │             <location file="src/implementation.cpp" line="68" column="7"/>
   7   │         </error>
   8   │         <error id="passedByValue" severity="performance" msg="Function parameter &apos;o
       │ bj&apos; should be passed by const reference." verbose="Parameter &apos;obj&apos; is pas
       │ sed by value. It could be passed as a const reference which is usually faster and recomm
       │ ended in C++." cwe="398" file0="src/implementation.cpp">
   9   │             <location file="src/implementation.cpp" line="94" column="23" info="Function
       │  parameter &apos;obj&apos; should be passed by const reference."/>
  10   │             <symbol>obj</symbol>
  11   │         </error>
 ...
  40   │         <error id="unusedFunction" severity="style" msg="The function &apos;uuid4&apos;
       │ is never used." verbose="The function &apos;uuid4&apos; is never used." cwe="561">
  41   │             <location file="src/implementation.cpp" line="193" column="0"/>
  42   │             <symbol>uuid4</symbol>
  43   │         </error>
  44   │         <error id="checkersReport" severity="information" msg="Active checkers: 172/592
       │ (use --checkers-report=&lt;filename&gt; to see details)" verbose="Active checkers: 172/5
       │ 92 (use --checkers-report=&lt;filename&gt; to see details)"/>
  45   │     </errors>
  46   │ </results>
───────┴─────────────────────────────────────────────────────────────────────────────────────────
```

## Status

Experimental.

**Note**: The default branch is `default`.
