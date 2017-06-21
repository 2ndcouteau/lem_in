#!/bin/bash

RED=$(printf "\e[31m")
GREEN=$(printf "\e[32m")
YELLOW=$(printf "\e[33m")
BLUE=$(printf "\e[34m")
MAGENTA=$(printf "\e[35m")
CYAN=$(printf "\e[36m")
WHITE=$(printf "\e[37m")
RESET=$(printf "\e[m")

for var in `toe -a | awk -F " " '{print $1}'`
do
	env TERM=$var ./lem-in < maps/test_2.map 1>&-
	echo -n "Test TERM==$var: "
	if [ `echo $?` != 0 ]; then
		echo "${RED}ERROR${RESET}"
	else
		echo "${CYAN}SUCCESS${RESET}"
	fi
done
