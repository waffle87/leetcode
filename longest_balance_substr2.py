# 3714. Longest Balanced Substring II

"""
you are given a string 's' consisting only of the characters a, b, and c. a
substring of 's' is called balanced if all distinct characters in the
substring appear the same number of times. return the length of the longest
balance substring of 's'.
"""


class Solution(object):
    def longestBalanced(self, s):
        """
        :type s: str
        :rtype: int
        """
        p = [[0, 0, 0]]
        for i in s:
            p.append(p[-1][:])
            p[-1]["abc".index(i)] += 1
        ans, first = 0, {}
        for i, (a, b, c) in enumerate(p):
            for key in [
                ("abc", a - b, a - c),
                ("ab", a - b, c),
                ("bc", b - c, a),
                ("ca", c - a, b),
                ("a", b, c),
                ("b", c, a),
                ("c", a, b),
            ]:
                ans = max(ans, i - first.get(key, i))
                first.setdefault(key, i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestBalanced(s="abbac"))
    print(obj.longestBalanced(s="aabcc"))
    print(obj.longestBalanced(s="aba"))
