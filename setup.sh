mkdir build_pc
mkdir build_target
mkdir build_unittest
cd build_pc
cmake -DBUILD_TYPE=PC ..
make
cd ..
cd build_unittest
cmake -DBUILD_TYPE=UNITTEST ..
make
cd ..
cd build_target
cmake -DBUILD_TYPE=TARGET ..
make
cd ..

