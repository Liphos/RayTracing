#!/bin/bash
cmake -B build
cmake --build build
./build/Debug/RayTracingInOneWeekend.exe > image_test.ppm