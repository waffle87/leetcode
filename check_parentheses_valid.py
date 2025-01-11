# 2116. Check if a Parentheses String Can Be Valid

"""
a parentheses string is a non-empty string consisting only of '(' and ')'. it
is valid if any of the following conditions is true: it is '()', it can be
written as 'AB' where 'A' and 'B' are valid parentheses, it can be written as
'(A)' where 'A' is a valid parentheses string. you are given a parentheses
string 's' and a string 'locked', both of length 'n'. 'locked' is a binary
string consistion only of '0's and '1's. for each indiex 'i' of 'locked'.
"""


class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """
        if len(s) % 2 == 1:
            return False
        total = open = closed = 0
        for i in range(len(s) - 1, -1, -1):
            if locked[i] == "0":
                total += 1
            elif s[i] == "(":
                open += 1
            elif s[i] == ")":
                closed += 1
            if total - open + closed < 0:
                return False
        total = open = closed = 0
        for i in range(len(s)):
            if locked[i] == "0":
                total += 1
            elif s[i] == "(":
                open += 1
            elif s[i] == ")":
                closed += 1
            if total + open - closed < 0:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.canBeValid(s="))()))", locked="010100"))
    print(obj.canBeValid(s="()()", locked="0000"))
    print(obj.canBeValid(s=")", locked="0"))
