from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(ext_modules = [
                    Extension("cython_test", 
                              ["cython_test.pyx"],  
                              language = "c++",
                              extra_compile_args = ["-D PYTHON"])],
      cmdclass = {'build_ext': build_ext})
