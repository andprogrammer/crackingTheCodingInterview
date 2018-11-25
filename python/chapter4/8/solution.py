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


def first_common_ancestor(bst, value1, value2):
    path = []
    bst.preorder(bst.root, path)
    path_value1 = get_sublist(path, value1)
    path_value2 = get_sublist(path, value2)
    path_value1.pop()
    path_value2.pop()
    ancestor = get_common_ancestor(path_value1, path_value2)
    if ancestor != -9999:
        print('ancestor = ', ancestor)
        return
    print('Common ancestor not found!')


def get_common_ancestor(sublist1, sublist2):
    if not sublist1 or not sublist2:
        raise Exception('Incorrect data')
    for x in reversed(sublist2):
        for y in reversed(sublist1):
            if x == y:
                return x
    return -9999


def get_sublist(array, end):
    if not array or not end:
        raise Exception('Incorrect data')
    sublist = []
    for i in array:
        sublist.append(i)
        if i == end:
            return sublist
    return []


if __name__ == '__main__':
    array = [1, 2, 5, 6]
    my_bst = bst(Node(3))

    minimal_tree(array, my_bst)
    first_common_ancestor(my_bst, 2, 5)
