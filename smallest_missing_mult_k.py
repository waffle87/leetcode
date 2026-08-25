# 3718. Smallest Missing Multiple of K

"""
given an integer array 'nums' and an integer 'k', return the smallest
positive muliple of  lk that is missing from 'nums'. a multiple of 'k' is any
positive integer divisible by 'k'.
"""


class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        vis, m = set(nums), k
        while m in vis:
            m += k
        return m


if __name__ == "__main__":
    obj = Solution()
    print(obj.missingMultiple(nums=[8, 2, 3, 4, 6], k=2))
    print(obj.missingMultiple(nums=[1, 4, 7, 10, 15], k=5))
