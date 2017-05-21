for var in `ls maps/*`
do
	echo "\\nTest $var :"
	./lem-in < $var 1>&-

	[ `echo $?` == 0 ] && echo OK
done
