from sys import maxsize


class MyStack(object):
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.array = [0] * capacity
        self.min_v = maxsize

    def push(self, elem):
        if self.is_full():
            raise Exception('Stack is full')
        self.size += 1
        self.array[self._index_of_top()] = elem
        self.min_v = min(self.min_v, elem)

    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        top = self.array[self._index_of_top()]
        self.array[self._index_of_top()] = 0
        self.size -= 1
        if self.size:
            self.min_v = min(self.array[:self._index_of_top()])
        else:
            self.min_v = maxsize
        return top

    def top(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        return self.array[self._index_of_top()]

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def _index_of_top(self):
        return self.size - 1

    def min_value(self):
        if self.min_v == maxsize:
            raise Exception('min value does not defined')
        return self.min_v

    def print_stack(self):
        for i in reversed(self.array):
            print('[', i, ']')


if __name__ == '__main__':
    stack = MyStack(5)
    stack.print_stack()
    stack.push(5)
    stack.push(4)
    stack.push(36)
    stack.push(56)
    stack.push(7)
    print('delimiter')
    print('min value=', stack.min_value())
    stack.print_stack()
    print('top elem=', stack.top())
    stack.pop()
    print('min value=', stack.min_value())
    print('top elem=', stack.top())
