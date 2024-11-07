#!/bin/bash
cmake -B build
cmake --build build --config Release
./build/Release/RayTracingInOneWeekend.exe > ./image_test.ppm