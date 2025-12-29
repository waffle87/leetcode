# 756. Pyramid Transition Matrix
from collections import defaultdict

"""
you are stacking blocks to form a pyramid. each block has a colour which is
represented by a single letter. each row of blocks contains one less block
than the row beneat it and is centered on top. to make the pyramid
aesthetically pleasing, there are only specific triangular patterns that are
allowed. a triangular pattern consists of a single block stacked on top of
two blocks. the patterns are given as a list of three letter strings
'allowed', where the first two characters of a pattern represent the third
character is the top block. you start with a bottom row of blocks 'bottom',
given as a string, that you must use as the base of the pyramid. given
'bottom' and 'allowed', return 'true' if you can build the pyramid all the
way to the top such that every triangular pattern in the pyramid is in
'allowed', or false otherwise.
"""


class Solution(object):
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        dp, vis = defaultdict(set), set()
        for u, v, w in allowed:
            dp[u, v].add(w)

        def add_neighbour(node):
            res = [""]
            for i in range(1, len(node)):
                curr = dp[(node[i - 1], node[i])]
                if curr:
                    res = [i + j for j in curr for i in res]
                else:
                    return []
            return res

        def dfs(node):
            if len(node) == 1:
                return True
            if node in vis:
                return False
            for i in add_neighbour(node):
                if dfs(i):
                    return True
            vis.add(node)
            return False

        return dfs(bottom)


if __name__ == "__main__":
    obj = Solution()
    print(obj.pyramidTransition(bottom="BCD", allowed=["BCC", "CDE", "CEA", "FFF"]))
    print(
        obj.pyramidTransition(
            bottom="AAAA", allowed=["AAB", "AAC", "BCD", "BBE", "DEF"]
        )
    )
