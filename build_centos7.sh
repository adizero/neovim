#!/usr/bin/env bash

mkdir build
gcc -c endian_fix.c -o build/endian_fix.o
ar rcs build/libendianfix.a build/endian_fix.o
CC=gcc make CMAKE_BUILD_TYPE=RelWithDebInfo CMAKE_EXTRA_FLAGS="-DCMAKE_INSTALL_PREFIX=$HOME/apps/" -j8
echo "If it everything goes well run 'make install' to install it (into the install prefix directory)"
# make install
