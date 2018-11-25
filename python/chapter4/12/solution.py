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


def paths_with_sum(bst, total):
    array = []
    bst.preorder(bst.root, array)
    print('Path with sums = ', check_sum(get_array_of_arrays(array), total))


def get_array_of_arrays(array):
    if not array:
        return
    tmp = []
    shift = 0
    while shift < len(array):
        tmp.append(array[shift:])
        shift += 1
    return tmp


def check_sum(arrays, total):
    if not arrays:
        return
    counter = 0
    for arr in arrays:
        shifter = len(arr)
        while shifter > 0:
            if sum(arr[:shifter]) == total:
                counter += 1
            shifter -= 1
    return counter


if __name__ == '__main__':
    array = [1, 2, 5, 6]
    my_bst = bst(Node(3))

    minimal_tree(array, my_bst)
    paths_with_sum(my_bst, 6)

# My approach
# preorder
# calculate sublists
# 3 2 1 5 6
# 2 1 5 6
# 1 5 6
# 5 6
# 6
# get num of sums
