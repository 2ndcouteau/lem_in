#!/bin/sh
cd visu
cat $1 | python3 visualize.py
open vizualize.html
