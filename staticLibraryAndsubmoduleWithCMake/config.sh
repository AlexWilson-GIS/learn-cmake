#!/bin/sh

git submodule update --init --recursive
cmake -DBUILD_SHARED_LIBS=ON -DGLFW_BUILD_DOCS=OFF -S . -B out/build