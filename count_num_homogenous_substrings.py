# 1759. Count Number of Homogenous Substrings

"""
given a string 's', return the number of homogenous substrings of 's'. since
thhe answer may be very large, return it modulo 10^9+7. a string is
homogenous if all the characters of the string are the same. a substring is a
continuous sequence of chharacters within a string.
"""


class Solution(object):
    def countHomogenous(self, s):
        ans = 0
        for c, s in groupby(s):
            n = len(list(s))
            ans += n * (n + 1) / 2
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countHomogenous("abbcccaa"))  # expect: 13
    print(obj.countHomogenous("xy"))  # expect: 2
    print(obj.countHomogenous("zzzzz"))  # expect: 15
