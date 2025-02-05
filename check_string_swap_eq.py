# 1790. Check if One String Swap Can Make Strings Equal

"""
you are given two strings 's1' and 's2' of equal length. a string swap is an
operation where you choose two indices in a string (not necessarily
different) and swap the characters at these indices. return 'true' if it is
possible to make both strings equal by performing at most one string swap on
exactly one of the strings. otherwise, return 'false'.
"""


class Solution(object):
    def areAlmostEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        diff = [[x, y] for x, y in zip(s1, s2) if x != y]
        return not diff or len(diff) == 2 and diff[0][::-1] == diff[1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.areAlmostEqual(s1="bank", s2="kanb"))
    print(obj.areAlmostEqual(s1="attack", s2="defend"))
    print(obj.areAlmostEqual(s1="kelb", s2="kelb"))
