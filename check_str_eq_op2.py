# 2840. Check if Strings Can be Made Equal With Operations II
from collections import Counter

"""
you are given two strings 's1' and 's2' both of length 'n' consisting of
lowercase english letters. you can apply the following operation on any of
the two strings any number of times. choose any two indices 'i' and 'j' such
that 'i < j' and the difference 'j - i' is even, then swap the two characters
at those indices in the string. return true if you can make the strings 's1'
and 's2' equal, otherwise return false.
"""


class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return Counter(s1[::2]) == Counter(s2[::2]) and Counter(s1[1::2]) == Counter(
            s2[1::2]
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkStrings(s1="abcdba", s2="cabdab"))
    print(obj.checkStrings(s1="abe", s2="bea"))
