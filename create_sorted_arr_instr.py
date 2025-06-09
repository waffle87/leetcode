# 1649. Create Sorted Array through Instructions

"""
given an integer array 'instructions', you are asked to create a sorted array
from the elements in 'instructions'. you start with an empty container
'nums'. for each element from left to right in 'instructions', insert it into
'nums'. the cost of each insertion is the minimum of the following: the
number of elements currently in 'nums' that are strictly less than
'instructions[i]', the number of elements currently in 'nums' that are
strictly greater than 'instructions[i]'. return the total cost to insert all
elements from 'instructions' into 'nums'. since the answer may be large,
return it modulo 10^9 + 7
"""


class Solution(object):
    def createSortedArray(self, instructions):
        """
        :type instructions: List[int]
        :rtype: int
        """
        m = max(instructions)
        arr = [0] * (m + 1)

        def update(x):
            while x <= m:
                arr[x] += 1
                x += x & -x

        def get(x):
            res = 0
            while x > 0:
                res += arr[x]
                x -= x & -x
            return res

        ans = 0
        for i, j in enumerate(instructions):
            ans += min(get(j - 1), i - get(j))
            update(j)
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.createSortedArray(instructions=[1, 5, 6, 2]))
    print(obj.createSortedArray(instructions=[1, 2, 3, 6, 5, 4]))
    print(obj.createSortedArray(instructions=[1, 3, 3, 3, 2, 4, 2, 1, 2]))
