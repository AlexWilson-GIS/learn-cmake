#!/bin/sh

rm -rf out/build
mkdir out/build
cmake -DUSE_SIMPLE_MATH_LIBRARY=OFF -S . -B out/build