# 3223. Minimum Length of String After Operations
from collections import Counter

"""
you are given a string 's'. you can perform the following process on 's' any
number of times: choose an index 'i' in the string such that there is at
least one character to the left of index 'i' that is equal to 's[i]' and at
least one character to the right that is also equal to 's[i]', delete the
closest character to the left of index 'i' that is equal to 's[i]', delete
the closest character to the right of index 'i' that is equal to 's[i]'.
return the minimum length of the final string 's' that you can achieve
"""


class Solution(object):
    def minimumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        map, ans = Counter(s), 0
        for c, cnt in map.items():
            ans += 1
            if not cnt % 2:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumLength("abaacbcbb"))
    print(obj.minimumLength("aa"))
