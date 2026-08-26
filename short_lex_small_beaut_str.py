# 2904. Shortest and Lexicographically Smallest Beautiful String

"""
you are given a binary string 's' and a positive integer 'k'. a substring of
's' is beautiful if the number of 1's in it is exactly 'k'. let 'len' be the
length of the shortest beautiful substring. return the lexicographically
smallest beautiful substring of 's' with length equal to 'len'. if 's'
doesn't contain a beautiful substring, return an empty string.
"""


class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ones = [i for i, j in enumerate(s) if j == "1"]
        if len(ones) < k:
            return ""
        candid = list(zip(ones, ones[k - 1 :]))
        m = min(r - l for l, r in candid)
        candid = list(filter(lambda x: x[1] - x[0] == m, candid))
        return min([s[l : r + 1] for l, r in candid])


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestBeautifulSubstring(s="100011001", k=3))
    print(obj.shortestBeautifulSubstring(s="1011", k=2))
    print(obj.shortestBeautifulSubstring(s="000", k=1))
