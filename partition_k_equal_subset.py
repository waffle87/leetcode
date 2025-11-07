# 698. Partition to K Equal Sum Subsets

"""
given an integer array 'nums' and an integer 'k', return 'true' if it is
possible to divide this array into 'k' non-empty subsets whose sums are all
equal.
"""


class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        total = sum(nums)
        if total % k:
            return False
        target = total // k
        nums.sort(reverse=True)
        if nums[0] > target:
            return False
        n, memo = len(nums), {}

        def dfs(used, curr):
            if used == (1 << n) - 1:
                return True
            if (used, curr) in memo:
                return memo[(used, curr)]
            for i in range(n):
                if not (used >> i) & 1 and curr + nums[i] <= target:
                    new = curr + nums[i]
                    next = 0 if new == target else new
                    if dfs(used | (1 << i), next):
                        memo[(used, curr)] = True
            memo[(used, curr)] = False
            return False

        return dfs(0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canPartitionKSubsets(nums=[4, 3, 2, 3, 5, 2, 1], k=4))
    print(obj.canPartitionKSubsets(nums=[1, 2, 3, 4], k=3))
