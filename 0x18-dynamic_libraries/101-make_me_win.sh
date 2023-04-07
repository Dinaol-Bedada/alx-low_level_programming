#!/bin/bash
wget -P /tmp https://github.com/Dinaol-Bedada/alx-low_level_programming/tree/main/0x18-dynamic_libraries/random.so
export LD_PRELOAD="$PWD/../random.so"
