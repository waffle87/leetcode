# 1717. Maximum Score From Removing Substrings
from collections import Counter

"""
given a sting 's' and two integers 'x' and 'y'. you can perform two types of
operations any number of times. remove substring "ab" and gain 'x' points.
remove substring "ba" and gain 'y' points. return the maximum points you can
gain after applying the above operations on 's'
"""


class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        a, b = "a", "b"
        if x < y:
            x, y = y, x
            a, b = b, a
        seen, ans = Counter(), 0
        for c in s + "x":
            if c in "ab":
                if c == b and 0 < seen[a]:
                    ans += x
                    seen[a] -= 1
                else:
                    seen[c] += 1
            else:
                ans += y * min(seen[a], seen[b])
                seen = Counter()
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumGain(s="cdbcbbaaabab", x=4, y=5))
    print(obj.maximumGain(s="aabbaaxybbaabb", x=5, y=4))
