# 3942. Minimum Operations to Sort a Permutation

"""
you are given an integer array 'nums' of length 'n' where 'nums' is a
permutation of the integers from 0 to 'n - 1'. you may perform only the
following operations: reverse the entire array, rotate left by one: move the
first element to the end of the array, and rest elements to the left by one
position. return an integer denoting the minimum number of operations
required to sort the array in increasing order. if it is not possible to sort
the array using only the given operations return -1.
"""


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n, k = len(nums), nums[0]
        ans = float("inf")
        forward, reverse = True, True
        for i in range(n):
            if nums[i] != (k + i) % n:
                forward = False
            if nums[i] != ((k - i) % n + n) % n:
                reverse = False
        if forward:
            ans = min((n - k) % n, k + 2)
        if reverse:
            ans = min(ans, min(1 + (k + 1) % n, 1 + (n - k - 1) % n))
        return -1 if ans == float("inf") else ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[0, 2, 1]))
    print(obj.minOperations(nums=[1, 0, 2]))
    print(obj.minOperations(nums=[2, 0, 1, 3]))
