import unittest


def is_unique(data):
    if not data:
        return True
    uniques = [False for _ in range(128)]
    for i in data:
        if uniques[ord(i)]:
            return False
        uniques[ord(i)] = True
    return True


class TestSuit(unittest.TestCase):
    def setUp(self):
        self.data_true = ["", "not same", "t ia"]
        self.data_false = ["mam", "oo", "the same"]

    def test_unique(self):
        for d in self.data_true:
            self.assertTrue(is_unique(d))
        for d in self.data_false:
            self.assertFalse(is_unique(d))


def run():
    unittest.main()
    assert is_unique("") is True
    assert is_unique("mam") is False
    assert is_unique("Tomek")
    assert is_unique("ala ma kota") is False
    assert is_unique("aa") is False
    assert is_unique("not same")


if __name__ == '__main__':
    run()
