d = {
    1: 'a',
    2: 'b',
    3: 'c',
    4: 'd'}
print(d)


def decode(input):
    if len(input) == 1:
        return 1
    if len(input) == 0:
        return 1
    return decode(input[0]) + decode(input[1:])


def main():
    input = '12'
    print(decode(input))


if __name__ == "__main__":
    main()
