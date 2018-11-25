class MyStack(object):
    def __init__(self, size):
        self.stack_size = size
        self.array = 3 * [0] * size
        self.sizes = 3 * [0]

    def push(self, elem, stack_num):
        if self.is_full(stack_num):
            raise Exception('Stack {} is full', stack_num)
        self.sizes[stack_num] += 1
        self.array[self._index_of_top(stack_num)] = elem

    def pop(self, stack_num):
        if self.is_empty(stack_num):
            raise Exception('Stack is empty')
        top = self.array[self._index_of_top(stack_num)]
        self.array[self._index_of_top(stack_num)] = 0
        self.sizes[stack_num] -= 1
        return top

    def top(self, stack_num):
        if self.is_empty(stack_num):
            raise Exception('Stack {} is empty', stack_num)
        return self.array[self._index_of_top(stack_num)]

    def is_empty(self, stack_num):
        return self.sizes[stack_num] == 0

    def is_full(self, stack_num):
        return self.sizes[stack_num] == self.stack_size

    def _index_of_top(self, stack_num):
        return self.stack_size * stack_num + self.sizes[stack_num] - 1

    def print_stack(self):
        counter = 0
        for i in self.array:
            if counter == self.stack_size:
                counter = 0
                print('')
            counter += 1
            print(i, ' ', end='')
        print()


if __name__ == '__main__':
    stack = MyStack(4)
    stack.print_stack()
    stack.push(7, 2)
    stack.push(4, 2)
    stack.push(9, 0)
    stack.push(1, 0)
    stack.push(6, 2)
    print('delimiter')
    stack.print_stack()
    print('top elem=', stack.top(0))
    print('top elem=', stack.top(2))
    stack.pop(2)
    print('top elem=', stack.top(2))
