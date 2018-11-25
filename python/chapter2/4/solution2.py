from LinkedList import LinkedList


def partition(linked_list, k):
    if not linked_list.root:
        return
    runner = linked_list.root
    left_container = []
    right_container = []
    while runner.next:
        if runner.value == k:
            right_container = [k] + right_container
        elif runner.value < k:
            left_container.append(runner.value)
        else:
            right_container.append(runner.value)
        runner = runner.next
    return left_container + right_container


if __name__ == '__main__':
    linked_list = LinkedList()
    linked_list.add(4)
    linked_list.add(2)
    linked_list.add(65)
    linked_list.add(7)
    linked_list.add(9)
    linked_list.add(16)
    linked_list.add(1)
    linked_list.add(6)
    linked_list.add(5)
    print(partition(linked_list, 9))
