# 2657. Find the Prefix Common Array of Two Arrays

"""
you are given two 0-indexed integer permutations 'a' and 'b' of length 'n'. a
prefix common array of 'a' and 'b' is an array 'c' such that 'c[i]' is equal
to the count of numbers that are present at or before the index 'i' in both
'a' and 'b'. return the prefix common array of 'a' and 'b'. a sequence of 'n'
integers is called a permutation if it contains all integers from 1 to 'n'
exactly once.
"""


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans = [0] * n
        a, b = 0, 0
        for i in range(n):
            a |= 1 << A[i]
            b |= 1 << B[i]
            ab = a & b
            ans[i] = ab.bit_count()
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findThePrefixCommonArray(A=[1, 3, 2, 4], B=[3, 1, 2, 4]))
    print(obj.findThePrefixCommonArray(A=[2, 3, 1], B=[3, 1, 2]))
