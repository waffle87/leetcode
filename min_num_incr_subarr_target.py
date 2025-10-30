# 1526. Minimum Number of Increments on Subarrays to Form a Target Array

"""
you are given an integer array 'target'. you have an integer array 'initial'
of the same size as 'target' with all elements initially zeros. in one
operation, you can choose any subarray from 'initial' and increment ach value
by one. return the minimum number of operations to form a 'target' array from
'initial'. the test cases are generated such that the answer will fit in a
32-bit integer.
"""


class Solution(object):
    def minNumberOperations(self, target):
        """
        :type target: List[int]
        :rtype: int
        """
        ans, prev = 0, 0
        for i in target:
            if i > prev:
                ans += i - prev
            prev = i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minNumberOperations(target=[1, 2, 3, 2, 1]))
    print(obj.minNumberOperations(target=[3, 1, 1, 2]))
    print(obj.minNumberOperations(target=[3, 1, 5, 4, 2]))
