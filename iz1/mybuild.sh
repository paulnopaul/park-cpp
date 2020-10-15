rm -rf build;
mkdir build;
cd build;
cmake -DENABLE_GCOV=ON ..;
make;

