@echo off

rmdir /S /Q build
mkdir build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
cmake --build . --config Release

echo.
echo Press a key to continue...
pause >nul