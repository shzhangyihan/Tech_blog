import ctypes

def python_test():
    pdll = ctypes.CDLL('./test_cpp.so')
    pdll.try_test()
    print "Hello world"

def return_test():
    print "try to return 10"
    return 10

python_test()
