from LinkedList import LinkedList


def palindrome(linked_list):
    if not linked_list.root:
        return True
    temp_stack = []
    runner = linked_list.root
    while runner.next:
        temp_stack.append(runner.value)
        runner = runner.next
    check_list = LinkedList()
    if runner:
        check_list.add(runner.value)
    while temp_stack:
        check_list.add(temp_stack.pop())
    return check_palindrome(linked_list, check_list)


def check_palindrome(first_linked_list, second_linked_list):
    if first_linked_list.size() != second_linked_list.size():
        return False
    runner_first_linked_list = first_linked_list.root
    runner_v = second_linked_list.root
    while runner_first_linked_list.next:
        if runner_first_linked_list.value != runner_v.value:
            return False
        runner_first_linked_list = runner_first_linked_list.next
        runner_v = runner_v.next
    return True


if __name__ == '__main__':
    linked_list = LinkedList()
    linked_list.add(6)
    linked_list.add(1)
    linked_list.add(7)
    linked_list.add(2)
    linked_list.add(9)
    linked_list.add(5)
    print(palindrome(linked_list))

    linked_list = LinkedList()
    linked_list.add(6)
    linked_list.add(1)
    linked_list.add(7)
    linked_list.add(7)
    linked_list.add(1)
    linked_list.add(6)
    print(palindrome(linked_list))

    linked_list = LinkedList()
    print(palindrome(linked_list))

    linked_list = LinkedList()
    linked_list.add(6)
    print(palindrome(linked_list))

    linked_list = LinkedList()
    linked_list.add(6)
    linked_list.add(4)
    print(palindrome(linked_list))