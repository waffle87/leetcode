# 3333. Find the Original Typed String II
from functools import reduce
from itertools import accumulate

"""
alice is attempting to type a specific string on her computer. however, she
tends to be clumsy and may press a key for too long, resulting in a character
being typed multiple times. you are given a string 'word', which represents
the final output displayed on alice's screen. you are also given a positive
integer 'k'. return the total number of possible original strings that alice
might have intended to type, if she was trying to type a string of size at
least 'k'. since the answer may be very large, return it modul 10^9+7.
"""


class Solution(object):
    def possibleStringCount(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        mod_mul = lambda a, b: (a * b) % (10**9 + 7)
        mod_add = lambda a, b: (a + b) % (10**9 + 7)
        mod_sub = lambda a, b: (a - b) % (10**9 + 7)
        segment = [1]
        for i in range(1, len(word)):
            if word[i] != word[i - 1]:
                segment.append(1)
            else:
                segment[-1] += 1
        total = reduce(mod_mul, segment)
        if k <= len(segment):
            return total

        dp = [1] + ([0] * (k - 1))
        for i in range(1, len(segment) + 1):
            prefix = list(accumulate(dp, mod_add, initial=0))
            dp = [0] * k
            for j in range(i, k):
                dp[j] = mod_sub(prefix[j], prefix[j - min(segment[i - 1], j - i + 1)])
        less_than_k = reduce(mod_add, dp)
        return mod_sub(total, less_than_k)


if __name__ == "__main__":
    obj = Solution()
    print(obj.possibleStringCount(word="aabbccdd", k=7))
    print(obj.possibleStringCount(word="aabbccdd", k=8))
    print(obj.possibleStringCount(word="aaabbb", k=3))
