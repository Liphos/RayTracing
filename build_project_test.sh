#!/bin/bash
cmake -B build
cmake --build build
./build/Debug/RayTracingInOneWeekend.exe > ./images/image_test.ppm