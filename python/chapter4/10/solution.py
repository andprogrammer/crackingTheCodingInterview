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

    def preorder(self, root, path):
        if not root:
            return
        path.append(root.data)
        self.preorder(root.left, path)
        self.preorder(root.right, path)


def minimal_tree(array, bst):
    if not array:
        return
    mid = len(array) // 2
    mid_elem = array[mid]
    root = bst.root
    bst.insert(root, mid_elem)
    minimal_tree(array[0: mid], bst)
    minimal_tree(array[mid + 1:], bst)


def check_subtree(first_bst, second_bst):
    if not second_bst:
        return True
    if not first_bst and second_bst:
        return False
    first_path = []
    first_bst.preorder(first_bst.root, first_path)

    second_path = []
    second_bst.preorder(second_bst.root, second_path)

    if check_subpath(first_path, second_path):
        print('This is Subtree')
    else:
        print('This is not Subtree')


def check_subpath(first_path, second_path):
    if not second_path:
        return True
    if not first_path and second_path:
        return False
    if len(second_path) > len(first_path):
        return False

    shifter = 0
    same = False
    for x in first_path:
        if x == second_path[shifter]:
            same = True
            shifter += 1
            continue
        if same:
            return False
    return True


if __name__ == '__main__':
    first_array = [1, 2, 5, 6]
    first_bst = bst(Node(3))

    second_array = [6, 5]
    second_bst = bst(Node(1))

    minimal_tree(first_array, first_bst)
    minimal_tree(second_array, second_bst)

    check_subtree(first_bst, second_bst)
