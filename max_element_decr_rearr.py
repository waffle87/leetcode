# 1846. Maximum Element After Decreasing and Rearranging

"""
given an array of positive integers 'arr', perform some operations on 'arr'
so that it satisfies these conditions:
- the value of the first element in 'arr' must be 1
- the absolute difference between any two adjacent elements must be less than
or equal to 1. in other words 'abs(arr[i] - arr[i - 1]) <= 1' for each i
where 1 <= i < arr.length (0-indexed). 'abs(x)' is the absolute value of 'x'
there are two types operations that you can perform any number of times:
decrease the value of any element of 'arr' to a smaller positive integer
rearrange the elements of 'arr' to be in any order
return the maximum possible value of an element in 'arr' after performing the
operations to satisfy the conditions.
"""


class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        arr.sort()
        ans = 0
        for i in arr:
            ans = min(ans + 1, i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumElementAfterDecrementingAndRearranging(arr=[2, 2, 1, 2, 1]))
    print(obj.maximumElementAfterDecrementingAndRearranging(arr=[100, 1, 1000]))
    print(obj.maximumElementAfterDecrementingAndRearranging(arr=[1, 2, 3, 4, 5]))
