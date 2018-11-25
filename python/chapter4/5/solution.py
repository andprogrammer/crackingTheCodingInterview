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

    def inorder(self, node, visited):
        if not node:
            return
        self.inorder(node.left, visited)
        visited.append(node.data)
        self.inorder(node.right, visited)


def minimal_tree(array, bst):
    if not array:
        return
    mid = len(array) // 2
    mid_elem = array[mid]
    root = bst.root
    bst.insert(root, mid_elem)
    minimal_tree(array[0: mid], bst)
    minimal_tree(array[mid + 1:], bst)


def is_ascending(array):
    return sorted(array) == array


def is_bst(bst):
    if not bst:
        return False
    visited = []
    bst.inorder(bst.root, visited)
    return is_ascending(visited)


if __name__ == '__main__':
    my_bst = bst(Node(6))

    my_bst.root.left = Node(5)
    my_bst.root.right = Node(10)
    print(is_bst(my_bst))
