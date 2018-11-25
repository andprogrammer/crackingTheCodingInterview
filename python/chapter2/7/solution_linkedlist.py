from LinkedList import LinkedList


def intersection(first, second):
    if first and not second:
        return True
    if first.size() < second.size():
        return False
    first_runner = first.root
    second_first_value = second.root.value
    while first_runner.next:
        if first_runner.value == second_first_value:
            if check_intersection(first_runner, second):
                return True
        first_runner = first_runner.next
    return True if (first_runner.value == second_first_value and second.size() == 1) else False


def check_intersection(start_node, intersect):
    if not start_node:
        return False
    if start_node and not intersect:
        return True
    runner = start_node
    runner_intersect = intersect.root
    while runner:
        if not runner_intersect:
            return True
        if runner.value != runner_intersect.value:
            return False
        runner = runner.next
        runner_intersect = runner_intersect.next
    if runner_intersect:
        return False
    return True


if __name__ == '__main__':
    print(check_intersection(None, None))

    linked_list_first = LinkedList()
    linked_list_first.add(6)
    linked_list_first.add(6)

    linked_list_second = LinkedList()
    linked_list_second.add(6)
    linked_list_second.add(6)
    print(check_intersection(linked_list_first.root, linked_list_second))

    linked_list_first = LinkedList()
    linked_list_first.add(1)
    linked_list_first.add(6)
    linked_list_first.add(6)

    linked_list_second = LinkedList()
    linked_list_second.add(6)
    linked_list_second.add(6)
    print(check_intersection(linked_list_first.root, linked_list_second))

    linked_list_first = LinkedList()
    linked_list_first.add(1)
    linked_list_first.add(1)
    linked_list_first.add(6)

    linked_list_second = LinkedList()
    linked_list_second.add(1)
    linked_list_second.add(1)
    print(check_intersection(linked_list_first.root, linked_list_second))

    # Example of function usage
    linked_list_first = LinkedList()
    linked_list_first.add(6)
    linked_list_first.add(1)
    linked_list_first.add(4)
    linked_list_first.add(73)

    linked_list_second = LinkedList()
    linked_list_second.add(1)
    linked_list_second.add(4)
    print(intersection(linked_list_first, linked_list_second))
