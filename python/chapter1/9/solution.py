import unittest


def change_str(data):
    data_len = len(data)
    if data_len <= 0:
        raise Exception("Incorrect data")
    if data_len == 1:
        return data
    return data[1:] + data[0]


def string_rotation(str1, str2):
    if len(str1) != len(str2):
        return False
    str1_len = len(str1)
    counter = 0
    str1_temp = str1
    while str1_temp != str2 and counter < str1_len:
        counter += 1
        str1_temp = change_str(str1_temp)
    return True if str1_temp == str2 else False


class Test(unittest.TestCase):
    data = [
        ('waterbottle', 'erbottlewat', True),
        ('tomek', 'ktome', True),
        ('', '', True),
        ('foo', 'bar', False),
        ('foo', 'foofoo', False)
    ]

    def test_string_rotation(self):
        for [s1, s2, expected] in self.data:
            actual = string_rotation(s1, s2)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
    s = "tomek"
    print(change_str(s))
