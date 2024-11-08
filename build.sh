#!/usr/bin/env sh

cd "$(dirname "$0")" || exit

if [ ! -d ./build/ ]; then
  mkdir build
fi

cd build/ || exit

cmake ..
cmake --build .
