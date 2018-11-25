import unittest


def remove_duplicates(container):
    l_len = len(container)
    if not l_len:
        return container
    seen = set()
    list_temp = []
    for c in container:
        if c not in seen:
            seen.add(c)
            list_temp.append(c)
    return list_temp


class Test(unittest.TestCase):
    data = [
        ([5, 3, 6, 2, 2], [5, 3, 6, 2]),
        ([], []),
        ([32], [32]),
        ([45, 45, 45], [45])
    ]

    def test_string_rotation(self):
        for s1, s2 in self.data:
            none_duplicates = remove_duplicates(s1)
            self.assertTrue(none_duplicates == s2)


if __name__ == '__main__':
    unittest.main()
