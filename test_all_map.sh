for var in `ls maps/*`
do
	echo ""
	echo "Test $var :"
	./lem-in < $var 1>&-

	[ `echo $?` == 0 ] && echo OK
done
