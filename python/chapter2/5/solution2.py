from LinkedList import LinkedList


def sum(linked_list_left, linked_list_right):
    return calculation(linked_list_left) + calculation(linked_list_right)


def calculation(linked_list):
    if not linked_list.root:
        return
    runner = linked_list.root
    multiplier = 1
    score = 0
    while runner.next:
        score += (multiplier * runner.value)
        multiplier *= 10
        runner = runner.next
    return (multiplier * runner.value) + score


if __name__ == '__main__':
    linked_list_left = LinkedList()
    linked_list_left.add(7)
    linked_list_left.add(1)
    linked_list_left.add(6)

    linked_list_right = LinkedList()
    linked_list_right.add(5)
    linked_list_right.add(9)
    linked_list_right.add(2)
    print(sum(linked_list_left, linked_list_right))
