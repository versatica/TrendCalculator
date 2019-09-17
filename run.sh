#!/usr/bin/env bash

set -e

mkdir -p out

g++ -std=c++11 -Isrc -Wall src/main.cpp src/TrendCalculator.cpp -o out/trend_calculator_test

out/trend_calculator_test
