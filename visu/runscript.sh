#!/bin/sh

cd visu
cat $1 | python3 visualize.py

if [ -e /usr/bin/iceweasel ]; then
	iceweasel vizualize.html &
else if [ -e /usr/bin/chromium ]; then
	chromium vizualize.html &
else if [ -e /usr/bin/firefox ]; then
	firefox vizualize.html &
else
	echo "No know web browser. Please open manually: \"navigateur vizualize.html\""
	open .
fi
fi
fi
