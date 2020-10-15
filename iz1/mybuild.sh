#! /bin/bash

rm -rf build;
mkdir build;
cd build;
cmake -DENABLE_GCOV=ON ..;
make;
gcovr  --html-details > cov_res.html;


