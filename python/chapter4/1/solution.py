class Node(object):
    def __init__(self, data, neighbours=[]):
        self.data = data
        self.neighbours = neighbours

    def print_neighbours(self):
        print('\t[{}]'.format(self.data))
        for i in self.neighbours:
            print(i)


class Graph(object):
    def __init__(self, nodes=[]):
        self.nodes = nodes

    def print_graph(self):
        for i in self.nodes:
            i.print_neighbours()


def route_between_nodes(graph, start, end):
    if not graph or not graph.nodes or not graph or not start or not end:
        raise Exception('Incorrect graph')
    root = graph.nodes[0]
    visited_nodes = []
    queue = [root]
    node_found = False
    while queue:
        curr_node = queue.pop(0)
        if curr_node.data == start.data or curr_node.data == end.data:
            if node_found:
                return True
            node_found = True
        if curr_node.data not in visited_nodes:
            visited_nodes.append(curr_node.data)
            print(curr_node.data)
            for i in curr_node.neighbours:
                queue.append(i)
    return False


if __name__ == '__main__':
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node5 = Node(5)
    node6 = Node(6)

    node1.neighbours = [node2, node3]
    node2.neighbours = [node4, node5]
    node3.neighbours = [node5]
    node4.neighbours = [node5]

    all_nodes = [node1, node2, node3, node4, node5, node6]
    my_graph = Graph(all_nodes)
    print(route_between_nodes(my_graph, node2, node6))
    print(route_between_nodes(my_graph, node4, node3))
