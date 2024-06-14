# 60. Permutation Sequence
import math

"""
the set '[1,2,3, ..., n]' contains a total of 'n!' unique permutations. by
listing and labeling all of the permutations in order, we get the following
sequence for 'n = 3' 123, 132, 213, 231, 312, 321 given 'n' and 'k', return
the k'th permutation sequence
"""


class Solution(object):
    def getPermutation(self, n, k):
        nums = range(1, n + 1)
        permutation = ""
        k -= 1
        while n > 0:
            n -= 1
            idx, k = divmod(k, math.factorial(n))
            permutation += str(nums[idx])
            nums.remove(nums[idx])
        return permutation


if __name__ == "__main__":
    obj = Solution()
    print(obj.getPermutation(3, 3))  # expect: 213
    print(obj.getPermutation(4, 9))  # expect: 2314
    print(obj.getPermutation(3, 1))  # expect: 123
