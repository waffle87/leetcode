# 796. Rotate String

"""
given two strings 's' and 'goal', return 'true' if and only if 's' can become
'goal' after some number of shifts on 's'. a shift on 's' consists of moving
the leftmost character of 's' to the rightmost position. for example, if 's =
"abcde"', then it will be "bcdea" after one shift.
"""


class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        return len(s) == len(goal) and goal in s + s


if __name__ == "__main__":
    obj = Solution()
    print(obj.rotateString(s="abcde", goal="cdeab"))
    print(obj.rotateString(s="abcde", goal="abced"))
