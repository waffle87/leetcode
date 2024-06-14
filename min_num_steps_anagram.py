# 1347. Minimum Number of Steps to Make Two Strings Anagram

"""
given two trings of the same length 's' and 't'. in one step you can choose
any character of 't' and replace itwith another characters. return the
minimum numberof steps to make 't' an anagram of 's'. an anagram of a string
is a string that contains the same characters witha different ordering.
"""


class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        cnt_s = [0] * 26
        cnt_t = [0] * 26
        for char in s:
            cnt_s[ord(char) - ord("a")] += 1
        for char in t:
            cnt_t[ord(char) - ord("a")] += 1
        steps = 0
        for i in range(26):
            steps += abs(cnt_s[i] - cnt_t[i])
        return steps // 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSteps(s="bab", t="aba"))
    print(obj.minSteps(s="leetcode", t="practice"))
    print(obj.minSteps(s="anagram", t="mangaar"))
