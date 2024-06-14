# 1016. Binary String With Substrings Representing 1 To N

"""
given a binary string 's' and a positive integer 'n', return 'true' if the
binary representation of all the integers in the range '[1, n]' are
substrings of 's' or 'false' otherwise. a substring is a contiguous sequence
of characters within a string.
"""


class Solution(object):
    def queryString(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: bool
        """
        if n > len(s) * 2:
            return False
        l = len(bin(n)) - 2
        seen = {s[i : i + l] for i in range(len(s))} | {
            s[i : i + l - 1] for i in range(len(s))
        }
        return all(bin(i)[2:] in seen for i in range(n, n / 2, -1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.queryString("0110", 3))  # expect: true
    print(obj.queryString("0110", 4))  # expect: false
