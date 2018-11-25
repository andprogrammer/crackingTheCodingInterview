class SortStack(object):
    def __init__(self):
        self.stack = []

    def push(self, elem):
        if self.is_empty():
            self.stack.append(elem)
            return
        temp_stack = []
        while self.stack and self.top() < elem:
            temp_stack.append(self.top())
            self.pop()
        self.stack.append(elem)
        while temp_stack:
            self.stack.append(temp_stack.pop())

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

    def print_stack(self):
        for i in reversed(self.stack):
            print('[', i, ']')


if __name__ == '__main__':
    sort_stack = SortStack()
    sort_stack.push(36)
    sort_stack.push(23)
    sort_stack.push(5)
    sort_stack.push(43)
    sort_stack.push(59)
    sort_stack.push(7)
    sort_stack.push(78)
    sort_stack.print_stack()
    print('top elem=', sort_stack.top())
    sort_stack.pop()
    sort_stack.pop()
    print('top elem=', sort_stack.top())
    sort_stack.print_stack()
