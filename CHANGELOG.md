# Changes:

2024.2.12
:    Enhanced version/tag handling in modules and padded option strings that broke on concat.
Hardened distclean make target forcefully remove both known build directories.
Raised minimum of cmake version range as FetchContent does not really work before 3.17.

2024.2.10
:    Initial release demonstrating integrating Catch2, cppcheck, doctest, and gcovr with CMake.