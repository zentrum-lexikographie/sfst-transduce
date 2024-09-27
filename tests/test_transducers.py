def assert_single_result(expected, results):
    assert len(results) == 1
    for result in results:
        assert result == expected


def test_transducer(transducer):
    assert_single_result("easy<ADJ><pos>", transducer.analyse("easy"))
    assert_single_result("easier", transducer.generate("easy<ADJ><comp>"))


def test_compact_transducer(compact_transducer):
    assert_single_result("easy<ADJ><pos>", compact_transducer.analyse("easy"))
