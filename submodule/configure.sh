#! /bin/sh
git submodule update --init --recursive
# use -D<name of option>=<value> to pass in CMake options.
cmake -S myApp -B myApp/out/build