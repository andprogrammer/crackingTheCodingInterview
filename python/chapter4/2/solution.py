class Node(object):
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


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


if __name__ == '__main__':
    array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 15, 18, 22, 43, 144, 515, 4123]
    my_bst = bst(Node(10))

    minimal_tree(array, my_bst)
    my_bst.inorder(my_bst.root)
