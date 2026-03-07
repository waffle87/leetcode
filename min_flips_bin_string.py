# 1888. Minimum Number of Flips to Make the Binary String Alternating

"""
you are given a binary string 's'. you are allowed to perform two types of
operations on the string in any sequence: 1: remove the character at the
start of the string 's' and append it to the end of the string. 2: pick any
characters in 's' and flip its value, ie. if its value is 0 it becomes 1 and
vice versa. return the minimum number of type-2 operations needed to perform
such that 's' becomes alternating. the string is called alternating if no two
adjacent characters are equal. for example, the strings "010" and "1010" are
alternating, while the string "0110" is not.
"""


class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        e, o = (n + 1) // 2, n // 2
        x = s[::2].count("1") - s[1::2].count("1")
        m = min(e - x, o + x)
        if n & 1:
            for c in s:
                x = 2 * (ord(c) & 1) - x
                m = min(m, e - x, o + x)
        return m


if __name__ == "__main__":
    obj = Solution()
    print(obj.minFlips("111000"))  # expect: 2
    print(obj.minFlips("010"))  # expect: 0
    print(obj.minFlips("1110"))  # expect: 1
