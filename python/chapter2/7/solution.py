def intersection(first_list, second_list):
    if not first_list and second_list:
        return False
    if not second_list:
        return True
    first_char_second_list = second_list[0]
    same = True
    for x in range(len(first_list)):
        if first_list[x] == first_char_second_list:
            for y in range(1, len(second_list)):
                if len(first_list[x + y:]):
                    if second_list[y] != first_list[x + y]:
                        same = False
                        break
            if same:
                return True
    return False


if __name__ == '__main__':
    first_list = [8, 7, 9, 5, 4, 8, 6]
    second_list = [5, 4, 8]
    assert intersection(first_list, second_list)
    first_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    second_list = [4, 5, 7]
    assert intersection(first_list, second_list) == False
