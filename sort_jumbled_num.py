# 2191. Sort the Jumbled Numbers

"""
you are given a 0-indexed integer array 'mapping' which represents the
mapping rule of a shuffled decimal system. 'mapping[i] = j' means the digit
'i' should be mapped to digit 'j' in this system. the mapped value of an
integer is the new integer obtained by replacing each occurence of digit 'i'
in the integer with 'mapping[i]' for all '0 <= i <= 9'. you are also given
another integer array 'nums'. return the array 'nums' sorted in non
decreasing order based on the mapped values of its elements.
"""


class Solution(object):
    def sortJumbled(self, mapping, nums):
        """
        :type mapping: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """

        def convert(num):
            if num == 0:
                return mapping[0]
            n, f = 0, 1
            while num > 0:
                num, r = divmod(num, 10)
                n += mapping[r] * f
                f *= 10
            return n

        indices = sorted(range(len(nums)), key=lambda i: convert(nums[i]))
        return [nums[i] for i in indices]


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortJumbled(mapping=[8, 9, 4, 0, 2, 1, 3, 5, 7, 6], nums=[991, 338, 38]))
    print(obj.sortJumbled(mapping=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9], nums=[789, 456, 123]))
