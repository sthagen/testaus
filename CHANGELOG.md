# Changes:

2024.2.20
:   - Added stduuid cmake module
- Added stduuid to implementation and test
- Added stduuid to top level cmake lists file
- Added tomplusplus cmake module
- Added tomplusplus to implementation and test
- Added tomplusplus to top level cmake lists file
 
2024.2.19
:    - Added pugixml cmake module
- Added pugixml to implementation and test
- Added pugixml to top level cmake lists file
- Added xml parsing to example
- Moved gcovr configuration template into dedicated etc dir

2024.2.18
:    - Adapted top level cmake lists file to use spdlog and yaml-cpp
- Added implementation and test of yaml backed services
- Added spdlog and yaml-cpp cmake modules based on FetchContent
- Added spdlog to implementation and json loader
- Added the shallow clone attribute to catch2 and doctest cmake modules
- Amended the example to use the yaml-cpp library backed parts of the implementation
- Split of tests into stub with only main and all real tests separate (doctest)

2024.2.17
:    - Added a glaze cmake module
- Added a glaze using part in implementation
- Added doctest test cases for glaze use
- Made the test framework switch uses more consistent

2024.2.13
:    - Added tool to open a file in browser.
- Added documentation to bin folder to ensure users do not use it as build folders.
- Raised minimum of cmake version range as FetchContent does not really work before 3.22.5.
- Split commands into several cmake commands for platform portability.

2024.2.12
:    - Enhanced version/tag handling in modules and padded option strings that broke on concat.
- Hardened distclean make target forcefully remove both known build directories.
- Raised minimum of cmake version range as FetchContent does not really work before 3.17.

2024.2.10
:    - Initial release demonstrating integrating Catch2, cppcheck, doctest, and gcovr with CMake.
