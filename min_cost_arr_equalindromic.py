# 2967. Minimum Cost to Make Array Equalindromic

"""
you are given a 0-indexed integer array 'nums' having length 'n'. you are
allowed to perform a special move any number of times on 'nums'. in one
special move, you perform the following steps in order: choose an index 'i'
in the range '[0, n - 1]' and a positive integer 'x', add '|nums[i] - x|' to
the total cost, and change the value of 'nums[i]' to 'x'. a palindromic
number is a positive integer that remains the same when its digits are
reversed. an array is considered equalindromic if all the elements in the
array are equal to an integer 'y', where 'y' is a palindromic number less
than 10^9. return an integer denoting the minimum possible total cost to make
'nums' equalindromic by performing any number of special moves
"""


class Solution(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        palindrome = lambda x: str(x) == str(x)[::-1]
        left = right = nums[len(nums) // 2]
        while not palindrome(left):
            left -= 1
        while not palindrome(right):
            right += 1
        return min(
            sum(map(lambda x: abs(x - left), nums)),
            sum(map(lambda x: abs(x - right), nums)),
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumCost(nums=[1, 2, 3, 4, 5]))
    print(obj.minimumCost(nums=[10, 12, 13, 14, 15]))
    print(obj.minimumCost(nums=[22, 33, 22, 33, 22]))
