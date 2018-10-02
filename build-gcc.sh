#!/bin/bash

CURDIR=$(pwd)
mkdir -p gcc-build
rm -rf gcc-build/*
cd gcc-build
export SYSROOT=$CURDIR/sysroot
../gcc-5.4.0/configure --target=i686-tinyos --prefix=$SYSROOT/usr --with-sysroot=$SYSROOT --enable-languages=c,c++
make -j4 all-gcc all-target-libgcc
make install-gcc install-target-libgcc

