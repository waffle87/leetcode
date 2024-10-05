# 567. Permutation in String
from collections import Counter

"""
given two strings 's1 s2' return true if 's2' contains a permutation of 's1'
or false otherwise. in other words, return true if one of 's1's permutations
is in the substring of 's2'
"""


class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        cnt, n, match = Counter(s1), len(s1), 0
        for i in range(len(s2)):
            if s2[i] in cnt:
                if not cnt[s2[i]]:
                    match -= 1
                cnt[s2[i]] -= 1
                if not cnt[s2[i]]:
                    match += 1
            if i >= n and s2[i - n] in cnt:
                if not cnt[s2[i - n]]:
                    match -= 1
                cnt[s2[i - n]] += 1
                if not cnt[s2[i - n]]:
                    match += 1
            if match == len(cnt):
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkInclusion(s1="ab", s2="eidbaooo"))
    print(obj.checkInclusion(s1="ab", s2="eidboaoo"))
