# 2275. Largest Combination With Bitwise AND Greater Than Zero

"""
the bitwise and of an array 'nums' is the bitwise nd of all integers in
'nums'. you are given an array of positive integers 'candidates'. evaluate
the bitwise and of every combination of numbers of 'candidates'. each number
in 'candidates' may only be used once in each combination. return the size of
the largest combination of 'candidates' with a bitwise and greater than zero.
"""


class Solution(object):
    def largestCombination(self, candidates):
        """
        :type candidates: List[int]
        :rtype: int
        """
        return max(sum(1 << i & j > 0 for j in candidates) for i in range(30))


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestCombination(candidates=[16, 17, 71, 62, 12, 24, 14]))
    print(obj.largestCombination(candidates=[8, 8]))
