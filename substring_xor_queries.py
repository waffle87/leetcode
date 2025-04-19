# 2564. Substring XOR Queries
from collections import defaultdict

"""
you are given a binary string 's' and a 2d integer array 'queries' where
'queries[i] = [first_i, second_i]'. for the i'th query, find the shortest
substring of 's' whose decimal value 'val' yields 'second_i' when bitwise
xor'd with 'first_i'. in other words, 'val ^ first_i == second_i'. the answer
to the i'th query is the endpoints of the substring '[left_i, right_i]' or
'[-1, -1]' if no such substring exists. if there are multiple answers, choose
the one with the minimum 'left_i'. return an array 'ans' where 'ans[i] =
[left_i, right_i]' is the answer to the i'th query. a substring is a
contiguous non-empty sequence of characters within a string.
"""


class Solution(object):
    def substringXorQueries(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(s)
        vis = defaultdict(lambda: [-1, -1])
        for i in range(n - 1, -1, -1):
            if s[i] == "0":
                vis[0] = [i, i]
                continue
            curr = 0
            for j in range(i, n):
                curr = curr * 2 + int(s[j])
                if curr > 2**32:
                    break
                vis[curr] = [i, j]
        return [vis[a ^ b] for b, a in queries]


if __name__ == "__main__":
    obj = Solution()
    print(obj.substringXorQueries(s="101101", queries=[[0, 5], [1, 2]]))
    print(obj.substringXorQueries(s="0101", queries=[[12, 8]]))
    print(obj.substringXorQueries(s="1", queries=[[4, 5]]))
