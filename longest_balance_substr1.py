# 3713. Longest Balanced Substring I

"""
you are given a string 's' consisting of lowercase english letters. a
substring of 's' is called balanced if all distinct characters in the
substring appear the same number of times. return the length of the longest
balanced substring of 's'.
"""


class Solution(object):
    def longestBalanced(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, ans = len(s), 0
        s = [ord(char) - ord("a") for char in s]
        for i in range(n):
            if n - i <= ans:
                break
            freq = [0] * 26
            unique = max_freq = 0
            for j in range(i, n):
                idx = s[j]
                unique += freq[idx] == 0
                freq[idx] += 1
                if freq[idx] > max_freq:
                    max_freq = freq[idx]
                curr = j - i + 1
                if unique * max_freq == curr and curr > ans:
                    ans = curr
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestBalanced(s="abbac"))
    print(obj.longestBalanced(s="zzabccy"))
    print(obj.longestBalanced(s="aba"))
