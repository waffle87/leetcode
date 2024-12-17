# 2182. Construct String With Repeat Limit
import heapq
from collections import Counter

"""
you are given a string 's' and an integer 'repeatLimit'. construct a new
string 'repeatLimitedString' using the characters of 's' such that no letter
appears more than 'repeatLimit' times in a row. you do not have to use all
characters from 's'. return the lexicographically largest
'repeatLimitedString' possible. a string 'a' is lexicographically larger than
string 'b' if in the first position where 'a' and 'b' differ, string 'a' has
a letter that appears later in the alphabet than the corresponding letter  in
'b'. if the first 'min(a.len, b.len)' characters do not differ, then the
longer string is the lexicographically larger one
"""


class Solution(object):
    def repeatLimitedString(self, s, repeatLimit):
        """
        :type s: str
        :type repeatLimit: int
        :rtype: str
        """
        pq = [(-ord(k), v) for k, v in Counter(s).items()]
        heapq.heapify(pq)
        ans = []
        while pq:
            k, v = heapq.heappop(pq)
            if ans and ans[-1] == k:
                if not pq:
                    break
                kk, vv = heapq.heappop(pq)
                ans.append(kk)
                if vv - 1:
                    heapq.heappush(pq, (kk, vv - 1))
                heapq.heappush(pq, (k, v))
            else:
                m = min(v, repeatLimit)
                ans.extend([k] * m)
                if v - m:
                    heapq.heappush(pq, (k, v - m))
        return "".join(chr(-x) for x in ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.repeatLimitedString(s="cczazcc", repeatLimit=3))
    print(obj.repeatLimitedString(s="aababab", repeatLimit=2))
