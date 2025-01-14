# 2657. Find the Prefix Common Array of Two Arrays

"""
you are given two 0-indexed integer permutations 'a' and 'b' of length 'n'. a
prefix common array of 'a' and 'b' is an array 'c' such that 'c[i]' is equal
to the count of numbers that are present at or before the index 'i' in both
'a' and 'b'. return the prefix common array of 'a' and 'b'. a sequence of 'n'
integers is called a permutation if it contains all integers from 1 to 'n'
exactly once.
"""


class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        ans, vis, cnt = [], 0, 0
        for ab in zip(A, B):
            for a in ab:
                if (1 << a) & vis:
                    cnt += 1
                vis |= 1 << a
            ans.append(cnt)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findThePrefixCommonArray(A=[1, 3, 2, 4], B=[3, 1, 2, 4]))
    print(obj.findThePrefixCommonArray(A=[2, 3, 1], B=[3, 1, 2]))
