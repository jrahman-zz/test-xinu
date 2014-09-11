#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: test_xinu.sh <labnumber>"
    exit
fi

echo "Finding xinu directory for lab $1"
XINU_BASE=$(find . -type d -name "xinu-14Fall-lab$1-linksys")
XINU_COMPILE="$XINU_BASE/compile"

echo "Calling make"
cd $XINU_COMPILE
make

echo "Connecting to a linksys machine and running Xinu"
/p/xinu/bin/mips-console
