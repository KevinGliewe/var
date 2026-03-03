#!/bin/bash
# Quick build and test script for local development.
# Use when vcpkg is not available (e.g. libgtest-dev from apt).

set -e
cd "$(dirname "$0")/.."

# Use g++ if clang has libstdc++ linker issues
export CMAKE_CXX_COMPILER="${CMAKE_CXX_COMPILER:-/usr/bin/g++}"

echo "=== Configuring ==="
cmake -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_COMPILER="$CMAKE_CXX_COMPILER" \
  -DVAR_BUILD_TESTS=ON \
  -DVAR_BUILD_EXAMPLES=ON

echo "=== Building ==="
cmake --build build

echo "=== Running tests ==="
ctest --test-dir build --output-on-failure

echo "=== Running example ==="
./build/example/example

echo "=== All passed ==="
