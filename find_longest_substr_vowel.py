# 1371. Find the Longest Substring Containing Vowels in Even Counts

"""
given the string 's', return the size of the longest substring containing
each value an even number of times. that is 'a, e, i, o, u' must appear an
even number of times.
"""


class Solution(object):
    def findTheLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen = {0: -1}
        ans, curr = 0, 0
        for i, j in enumerate(s):
            curr ^= 1 << ("aeiou".find(j) + 1) >> 1
            seen.setdefault(curr, i)
            ans = max(ans, i - seen[curr])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findTheLongestSubstring("eleetminicoworoep"))
    print(obj.findTheLongestSubstring("leetcodeisgreat"))
    print(obj.findTheLongestSubstring("bcbcbc"))
