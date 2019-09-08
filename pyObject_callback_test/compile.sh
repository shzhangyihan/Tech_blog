if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	echo "linux"
	gcc cpp_main.cpp -I/usr/include/python2.7/ -lpython2.7
elif [[ "$OSTYPE" == "darwin"* ]]; then
	echo "macos"
	gcc -framework Python cpp_main.cpp
fi
