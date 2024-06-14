# 90. Subsets II

"""
given an integer array 'nums' that may contain duplicates, return all
possible subsets (the power set). the solution set must not contain duplicate
subsets. return the solution in any order.
"""


class Solution(object):
    def subsetWithDup(self, nums):
        n = len(nums)
        nums.sort()
        seen = set()
        for mask in range(1 << n):
            subset = []
            for i in range(n):
                bit = (mask >> i) & 1  # get i'th bit of mask
                if bit == 1:
                    subset.append(nums[i])
            seen.add(tuple(subset))
        return seen


if __name__ == "__main__":
    obj = Solution()
    print(obj.subsetWithDup([1, 2, 2]))
    print(obj.subsetWithDup([0]))
