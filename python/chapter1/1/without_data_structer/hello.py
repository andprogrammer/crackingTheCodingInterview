def is_unique(data):
    if not data:
        return False
    input_len = len(data)
    for i in range(0, input_len - 1):
        j = input_len - 1
        while j > i:
            if data[j] == data[i]:
                return False
            j -= 1
    return True


def run():
    assert is_unique("") is False
    assert is_unique("mam") is False
    assert is_unique("Tomek")
    assert is_unique("ala ma kota") is False
    assert is_unique("aa") is False
    assert is_unique("not same")


if __name__ == '__main__':
    run()
