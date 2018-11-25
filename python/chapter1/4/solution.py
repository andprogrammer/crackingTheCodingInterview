import unittest


def urlify(data1, data2):
    alphabet = [0 for i in range(128)]
    data1 = str.lower(data1)
    data2 = str.lower(data2)
    for c in data1:
        alphabet[ord(c)] += 1
    for c in data2:
        if alphabet[ord(c)] == 0:   #todo check if alpha...
            return False
        alphabet[ord(c)] -= 1
    return True


class TestSuit(unittest.TestCase):
    def setUp(self):
        self.test_data = (('Tact Coa', "taco cat"),
                          ('Tact Coa', 'atco cta'))

    def test_unique(self):
        for d in self.test_data:
            self.assertTrue(urlify(*d))


if __name__ == '__main__':
    unittest.main()
