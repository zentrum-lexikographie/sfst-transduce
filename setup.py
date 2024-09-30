from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

setup(
    cmdclass={"build_ext": build_ext},
    ext_modules=[
        Pybind11Extension(
            "sfst_transduce",
            [
                "src/basic.cpp",
                "src/compact.cpp",
                "src/utf8.cpp",
                "src/alphabet.cpp",
                "src/fst.cpp",
                "src/operators.cpp",
                "src/determinise.cpp",
                "src/hopcroft.cpp",
                "python/sfst_transduce.cpp",
            ],
            define_macros=[("SFST_VERSION", open("VERSION").read().strip())],
        )
    ],
    zip_safe=False,
)
