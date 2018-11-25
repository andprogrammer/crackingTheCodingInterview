import unittest


def string_compression(data):
    if not data:
        return
    current_letter = data[0]
    letter_counter = 1
    data_len = len(data)
    output = ""
    for i in range(1, data_len):
        if data[i] == current_letter:
            letter_counter += 1
        else:
            output += current_letter + str(letter_counter)
            current_letter = data[i]
            letter_counter = 1
    output += current_letter + str(letter_counter)
    return min(data, output, key=len)


class Test(unittest.TestCase):
    data = {
        ('aabcccccaaa', 'a2b1c5a3'),
        ('abcdef', 'abcdef')}

    def test_string_compression(self):
        for test_string, expected in self.data:
            self.assertEqual(string_compression(test_string), expected)


if __name__ == '__main__':
    unittest.main()
