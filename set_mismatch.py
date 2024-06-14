# 645. Set Mismatch

"""
you have a set of integers 's' which originally contains all the numbers from
1 to 'n'. unfortunately, due to some error, one of the numbers in 's' was
duplicated to another number in the sett, which results in reptition of one
number and loss of another number. given an integer array 'nums' representing
the data state of this set after the error. find the number that occurs twice
and the number that is missing and return them in the form of an array
"""


class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]

        given that we have numbers from 1 to 'n' and some number 'x' is here
        twice and another number 'y' is missing. let us calculate the sum of all
        numbers and sum of squares of all numbers and given this information we can
        get our answer using pure math. facts:
         1. 1 + 2 + ... + n = n * (n + 1) // 2
         2. 1^2 + 2^2 + ... + n^2 = n * (n + 1) * (2 * n + 1) // 6
        now let us consider number 'a = -sum(nums) + n * (n + 1) // 2'. it is
        equal to 'y - x', because each element not equal to 'x' and 'y' will be
        canceled out. in similar way if we define 'b = -sum(i * i for i in nums) + n
        * (n + 1) * (2 * n + 1) // 6', it will be equal to 'y * y - x * x'. so, we
        have system of equations: 'a = y - x' and 'b = y * y - x * x'
        """
        n = len(nums)
        a = -sum(nums) + n * (n + 1) // 2
        b = -sum(i * i for i in nums) + n * (n + 1) * (2 * n + 1) // 6
        return [(b - a * a) // 2 // a, (b + a * a) // 2 // a]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findErrorNums([1, 2, 2, 4]))
    print(obj.findErrorNums([1, 1]))
