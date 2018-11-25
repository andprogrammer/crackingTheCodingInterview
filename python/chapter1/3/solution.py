import unittest


def urlify(data):
    everything = ""
    temp = ""
    data = data.strip()
    for c in data:
        if c == ' ':
            if temp:
                temp += "%20"
                everything += temp
                temp = ""
        else:
            temp += c
    everything += temp
    return everything


class TestSuit(unittest.TestCase):
    def setUp(self):
        self.test_data = [('Mr John Smith    ', "Mr%20John%20Smith"),
                          ('much ado about nothing      ', 'much%20ado%20about%20nothing')]

    def test_unique(self):
        for d in self.test_data:
            self.assertEqual(urlify(d[0]), d[1])


if __name__ == '__main__':
    unittest.main()
