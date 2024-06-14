# 2659. Make Array Empty

"""
given an integer array 'nums' containing distinct numbers and you can perform
the following operations until the array is emtpy. if the first element has
the smallest value, remove it. otherwise, put the first element at the end of
the array. return an integer denoting the number of operations it takes to
make 'nums' empty.
"""


class Solution(object):
    def countOperationsToEmptyArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pos = {n: i for i, n in enumerate(nums)}
        ans = n = len(nums)
        nums.sort()
        for i in range(1, n):
            if pos[nums[i]] < pos[nums[i - 1]]:
                ans += n - i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countOperationsToEmptyArray([3, 4, -1]))
    print(obj.countOperationsToEmptyArray([1, 2, 4, 3]))
    print(obj.countOperationsToEmptyArray([1, 2, 3]))
