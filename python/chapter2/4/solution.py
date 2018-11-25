def partition(data, x):
    if not x:
        raise Exception('Incorrect data')
    temp = [x]
    for i in data:
        if i <= x:
            temp.insert(0, i)
        else:
            temp.append(i)
    return temp


if __name__ == '__main__':
    container = [5, 9, 7, 1, 6, 4, 8, 3, 7, 6]
    try:
        print(partition(container, 5))
    except Exception as e:
        print(e)
