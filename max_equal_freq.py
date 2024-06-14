# 1224. Maximum Equal Frequency
from collections import defaultdict

"""
given an array 'nums' of positive integers, return the longest possible
length of an array prefix of 'nums' such that it is possible to remove
exactly one element from this prefix so that ever number has appear in it
will have the same number occurrences. if after removing one element there
are no remaining elements, it's still considered that every appear number has
the same number of occurrences.
"""


class Solution(object):
    def maxEqualFreq(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, freq, max_freq, ans = defaultdict(int), defaultdict(int), 0, 0
        for i, n in enumerate(nums):
            cnt[n] += 1
            freq[cnt[n] - 1] -= 1
            freq[cnt[n]] += 1
            max_freq = max(max_freq, cnt[n])
            if (
                max_freq * freq[max_freq] == i
                or (max_freq - 1) * (freq[max_freq - 1] + 1) == i
                or max_freq == 1
            ):
                ans = i + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxEqualFreq(nums=[2, 2, 1, 1, 5, 3, 3, 5]))
    print(obj.maxEqualFreq(nums=[1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5]))
