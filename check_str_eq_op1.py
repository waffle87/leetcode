# 2839. Check if Strings Can be Made Equal With Operations I

"""
you are given two strings 's1' and 's2' both of length 4, consisting of
lowercase english letters. you can apply the following operation on any of
the two strings any number of times: choose any two indices 'i' and 'j' such
that 'j - i = 2' then swap the two characters at those indices in the string.
return true if you make the strings 's1' and 's2' equal and false otherwise.
"""


class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return {s1[0], s1[2]} == {s2[0], s2[2]} and {s1[1], s1[3]} == {s2[1], s2[3]}


if __name__ == "__main__":
    obj = Solution()
    print(obj.canBeEqual(s1="abcd", s2="cdab"))
    print(obj.canBeEqual(s1="abcd", s2="dacb"))
