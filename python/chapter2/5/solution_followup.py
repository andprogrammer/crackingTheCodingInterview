def sum_lists(first_list, second_list):
    first_number = calculation(first_list)
    second_number = calculation(second_list)
    return first_number + second_number


def calculation(data):
    if not data:
        raise Exception('Incorrect data')
    multiplier = 1
    result = 0
    while data:
        result += multiplier * data.pop()
        multiplier *= 10
    return result


if __name__ == '__main__':
    first_list = [6, 1, 7]
    second_list = [2, 9, 5]
    print(sum_lists(first_list, second_list))
