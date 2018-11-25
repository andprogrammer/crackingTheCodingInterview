def delete_middle_node(container):
    container_len = len(container)
    if len(container) < 2:
        return None
    left = int(container_len / 2)
    right = int(container_len / 2) + 1
    return container[:left] + container[right:]


if __name__ == '__main__':
    l = [5, 3, 7, 2, 90]
    print(delete_middle_node(l))
