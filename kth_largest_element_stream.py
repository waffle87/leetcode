# 703. Kth Largest Element in a Stream
import heapq

"""
design a class to find the k'th largest element in a stream. note that it is
the k'th largest element in the sorted order, not the k'th distinct element.
implement 'KthLargest' class:
- KthLargest(int k, int[] nums) initialises the objct with the integer 'k'
and the stream of integers 'nums' int add(int val) appends the integer 'val'
to the stream and returns the element representing the k'th largest stream
element
"""


class KthLargest(object):
    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.pool = nums
        self.k = k
        heapq.heapify(self.pool)
        while len(self.pool) > k:
            heapq.heappop(self.pool)

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        if len(self.pool) < self.k:
            heapq.heappush(self.pool, val)
        elif val > self.pool[0]:
            heapq.heapreplace(self.pool, val)
        return self.pool[0]


if __name__ == "__main__":
    nums = [4, 5, 8, 2]
    obj = KthLargest(3, nums)
    print(obj.add(3))
    print(obj.add(5))
    print(obj.add(10))
    print(obj.add(9))
    print(obj.add(4))
