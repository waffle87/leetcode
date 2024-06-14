# 453. Minimum Moves to Equal Array Elements

"""
given an integer array 'nums' of size 'n', return the minimum number of moves
required to make all array elements equal. in one move you can increment 'n -
1' elements of the array by 1
"""


class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums) - len(nums) * min(nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMoves([1, 2, 3]))
    print(obj.minMoves([1, 1, 1]))
