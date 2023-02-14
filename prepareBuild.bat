cmake -S . -B build/debug/ -G "Ninja" -D CMAKE_BUILD_TYPE=Debug
cmake -S . -B build/release/ -G "Ninja" -D CMAKE_BUILD_TYPE=Release