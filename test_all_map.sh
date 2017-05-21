for var in `ls maps/*.map`; do ./lem-in < $var | grep ERROR ; echo -e "\\nTest $var :"; done
