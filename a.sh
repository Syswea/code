#!/bin/bash

g++ calculate_geometry.cpp -o a

echo "finish compiler"

chmod +x ./a

./a

rm ./a

echo "finish run"
