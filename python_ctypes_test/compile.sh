if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	echo "linux"
	gcc test_cpp.cpp -o test_cpp.so -shared -I/usr/include/python2.7/ -lpython2.7
elif [[ "$OSTYPE" == "darwin"* ]]; then
	echo "macos"
	gcc -framework Python test_cpp.cpp -o test_cpp.so -shared
fi
