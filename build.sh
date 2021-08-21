#!/bin/sh
clang++ -std=c++17 -o main main.cc win.cc `pkg-config --cflags --libs gtkmm-4.0`
