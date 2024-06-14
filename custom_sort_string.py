# 791. Custom Sort String
from collections import Counter

"""
given two strings 'order' and 's'. all the characters of 'order' are unique
and were sorted in some custom order previously. permute the characters of
's' so that they atch the order that 'order' was sorted. more specifically,
if a character 'x' occurs before character 'y' in 'order', then 'x' should
occur before 'y' in permuted string. return any permutation of 's' that
satisfies this property.
"""


class Solution(object):
    def customSortString(self, order, s):
        """
        :type order: str
        :type s: str
        :rtype: str
        """
        cnt = Counter(s)
        ans = [cnt.pop(c, 0) * c for c in order]
        for c, v in cnt.items():
            ans.append(c * v)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.customSortString("cba", "abcd"))
    print(obj.customSortString("bcafg", "abcd"))
