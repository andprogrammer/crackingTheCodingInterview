from LinkedList import LinkedList


def loop_detection(first, second):
    if not first:
        return False
    runner_f = first

    while runner_f.next:
        runner_s = second
        while runner_s.next:
            if runner_f == runner_s:
                return True
            runner_s = runner_s.next
        runner_f = runner_f.next
    return False


if __name__ == '__main__':
    print(loop_detection(None, None))

    linked_list_first = LinkedList()
    linked_list_first.add(6)
    linked_list_first.add(6)
    print(loop_detection(linked_list_first.root, linked_list_first.root))

    linked_list_first = LinkedList()
    linked_list_first.add(6)
    linked_list_first.add(6)

    linked_list_second = LinkedList()
    linked_list_second.add(6)
    linked_list_second.add(6)
    print(loop_detection(linked_list_first.root, linked_list_second.root))
