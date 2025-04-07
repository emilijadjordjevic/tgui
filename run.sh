#!/bin/bash

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$PROJECT_DIR/build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake -DCMAKE_BUILD_TYPE=Debug ..
make

if [ $? -eq 0 ]; then
    echo "===== Running MyProject ====="
    ./MyProject
else
    echo "Build failed!"
fi
