#!/bin/bash

export PATH="$HOME/tinyos-cross/autotools-newlib-bin/bin:$PATH"

CURDIR=$(pwd)


cd ${CURDIR}/newlib-2.5.0.20171222/newlib/libc/sys
autoconf
cd tinyos
autoreconf
cd ${CURDIR}

mkdir -p build-newlib
cd build-newlib
../newlib-2.5.0.20171222/configure --prefix=/usr --target=i686-tinyos
make all
make DESTDIR=$HOME/tinyos-cross/sysroot install
