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

    def inorder(self, node):
        if not node:
            return
        self.inorder(node.left)
        print(node.data)
        self.inorder(node.right)


def minimal_tree(array, bst):
    if not array:
        return
    mid = len(array) // 2
    mid_elem = array[mid]
    root = bst.root
    bst.insert(root, mid_elem)
    minimal_tree(array[0: mid], bst)
    minimal_tree(array[mid + 1:], bst)


def height(node):
    if not node:
        return 0
    return max(height(node.left), height(node.right)) + 1


def is_balanced(node):
    if not node:
        return True
    left = height(node.left)
    right = height(node.right)
    return False if abs(left - right) > 1 else is_balanced(node.left) and is_balanced(node.right)


if __name__ == '__main__':
    array = [1, 2, 5, 6]
    my_bst = bst(Node(3))

    minimal_tree(array, my_bst)
    print(is_balanced(my_bst.root))
