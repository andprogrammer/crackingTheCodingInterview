def sum_lists(first_list, second_list):
    first_number = calculation(first_list)
    second_number = calculation(second_list)
    return first_number + second_number


def calculation(data):
    if not data:
        raise Exception('Incorrect data')
    multiplier = multiply_multiplier(len(data) - 1)
    result = 0
    while data:
        result += multiplier * data.pop()
        multiplier //= 10
    return result


def multiply_multiplier(x):
    result = 1
    for i in range(x):
        result *= 10
    return result


if __name__ == '__main__':
    first_list = [7, 1, 6]
    second_list = [5, 9, 2]
    print(sum_lists(first_list, second_list))
