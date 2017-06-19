#!/bin/bash

RED=$(printf "\e[31m")
GREEN=$(printf "\e[32m")
YELLOW=$(printf "\e[33m")
BLUE=$(printf "\e[34m")
MAGENTA=$(printf "\e[35m")
CYAN=$(printf "\e[36m")
WHITE=$(printf "\e[37m")
RESET=$(printf "\e[m")

if [ ! -e ./lem-in ]; then
	make;
fi

for var in `ls maps/*`
do
	echo ""
	echo "${BLUE}#${RESET}Test $var :"
	if [[ ! $var =~ ^maps/map1* ]] && [[ ! $var =~ ^maps/big* ]]; then
		./lem-in < $var 1>&-
		[ `echo $?` == 0 ] && echo "${CYAN}SUCCESS${RESET}" || echo "${RED}ERROR${RESET}"
	else
		echo "${MAGENTA}Test too long --> Skip${RESET}"
	fi
done
