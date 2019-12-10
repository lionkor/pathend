#!/bin/bash
cd bin
rm -v pathend
cmake -DCMAKE_BUILD_TYPE=Debug ../
make -j 9
cd ..
