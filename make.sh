#!/bin/bash

if [ ! -d ./bin ]; then
    mkdir bin
fi

cd bin
rm -v pathend
cmake -DCMAKE_BUILD_TYPE=Debug ../
make -j 9
cd ..
