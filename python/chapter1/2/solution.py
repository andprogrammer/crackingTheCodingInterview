import unittest


def check_permutation(data1, data2):
    if len(data1) != len(data2):
        return False
    sorted_data1 = sorted(data1)
    sorted_data2 = sorted(data2)
    return sorted_data1 == sorted_data2


def check_permutation_second_solution(data1, data2):
    if len(data1) != len(data2):
        return False
    alphabet = {}
    for c in data1:
        alphabet[c] = alphabet.get(c, 0) + 1
    for c in data2:
        if c not in alphabet:
            return False
        alphabet[c] -= 1
        if alphabet[c] == 0:
            del alphabet[c]
    return True


class TestSuit(unittest.TestCase):
    def setUp(self):
        self.data_true = (("", ""), ("tomek", "moket"), (" i a", "a  i"))
        self.data_false = (("oao", "oo"), (" ", ""))

    def test_unique(self):
        for d in self.data_true:
            self.assertTrue(check_permutation(*d))
            self.assertTrue(check_permutation_second_solution(*d))
        for d in self.data_false:
            self.assertFalse(check_permutation(*d))
            self.assertFalse(check_permutation_second_solution(*d))


if __name__ == '__main__':
    unittest.main()
