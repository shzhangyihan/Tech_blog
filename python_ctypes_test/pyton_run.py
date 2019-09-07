import ctypes

pdll = ctypes.CDLL('./test_cpp.so')
pdll.try_test()
