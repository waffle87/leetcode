# 66. Plus One

"""
you are given a large integer represented as an integer array 'digits', where
each 'digits[i]' is the i'th digit of thee integer. the digits are ordered
from most significant to least signifcant in left to right order. the large
does not contain any leading zeros. increment the large integer by one and
return the resulting  array of digits.
"""


class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        return [1] + digits


if __name__ == "__main__":
    obj = Solution()
    print(obj.plusOne(digits=[1, 2, 3]))
    print(obj.plusOne(digits=[4, 3, 2, 1]))
    print(obj.plusOne(digits=[9]))
