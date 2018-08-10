alias clang=clang-6.0
mkdir -p build/linux/
clang $(< flags_linux.txt) -o build/linux/main src/main.cpp