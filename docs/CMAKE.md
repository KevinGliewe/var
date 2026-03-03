# Building and Using var with CMake

## Standalone Build

```bash
# With vcpkg (recommended)
export VCPKG_ROOT=/path/to/vcpkg
cmake -B build -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
ctest --test-dir build
```

## Using with FetchContent

Add var as a dependency in your project's `CMakeLists.txt`:

```cmake
include(FetchContent)
FetchContent_Declare(var
    GIT_REPOSITORY https://github.com/dimonpokemon81/var.git
    GIT_TAG        v1.2.0
)
FetchContent_MakeAvailable(var)

# Link your target
target_link_libraries(your_target PRIVATE var::var)
```

When used as a subproject via FetchContent:
- Tests and examples are **not** built by default
- To build them, set `VAR_BUILD_TESTS=ON` and `VAR_BUILD_EXAMPLES=ON` before the first `project()` call

## Using with find_package

After installing var:

```cmake
find_package(var CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE var::var)
```

## Options

| Option | Default (standalone) | Default (subproject) | Description |
|--------|----------------------|----------------------|-------------|
| `VAR_BUILD_TESTS` | ON | OFF | Build the test suite (requires GTest) |
| `VAR_BUILD_EXAMPLES` | ON | OFF | Build the example executable |

## CMake Presets

Presets are available for Ninja with vcpkg:

```bash
cmake --preset ninja-multi-vcpkg
cmake --build --preset ninja-vcpkg-release
ctest --preset test-release
```

Ensure `VCPKG_ROOT` is set in your environment.
