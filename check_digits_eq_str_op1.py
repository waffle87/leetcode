# 3461. Check If Digits Are Equal in String After Operations I

"""
you are given a string 's' consisting of digits. perform the following
operation repeatedly until the string has exactly two digits: for each pair
of consecutive digits in 's', starting from the first digit, calculate a new
digit as the sum of the two digits modulo 10. replace 's' with the sequence
of newly calcluated digits, maintaining their order in which they were
computed. return true if the final two digits in 's' are the same; otherwise
return false.
"""


class Solution(object):
    def hasSameDigits(self, s):
        """
        :type s: str
        :rtype: bool
        """
        while len(s) != 2:
            tmp = ""
            for i in range(1, len(s)):
                j = ((ord(s[i]) - ord("a")) + (ord(s[i - 1]) - ord("a"))) % 10
                tmp += chr(j + ord("a"))
            s = tmp
        return s[0] == s[1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasSameDigits(s="3902"))
    print(obj.hasSameDigits(s="34789"))
