# 729. My Calendar I

"""
you are implementing a program to use as your calendar. we can add a new
event if adding the event will not cause a double booking. a double booking
happens when two events have some non empty intersection (ie. some moment is
common to both events.). the event can be represented as a pair of integers
'start' and 'end' that represent a booking on the half open interval '[start,
end)', the range of real numbers 'x' such that 'start <= x < end'.
"""


class Node:
    def __init__(self, s, e):
        self.e = e
        self.s = s
        self.left = None
        self.right = None


class MyCalendar(object):
    def __init__(self):
        self.root = None

    def book_helper(self, s, e, node):
        if s >= node.e:
            if node.right:
                return self.book_helper(s, e, node.right)
            else:
                node.right = Node(s, e)
                return True
        elif e <= node.s:
            if node.left:
                return self.book_helper(s, e, node.left)
            else:
                node.left = Node(s, e)
                return True
        else:
            return False

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        if not self.root:
            self.root = Node(start, end)
            return True
        return self.book_helper(start, end, self.root)


if __name__ == "__main__":
    obj = MyCalendar()
    print(obj.book(10, 20))
    print(obj.book(15, 25))
    print(obj.book(20, 30))
