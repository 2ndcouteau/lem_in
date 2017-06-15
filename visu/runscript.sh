#!/bin/sh
cd visu
cat $1 | python3 visualize.py
firefox vizualize.html
