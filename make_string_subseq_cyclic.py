# 2825. Make String a Subsequence Using Cyclic Increments

"""
you are given two 0-indexed strings 'str1' and 'str2'. in an operation, you
select a set of indices in 'str1' and for each index 'i' in the set,
increment 'str1[i]' to be the next character cyclically. that is, 'a' becomes
'b', 'b' becomes 'c', and so on. return true if it is possible to make 'str2'
a subsequence of 'str1' by performing the operation at most once, and false
otherwise. note, a subsequence is a new string that is formed from the
original string by deleting some (possible none) of the characters without
disturbing the relative positions of the remaining characters
"""


class Solution(object):
    def canMakeSubsequence(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: bool
        """
        j, n, m = 0, len(str1), len(str2)
        for i in range(n):
            if j < m and (ord(str2[j]) - ord(str1[i])) % 26 <= 1:
                j += 1
        return j == m


if __name__ == "__main__":
    obj = Solution()
    print(obj.canMakeSubsequence(str1="abc", str2="ad"))
    print(obj.canMakeSubsequence(str1="zc", str2="ad"))
    print(obj.canMakeSubsequence(str1="ab", str2="d"))
