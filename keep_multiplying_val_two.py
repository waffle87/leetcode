# 2154. Keep Multiplying Found Values by Two

"""
you are given an array of integers 'nums'. you are also given an integer
'original' which is the first number that needs to be searched for in 'nums'.
you then do the following: if 'original' is found in 'nums', multiply it by
two, otherwise stop the process. repeat this process with the new number as
long as you keep finding the number. return the final value of 'original'
"""


class Solution(object):
    def findFinalValue(self, nums, original):
        """
        :type nums: List[int]
        :type original: int
        :rtype: int
        """
        bits = 0
        for i in nums:
            if i % original != 0:
                continue
            n = i // original
            if n & (n - 1) == 0:
                bits |= n
        ans = bits + 1
        return original * (ans & -ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findFinalValue(nums=[5, 3, 6, 1, 12], original=3))
    print(obj.findFinalValue(nums=[2, 7, 9], original=4))
