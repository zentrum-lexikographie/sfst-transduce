# -*- coding: utf-8 -*-
from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

__version__ = open('VERSION').read().strip()

setup(
    name="sfst-transduce",
    version=__version__,
    author="Gregor Middell",
    author_email="gregor@middell.net",
    description="Python bindings for SFST focusing on transducer usage",
    long_description=open('README.md').read(),
    long_description_content_type="text/markdown",
    url="https://github.com/gremid/sfst-transduce",
    license="GPLv2",
    ext_modules=[Pybind11Extension(
        "sfst_transduce",
        ["src/basic.cpp",
         "src/compact.cpp",
         "src/utf8.cpp",
         "src/alphabet.cpp",
         "src/fst.cpp",
         "src/operators.cpp",
         "src/determinise.cpp",
         "src/hopcroft.cpp",
         "python/sfst_transduce.cpp"],
        define_macros=[("SFST_VERSION", __version__)]
    )],
    cmdclass={"build_ext": build_ext},
    #package_dir={"": "python"},
    zip_safe=False,
    extras_require={
        'dev': [
            'pytest',
            'autoflake',
            'flake8'
        ]
    }
)
