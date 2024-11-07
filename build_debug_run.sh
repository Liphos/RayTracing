#!/bin/bash
cmake -B build
cmake --build build --config Debug
./build/Debug/RayTracingInOneWeekend.exe > ./image_test.ppm