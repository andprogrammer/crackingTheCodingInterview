#nie do konca rozwiazanie problemu z tresci zadania - nie uzywam LinkedList

def loop_detection(first_list, second_list):
    for x in first_list:
        for y in second_list:
            if x == y:
                return True
    return False


if __name__ == '__main__':
    first_list = [8, 7, 9, 5, 4, 8, 6]
    second_list = [5, 9]
    assert loop_detection(first_list, second_list)
    first_list = [1, 2, 3, 4]
    second_list = [40, 50, 60, 60]
    assert loop_detection(first_list, second_list) == False
