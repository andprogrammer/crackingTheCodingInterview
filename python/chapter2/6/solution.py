def check_if_palindrom(data):
    if len(data) <= 1:
        return True
    while len(data) > 1:
        left = data.pop(0)
        right = data.pop()
        if left != right:
            return False
    return True


if __name__ == '__main__':
    l = [5, 4, 8, 8, 4, 5]
    assert check_if_palindrom(l)
    l = [8, 4, 99, 4, 8]
    assert check_if_palindrom(l)
