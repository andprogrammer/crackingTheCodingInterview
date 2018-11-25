def kth_to_last(container, k):
    if len(container) < k:
        return
    return container[-k]


if __name__ == '__main__':
    l = [5, 2, 0, 3, 77, 43, 34]
    print(kth_to_last(l, 2))
