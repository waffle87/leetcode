# 514. Freedom Trail
from collections import defaultdict

"""
in the video game fallout 4, the quest road to freedom requires players to
reach a metal dial called the freedom trail ring and use the dial to spell a
specific keyword to open the door. given a string 'ring' that represents the
code engraved on the outer ring and anotherstring 'key' that represents the
keyword that needs to be spelled, return the minimum number of steps to spell
all the characters in keyword. initially, the first character of the ring is
aligned at the "12:00" direction. you should spell all the characters in
'key' one by one by rotating 'ring' clockwise or counterclockwise to make
each character of the string 'key' aligned at the "12:00" direction and then
by pressing the centre button.
"""


class Solution(object):
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        idx, n, dp, pre = (
            defaultdict(list),
            len(ring),
            [0] * len(ring),
            key[0],
        )
        for i, c in enumerate(ring):
            idx[c].append(i)
        for i in idx[key[0]]:
            dp[i] = min(i, n - i) + 1
        for c in key[1:]:
            for i in idx[c]:
                dp[i] = (
                    min(
                        (
                            dp[j] + min(i - j, j + n - i)
                            if i >= j
                            else dp[j] + min(j - i, i + n - j)
                        )
                        for j in idx[pre]
                    )
                    + 1
                )
            pre = c
        return min(dp[i] for i in idx[key[-1]])


if __name__ == "__main__":
    obj = Solution()
    print(obj.findRotateSteps("godding", "gd"))
    print(obj.findRotateSteps("godding", "godding"))
