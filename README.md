
# sfst-transduce

_Python bindings for SFST focusing on transducer usage_

[![PyPI – Version](https://badge.fury.io/py/sfst-transduce.svg)](https://badge.fury.io/py/sfst-transduce)
![PyPI - Python Version](https://img.shields.io/pypi/pyversions/sfst-transduce)
![PyPI - Wheel](https://img.shields.io/pypi/wheel/sfst-transduce)
![GitHub License](https://img.shields.io/github/license/zentrum-lexikographie/sfst-transduce)


A Python library providing bindings for the Stuttgart Finite State Transducer
system with a focus on the usage of compiled and serialized transducers,
excluding code for transducer development and testing, which reduces compile and
runtime dependencies.

Should you need the [SFST
tools](https://www.cis.uni-muenchen.de/~schmid/tools/SFST/) for transducer
generation, please take a look at their homepage for installation and usage
instructions.

## Installation

`sfst-transduce` is available at
[PyPI](https://pypi.org/project/sfst-transduce/):

```bash
pip install sfst-transduce
```

## Usage

```python
import sfst_transduce

# Create instance from compiled transducer
transducer = sfst_transduce.Transducer('path/to/fst.a')

# Analysis
analysis_results = transducer.analyse("easier")
# Returns ['easy<ADJ><comp>'] for example.

# Generate a string. results are a list of analysis.
generate_results = transducer.generate("easy<ADJ><comp>")
# Returns ['easier'] for example.

# Create instance from compiled transducer (compacted serialisation)
transducer = sfst_transduce.CompactTransducer('path/to/fst.ca')
# Activate output of aligned input and output layer
transducer.both_layers = True
# Analysis
transducer.analyse('easier')
# Returns ['easy:i<ADJ>:<><comp>:e<>:r'] for example.
```

## Development

```bash
pip install -e .
pip install -r requirements-dev.txt
pre-commit install
```

## Release

```bash
scripts/release $NEW_VERSION
git push && git push --tags
```

## Credits

The [SFST tools](https://www.cis.uni-muenchen.de/~schmid/tools/SFST/) have been
implemented by Helmut Schmid, Institute for Computational Linguistics,
University of Stuttgart, Germany and they are available under the GNU public
license version 2 or higher.

Please cite the following publication if you want to refer to the SFST tools:

Schmid, Helmut. "A programming language for finite state transducers." FSMNLP.
Vol. 4002. 2005.
[pdf](https://www.cis.uni-muenchen.de/~schmid/papers/SFST-PL.pdf)

This Python library is a fork of the excellent [SFST
adaptation](https://github.com/santhoshtr/sfst) by Santhosh Thottingal, changing
the focus of the Python part.
