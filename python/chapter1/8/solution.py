import unittest
import copy


def print_matrix(matrix):
    num_of_rows = len(matrix)
    for i in range(num_of_rows):
        print("".join(str(matrix[i])))
    print("---------------------------")


def copy_matrix(matrix):
    num_of_cols = len(matrix[0])
    num_of_rows = len(matrix)
    new_matrix = []
    for i in range(num_of_rows):
        new_matrix.append(matrix[i])
    print_matrix(new_matrix)
    return new_matrix


def zero_matrix(matrix):
    num_of_cols = len(matrix[0])
    num_of_rows = len(matrix)
    matrix_copy = copy.deepcopy(matrix)
    for i in range(num_of_cols):
        for j in range(num_of_rows):
            if matrix_copy[i][j] == 0:
                set_zero_on_row(matrix, i)
                set_zero_on_column(matrix, j)
    return matrix


def set_zero_on_row(matrix, row):
    num_of_cols = len(matrix[0])
    num_of_rows = len(matrix)
    for i in range(num_of_cols):
        matrix[row][i] = 0


def set_zero_on_column(matrix, column):
    num_of_cols = len(matrix[0])
    num_of_rows = len(matrix)
    for i in range(num_of_rows):
        matrix[i][column] = 0


class Test(unittest.TestCase):
    data = [
        ([
             [1, 2, 3, 4, 0],
             [6, 0, 8, 9, 10],
             [11, 12, 13, 14, 15],
             [16, 0, 18, 19, 20],
             [21, 22, 23, 24, 25]
         ], [
             [0, 0, 0, 0, 0],
             [0, 0, 0, 0, 0],
             [11, 0, 13, 14, 0],
             [0, 0, 0, 0, 0],
             [21, 0, 23, 24, 0]
         ])
    ]

    def test_zero_matrix(self):
        for [test_matrix, expected] in self.data:
            actual = zero_matrix(test_matrix)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
