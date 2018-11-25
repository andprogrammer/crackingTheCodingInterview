from LinkedList import LinkedList


def kth_to_last(linked_list, k):
    if not linked_list.root:
        raise Exception('Incorrect data')
    linked_list_size = linked_list.size()
    if k > linked_list_size:
        raise Exception('k greater than len of linked_list')
    counter = 0
    runner = linked_list.root
    shift = (linked_list_size - k)
    while counter < shift:
        counter += 1
        runner = runner.next
        if counter == shift:
            break
    return runner.value


if __name__ == '__main__':
    linked_list = LinkedList()
    linked_list.add(4)
    linked_list.add(2)
    linked_list.add(8)
    linked_list.add(69)
    linked_list.add(16)
    print(kth_to_last(linked_list, 3))
