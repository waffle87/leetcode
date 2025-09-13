# 3541. Find Most Frequent Vowel and Consonant

"""
you are given a string 's' consisting of lowercase english letters 'a' to
'z'. your task is to find the vowel with the maximum frequency, and find the
consonant with the maximum frequency. return the sum of the two frequencies.
note if multiple vowels or consonants have the same maximum frequency, you
may choose any one of them. if there are no vowels or consonants in the
string, consider their frequency as 0.
"""


class Solution(object):
    def maxFreqSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        freq = [0] * 26
        max_v, max_c = 0, 0
        for c in s:
            i = ord(c) - ord("a")
            freq[i] += 1
            if c in "aeiou":
                max_v = max(max_v, freq[i])
            else:
                max_c = max(max_c, freq[i])
        return max_v + max_c


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFreqSum(s="successes"))
    print(obj.maxFreqSum(s="aeiaeia"))
