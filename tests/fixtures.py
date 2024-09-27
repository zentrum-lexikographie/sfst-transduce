from pathlib import Path

from pytest import fixture

import sfst_transduce

tests_dir = (Path(__file__) / "..").resolve()


@fixture
def transducer():
    return sfst_transduce.Transducer((tests_dir / "easy.a").as_posix())


@fixture
def compact_transducer():
    return sfst_transduce.CompactTransducer((tests_dir / "easy.ca").as_posix())
