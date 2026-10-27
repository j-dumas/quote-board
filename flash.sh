#!/bin/bash

cmake --build build -j$(nproc)

picotool load -fvx build/quote_screen.uf2
