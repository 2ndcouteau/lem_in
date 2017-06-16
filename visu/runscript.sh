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
	echo "WALLAH YA PAS DE NAVIGATEUR CONNU: \"navigateur vizualize.html\""
fi
fi
fi
