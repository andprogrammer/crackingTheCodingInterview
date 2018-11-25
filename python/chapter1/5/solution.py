import unittest


def one_away(data1, data2):
    return one_replaced(data1, data2) if len(data1) == len(data2) else one_changed(data1, data2)


def one_replaced(data1, data2):
    if len(data1) != len(data2):
        return False
    changes = 0
    for x, y in zip(data1, data2):
        if x != y:
            if changes > 0:
                return False
            changes += 1
    return True


def one_changed(data1, data2):
    """Removed or Inserted"""
    if abs(len(data1) - len(data2)) != 1:
        return False
    index = 0
    for x, y in zip(data1, data2):
        if x != y:
            if data1[index:] == data2[index + 1:] or data1[index + 1:] == data2[index:]:
                return True
            return False
        index += 1
    return True


class Test(unittest.TestCase):
    def setUp(self):
        self.data_one_replaced = {
            ('', 'a', False),
            ('pale', 'pele', True),
            ('dodo', 'dede', False)}
        self.data_one_changed = {
            ('test', 'tst', True),
            (' ', '', True),
            ('   ', ' ', False),
            ('car', 'ca', True),
            ('deakor', 'dekor', True)}
        self.data = {
            ('pale', 'ple', True),
            ('pales', 'pale', True),
            ('pale', 'bale', True),
            ('paleabc', 'pleabc', True),
            ('pale', 'ble', False),
            ('a', 'b', True),
            ('', 'd', True),
            ('d', 'de', True),
            ('pale', 'pale', True),
            ('pale', 'ple', True),
            ('ple', 'pale', True),
            ('pale', 'bale', True),
            ('pale', 'bake', False),
            ('pale', 'pse', False),
            ('ples', 'pales', True),
            ('pale', 'pas', False),
            ('pas', 'pale', False),
            ('pale', 'pkle', True),
            ('pkle', 'pable', False),
            ('pal', 'palks', False),
            ('palks', 'pal', False)}

    def test_one_replaced(self):
        for test1, test2, expected in self.data_one_replaced:
            self.assertEqual(one_replaced(test1, test2), expected)

    def test_one_removed(self):
        for test1, test2, expected in self.data_one_changed:
            self.assertEqual(one_changed(test1, test2), expected)

    def test_one_away(self):
        for [test_s1, test_s2, expected] in self.data:
            self.assertEqual(one_away(test_s1, test_s2), expected)


if __name__ == '__main__':
    unittest.main()
