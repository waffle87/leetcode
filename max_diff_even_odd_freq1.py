# 3442. Maximum Difference Between Even and Odd Frequency I

"""
you are given a string 's' consisting of lowercase english letters. your task
is to find the minimum difference 'diff = a1 - a2' between the frequency of
characters 'a1' and 'a2' in the string such that 'a1' has an odd frequency in
the string, and 'a2' has an even frequency in the string. return this maximum
difference.
"""


class Solution(object):
    def maxDifference(self, s):
        """
        :type s: str
        :rtype: int
        """
        freq = [0] * 26
        for i in s:
            freq[ord(i) - ord("a")] += 1
        maxi, mini = 0, len(s)
        for i in range(26):
            if freq[i] % 2 != 0:
                maxi = max(maxi, freq[i])
            if freq[i] % 2 == 0 and freq[i] > 0:
                mini = min(mini, freq[i])
        return maxi - mini


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDifference(s="aaaaabbc"))
    print(obj.maxDifference(s="abcabcab"))
