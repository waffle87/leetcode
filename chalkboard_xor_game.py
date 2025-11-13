# 810. Chalkboard XOR Game

"""
you are given an array of integers 'nums' that represents the numbers written
on a chalboard. alice and bob take turns erasing exactly one number from the
chalboard, with alice starting first. if erasing a number causes the bitwise
xor of all the elements of the chalboard to become 0, then the player loses.
the bitwise xor of one element is that element itself, and the bitwise xor of
no elements is 0. also, if any player starts their turn with the bitwise xor
of all the elements of the Chalkboard equal to 0 then that player wins.
return true if and only if alice wins the game, assuming both players play
optimally.
"""


class Solution(object):
    def xorGame(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        x = 0
        for i in nums:
            x ^= i
        return x == 0 or len(nums) % 2 == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.xorGame(nums=[1, 1, 2]))
    print(obj.xorGame(nums=[0, 1]))
    print(obj.xorGame(nums=[1, 2, 3]))
