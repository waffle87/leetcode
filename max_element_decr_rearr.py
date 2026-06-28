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


class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n, ans = len(arr), 1
        cnts = [0] * (n + 1)
        for i in arr:
            cnts[min(i, n)] += 1
        for i in range(2, n + 1):
            ans = min(ans + cnts[i], i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumElementAfterDecrementingAndRearranging(arr=[2, 2, 1, 2, 1]))
    print(obj.maximumElementAfterDecrementingAndRearranging(arr=[100, 1, 1000]))
    print(obj.maximumElementAfterDecrementingAndRearranging(arr=[1, 2, 3, 4, 5]))
