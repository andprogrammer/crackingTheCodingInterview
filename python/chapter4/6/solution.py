class Node(object):
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return '{} '.format(self.data)


class bst(object):
    def __init__(self, root=None):
        self.root = root

    def insert(self, runner, elem):
        if not runner:
            return
        if elem < runner.data:
            if runner.left:
                self.insert(runner.left, elem)
            else:
                runner.left = Node(elem)
                return
        elif elem > runner.data:
            if runner.right:
                self.insert(runner.right, elem)
            else:
                runner.right = Node(elem)
                return

    def inorder(self, node, array):
        if not node:
            return
        self.inorder(node.left, array)
        array.append(node.data)
        self.inorder(node.right, array)


def minimal_tree(array, bst):
    if not array:
        return
    mid = len(array) // 2
    mid_elem = array[mid]
    root = bst.root
    bst.insert(root, mid_elem)
    minimal_tree(array[0: mid], bst)
    minimal_tree(array[mid + 1:], bst)


def find_next(array, finder):
    found = False
    for elem in array:
        if found:
            return elem
        if elem == finder:
            found = True
    return -9999


def successor(bst, finder):
    if not bst:
        return
    array = []
    bst.inorder(bst.root, array)
    next = find_next(array, finder)
    if next != -9999:
        print('next = ', next)
    else:
        print('next not found!')


if __name__ == '__main__':
    array = [1, 2, 3, 4, 5, 7, 8, 9, 10]
    my_bst = bst(Node(6))

    minimal_tree(array, my_bst)
    successor(my_bst, 8)
