class Stack(object):
    def __init__(self, capacity):
        self.capacity = capacity
        self.stack = []
        self.size = 0

    def push(self, elem):
        if self.is_full():
            raise Exception('Stack is full')
        self.size += 1
        self.stack.append(elem)

    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        del self.stack[-1]

    def top(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        return self.stack[-1]

    def is_empty(self):
        return not self.size

    def is_full(self):
        return self.size == self.capacity

    def print_stack(self):
        for i in reversed(self.stack):
            print('[{}]'.format(i))


class StackOfPlates(object):
    def __init__(self, max_height):
        self.max_height = max_height
        self.stacks = []

    def push(self, elem):
        if self.stacks:
            last = self.stacks[-1]
            if last.is_full():
                self._add_new_stack(elem)
            else:
                last.push(elem)
        else:
            self._add_new_stack(elem)

    def _add_new_stack(self, elem):
        new_stack = Stack(self.max_height)
        new_stack.push(elem)
        self.stacks.append(new_stack)

    def pop(self):
        if self.stacks:
            last = self.stacks[-1]
            last.pop()

    def top(self):
        if self.stacks:
            last = self.stacks[-1]
            return last.top()
        else:
            raise Exception('Stack is empty')

    def print_stack(self):
        for stack in reversed(self.stacks):
            stack.print_stack()


if __name__ == '__main__':
    plates = StackOfPlates(3)
    plates.push(1)
    plates.push(2)
    plates.pop()
    plates.push(3)
    plates.push(4)
    plates.pop()
    plates.push(5)
    print('top=', plates.top())
    plates.push(6)
    plates.push(7)
    print('top=', plates.top())
    plates.print_stack()