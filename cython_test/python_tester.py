import cython_test
import random

def custom_rand():
    return random.randint(1, 200)

cython_test.py_register_rand(custom_rand)

for i in range(20):
    cython_test.py_loop()
