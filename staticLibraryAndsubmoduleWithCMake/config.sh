#!/bin/sh

git submodule update --init --recursive
cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build