from unittest import TestCase, main
from random import randint


class Node(object):
    def __init__(self):
        self.value = None
        self.next = None

    def __str__(self):
        return str(self.value)


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

    def remove(self, value):
        if not self.root:
            return
        if self.root.value == value:
            self.root = self.root.next
            return
        runner = self.root
        while runner.next:
            if runner.next.value == value:
                runner.next = runner.next.next
                break
            runner = runner.next

    def size(self):
        if not self.root:
            return 0
        counter = 1
        runner = self.root
        while runner.next:
            counter += 1
            runner = runner.next
        return counter

    def first(self):
        if not self.root:
            return
        return self.root.value

    def print_list(self):
        if not self.root:
            return
        runner = self.root
        while runner:
            print(runner.value)
            runner = runner.next

    def __str__(self):
        if not self.root:
            return ''
        runner = self.root
        values = ''
        while runner.next:
            values += str(runner.value) + '->'
            runner = runner.next
        values += str(runner.value)
        return values


class LinkedListTestSuite(TestCase):
    def setUp(self):
        self.linked_list = LinkedList()

    def test_list_add(self):
        self.assertEqual(self.linked_list.size(), 0)

        self.linked_list.add(78)
        self.assertEqual(self.linked_list.size(), 1)

        self.linked_list.add(89)
        self.linked_list.add(7)
        self.assertEqual(self.linked_list.size(), 3)

        self.linked_list.add(89)
        self.linked_list.add(45)
        self.linked_list.add(11)
        self.assertEqual(self.linked_list.size(), 6)

        current_size = self.linked_list.size()
        number_of_new_elements = 5
        for _ in range(number_of_new_elements):
            self.linked_list.add(randint(0, number_of_new_elements))
        self.assertEqual(self.linked_list.size(), current_size + number_of_new_elements)

    def test_list_remove(self):
        self.linked_list.add(78)
        self.linked_list.remove(self.linked_list.first())
        self.assertEqual(self.linked_list.size(), 0)

        self.linked_list.add(89)
        self.linked_list.add(7)
        self.linked_list.remove(7)
        self.assertEqual(self.linked_list.size(), 1)

        self.linked_list.add(89)
        self.linked_list.add(45)
        self.linked_list.add(11)
        self.linked_list.add(63)
        self.linked_list.add(7)
        self.linked_list.remove(7)
        self.assertEqual(self.linked_list.size(), 5)

    def test_list_size(self):
        self.assertEqual(self.linked_list.size(), 0)

        self.linked_list.add(9)
        self.assertEqual(self.linked_list.size(), 1)

        self.linked_list.remove(9)
        self.assertEqual(self.linked_list.size(), 0)

        self.linked_list.add(31)
        self.linked_list.add(22)
        self.linked_list.add(13)
        self.assertEqual(self.linked_list.size(), 3)

    def test_list_first(self):
        self.assertIsNone(self.linked_list.first())

        self.linked_list.add(32)
        self.assertEqual(self.linked_list.first(), 32)

        self.linked_list.add(78)
        self.assertEqual(self.linked_list.first(), 32)

        self.linked_list.add(101)
        self.linked_list.add(999)
        self.assertEqual(self.linked_list.first(), 32)


if __name__ == '__main__':
    main()
