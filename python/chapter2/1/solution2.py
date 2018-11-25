class Node(object):
    def __init__(self):
        self.value = None
        self.next = None


class LinkedList(object):
    def __init__(self):
        self.root = None

    def add(self, value):
        new_node = Node()
        new_node.value = value
        if not self.root:
            self.root = new_node
            return
        runner = self.root
        while runner.next:
            runner = runner.next
        runner.next = new_node

    def print(self):
        if not self.root:
            return
        runner = self.root
        while runner:
            print(runner.value)
            runner = runner.next


def remove_dups(linked_list):
    if not linked_list.root:
        return
    seen = set()
    runner = linked_list.root
    while runner.next:
        if runner.next.value in seen:
            runner.next = runner.next.next
        else:
            seen.add(runner.next.value)
            runner = runner.next


if __name__ == '__main__':
    linked_list = LinkedList()
    linked_list.add(4)
    linked_list.add(2)
    linked_list.add(2)
    linked_list.add(2)
    linked_list.add(16)
    remove_dups(linked_list)
    linked_list.print()
