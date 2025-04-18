# 38. Count and Say
from re import findall

"""
the count-and-say sequence is a sequence of digit strings defined by the
recursive formula:
- countAndSay(1) = "1"
- countAndSay(n) is the way you would "say" the digit string from
'countAndSay(n - 1)', which is then converted into a different digit string
to determine how you "say" a digit string, split it into minimal number of
substrings such that each substring contains exactly one unique digit. then
for each substring, say the number of digits, then say the digit, finally,
concatenate every said digit. given a positive integer 'n', return the n'th
term of the count and say sequence.
"""


class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        ans = "1"
        for _ in range(n - 1):
            ans = "".join(
                str(len(group)) + digit for group, digit in findall(r"((.)\2*)", ans)
            )
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countAndSay(n=4))
    print(obj.countAndSay(n=1))
