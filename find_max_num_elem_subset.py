# 3020. Find the Maximum Number of Elements in Subset

"""
you are given an array of positive integers 'nums'. you need to select a
subset of 'nums' which satisfies the following condition: you can place the
selected elements in a 0-indexed array such that it follows the pattern '[x,
x2, x4, ..., k k/2]'. return the maximum nnumber of elements in a subset that
satisfies these conditions.
"""

from collections import Counter


class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt, ans = Counter(nums), 0
        for key in cnt.keys():
            if key == 1:
                total = cnt[key] if cnt[key] % 2 else cnt[key] - 1
            else:
                total = 0
                while cnt[key] >= 2 and key * key in cnt:
                    total += 2
                    key = key * key
                total += 1
            ans = max(ans, total)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumLength(nums=[5, 4, 1, 2, 2]))
    print(obj.maximumLength(nums=[1, 3, 2, 4]))
