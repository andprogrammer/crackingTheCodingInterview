class MyQueue(object):
    def __init__(self):
        self.stack = []

    def push(self, elem):
        self.stack.append(elem)

    def pop(self):
        if self.is_empty():
            raise Exception('Queue is empty')
        del self.stack[-1]

    def top(self):
        if self.is_empty():
            raise Exception('Queue is empty')
        return self.stack[-1]

    def is_empty(self):
        return not self.stack

    def print_queue(self):
        for i in reversed(self.stack):
            print('[', i, ']')


if __name__ == '__main__':
    queue = MyQueue()
    queue.push(5)
    queue.push(4)
    queue.push(36)
    queue.push(59)
    queue.push(7)
    queue.print_queue()
    print('top elem=', queue.top())
    queue.pop()
    queue.pop()
    print('top elem=', queue.top())
