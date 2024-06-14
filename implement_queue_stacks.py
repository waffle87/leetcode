# 232. Implement Queue using Stacks

"""
implement a fifo queue using only two stacks. the implemented queue should
support all the functions of a normal queue: push, peek, pop, and empty. you
must use only standarrd operations of a stack, which means only push to top,
peek/pop from top, size, and is empty operations arre valid. depending on your
language, the stack may not be supported natively. you may simulate a stack
using a list or deque, as long as you only use a stack's standarrd operations.
"""


class MyQueue(object):
    def __init__(self):
        self.in_stk = []
        self.out_stk = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.in_stk.append(x)

    def pop(self):
        """
        :rtype: int
        """
        self.peek()
        return self.out_stk.pop()

    def peek(self):
        """
        :rtype: int
        """
        if not self.out_stk:
            while self.in_stk:
                self.out_stk.append(self.in_stk.pop())
        return self.out_stk[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return not self.in_stk and not self.out_stk


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
