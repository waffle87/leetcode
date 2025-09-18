# 2055. Plates Between Candles
import bisect

"""
there is a long table with a line of plates and candles arranged on top of
it. you are given a 0-indexed string 's' consisting of characters '*' and '|'
only where '*' represents a plate and '|' represents a candle. return an
integer array 'answer' where 'answer[i]' is the answer to the i'th query.
"""


class Solution(object):
    def platesBetweenCandles(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        dp = [i for i, j in enumerate(s) if j == "|"]
        ans = []
        for a, b in queries:
            i = bisect.bisect_left(dp, a)
            j = bisect.bisect(dp, b) - 1
            ans.append((dp[j] - dp[i]) - (j - i) if i < j else 0)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.platesBetweenCandles(s="**|**|***|", queries=[[2, 5], [5, 9]]))
    print(
        obj.platesBetweenCandles(
            s="***|**|*****|**||**|*",
            queries=[[1, 17], [4, 5], [14, 17], [5, 11], [15, 16]],
        )
    )
