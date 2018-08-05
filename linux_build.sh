mkdir -p build/linux/
clang bnutils/main.cpp $(< flags_linux.txt) -o build/linux/main