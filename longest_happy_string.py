# 1405. Longest Happy String
from collections import Counter

"""
a string 's' is called happy if it satisfies the following conditions: 's'
only contains the letters 'a', 'b', 'c', does not contain any of 'aaa',
'bbb', or 'ccc' as a substring, contains at most 'n' occurences of the
letters 'a', 'b', 'c'. given three integers, return the longest possible
happy string. if there are multiple longest happy strings, return any of
them. if there is no such string, return the empty string
"""


class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        ans = []
        rem = Counter({"a": a, "b": b, "c": c})
        (fence, _), (wedge, _) = rem.most_common(2)
        while rem[fence] > 0 and rem[wedge] > 0:
            ans.append(fence)
            rem[fence] -= 1
            if len(ans) >= 2 and ans[-2] == fence:
                pass
            elif rem[fence] > 0:
                ans.append(fence)
                rem[fence] -= 1
            ans.append(wedge)
            rem[wedge] -= 1
            (fence, _), (wedge, _) = rem.most_common(2)
        if rem[fence] > 0:
            ans.append(fence)
            rem[fence] -= 1
            if rem[fence] > 0:
                ans.append(fence)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestDiverseString(a=1, b=1, c=7))
    print(obj.longestDiverseString(a=7, b=1, c=0))
