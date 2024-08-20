# 2080. Range Frequency Queries
from collections import defaultdict
from bisect import bisect

"""
design a data structure to find the frequency of a given value in a given
subarray. the frequency of a value in a subarray is the number of occurences
of that value in the subarray. implement the 'RangeFreqQuery' class:
'rangeFreqQueryCreate(int[] arr)' constructs an instance of the class with
the given 0-indexed integer array 'arr'. 'int RangeFreqQuery(int left, int
right, int val)' returns the frequency of 'val' in the subarray 'arr[left ...
right]'. a subarray is contiguous sequence of elements within an array.
'arr[left ... right]' denotes the subarray that contains the elements of
'nums' between indices 'left' and 'right' inclusively
"""


class RangeFreqQuery(object):
    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.cnt = defaultdict(list)
        for i, j in enumerate(arr):
            self.cnt[j].append(i)

    def query(self, left, right, value):
        """
        :type left: int
        :type right: int
        :type value: int
        :rtype: int
        """
        i = bisect(self.cnt[value], left - 1)
        j = bisect(self.cnt[value], right)
        return j - i


if __name__ == "__main__":
    obj = RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56])
    print(obj.query(1, 2, 4))
    print(obj.query(0, 11, 33))
