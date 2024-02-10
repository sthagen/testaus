FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG v2.4.11 # commit ae7a13539fb71f270b87eb2e874fbac80bc8dda2
  FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(doctest)
