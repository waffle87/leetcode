# 696. Count Binary Substrings

"""
given a binary string 's', return the number of non-empty substrings that
have the same number of 0's and 1's, and all the 0's and all the 1's in these
substrings are group consecutively. substrings that occur multiple times are
counted the number of times they occur.
"""


class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        curr, prev, ans = 1, 0, 0
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                curr += 1
            else:
                ans += min(curr, prev)
                prev, curr = curr, 1
        return ans + min(curr, prev)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countBinarySubstrings(s="00110011"))
    print(obj.countBinarySubstrings(s="10101"))
