@echo off

IF NOT EXIST build\windows mkdir build\windows
pushd build\windows
cl -Zi ..\..\bnutils\main.cpp -O2
popd