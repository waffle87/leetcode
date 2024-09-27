# 731. My Calendar II
import bisect

"""
you are implementing a program to use as your calendar. we can add a new
event if adding the event will not cause a triple booking. a triple booking
happens when three events have the same non empty intersection (ie. some
moment is common to all the three event). the event can be represented as a
pair of integers 'start' and 'end' that represents a booking on the half open
interval '[start, end]', the range of real numbers 'x' such that 'start <= x
< end'.
"""


class MyCalendarTwo(object):
    def __init__(self):
        self.list = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        bisect.insort(self.list, (start, 1))
        bisect.insort(self.list, (end, -1))
        booked = 0
        for time, n in self.list:
            booked += n
            if booked == 3:
                self.list.pop(bisect.bisect_left(self.list, (start, 1)))
                self.list.pop(bisect.bisect_left(self.list, (end, -1)))
                return False
        return True


if __name__ == "__main__":
    obj = MyCalendarTwo()
    print(obj.book(10, 20))
    print(obj.book(50, 60))
    print(obj.book(10, 40))
    print(obj.book(5, 15))
    print(obj.book(5, 10))
    print(obj.book(25, 55))
