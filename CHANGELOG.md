# Changes:

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
