#!/bin/bash

CURDIR=$(pwd)
export PATH="$CURDIR/autotools-newlib-bin/bin:$PATH"
cd ${CURDIR}/newlib-2.5.0.20171222/newlib/libc/sys
autoconf
cd tinyos
autoreconf
cd ${CURDIR}
mkdir -p build-newlib
cd build-newlib
../newlib-2.5.0.20171222/configure --prefix=/usr --target=i686-tinyos
make all
make DESTDIR=$CURDIR/sysroot install
