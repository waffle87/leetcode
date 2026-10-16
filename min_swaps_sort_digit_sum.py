# 3551. Minimum Swaps to Sort by Digit Sum

"""
you are given an array 'nums' of distinct positive integers. you need to sort
the array in increasing order based on the sum of the digits of each number.
if two numbers have the same digit sum, the smaller number appears first in
the sorted order. return the minimum number of swaps required to rearrange
'nums' into this sorted order. a swap is defined as exchanging the values at
two distinct positions in the array.
"""


class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        digit_sum = lambda x: sum(map(int, str(x)))
        rank = {
            x: k for k, x in enumerate(sorted(nums, key=lambda x: (digit_sum(x), x)))
        }
        home = [rank[x] for x in nums]
        swaps = 0
        for i in range(len(home)):
            while home[i] != i:
                j = home[i]
                home[i], home[j] = home[j], home[i]
                swaps += 1
        return swaps


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSwaps(nums=[37, 100]))
    print(obj.minSwaps(nums=[22, 14, 33, 7]))
    print(obj.minSwaps(nums=[18, 43, 34, 16]))
