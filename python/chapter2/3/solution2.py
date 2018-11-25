from LinkedList import LinkedList
from unittest import TestCase, main


def get_middle_node(linked_list):
    if not linked_list:
        raise Exception('Incorrect linked list')
    runner = linked_list.root
    faster = linked_list.root
    while faster and faster.next:
        runner = runner.next
        faster = faster.next.next
    return runner.value


def delete_middle_node(linked_list):
    try:
        middle = get_middle_node(linked_list)
        print(middle)
        linked_list.remove(middle)
        return linked_list
    except Exception as ex:
        print("Incorrect data" + ex)


class LinkedListTestSuite(TestCase):
    def setUp(self):
        self.linked_list = LinkedList()

    def test_check_middle(self):
        self.linked_list.add(78)
        self.assertEqual(get_middle_node(self.linked_list), 78)

        self.linked_list.add(90)
        self.assertEqual(get_middle_node(self.linked_list), 90)

        self.linked_list.add(34)
        self.assertEqual(get_middle_node(self.linked_list), 90)

        self.linked_list.add(12)
        self.assertEqual(get_middle_node(self.linked_list), 34)

        self.linked_list.add(56)
        self.assertEqual(get_middle_node(self.linked_list), 34)


if __name__ == '__main__':
    main()
