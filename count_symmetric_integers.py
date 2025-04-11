# 2843. Count Symmetric Integers

"""
you are given two positive integers 'low' and 'high'. an integer 'x'
consisting of '2 * n' digits is symmetric if the sum of the first 'n' digits
of 'x' is equal to the sum of the last 'n' digits of 'x'. numbers with an odd
number of digits are never symmetric. return the number of symmetric integers
in the range '[low, high]'.
"""


class Solution(object):
    def countSymmetricIntegers(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        cnt = 0
        for i in range(low, high + 1):
            if i < 100 and i % 11 == 0:
                cnt += 1
            elif 1000 <= i < 10000:
                left = i // 1000 + (i % 1000) // 100
                right = (i % 100) // 10 + (i % 10)
                if left == right:
                    cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSymmetricIntegers(low=1, high=100))
    print(obj.countSymmetricIntegers(low=1200, high=1230))
