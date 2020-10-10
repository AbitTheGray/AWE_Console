# AWE Console

Originally part of AWEngine, AWE Console is simple utility designed to be used similar to [GoldSrc](https://en.wikipedia.org/wiki/GoldSrc) in-game Console.

## Testing

Run `ctest` in build directory.

Executable of tests have prefix `t_` (test `abc` would be executable `t_abc`).
After creating new test, add it to [`tests/CMakeLists.txt`](tests/CMakeLists.txt) as `add_subdirectory(abc)` (where `abc` is name of your test).

To setup tests in CLion IDE, create new Run Configuration with Name=`CTest`, Working Directory=`$CMakeCurrentBuildDir$` and Executable pointing to your `ctest` executable.
On Linux it will be `/bin/ctest`, on Windows probably `C:\CMake\bin\ctest.exe` 
