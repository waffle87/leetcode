# 756. Pyramid Transition Matrix
from collections import defaultdict
from itertools import product

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
        f = defaultdict(lambda: defaultdict(list))
        for a, b, c in allowed:
            f[a][b].append(c)

        def helper(bottom):
            return len(bottom) == 1 or any(
                helper(i)
                for i in product(*(f[a][b] for a, b in zip(bottom, bottom[1:])))
            )

        return helper(bottom)


if __name__ == "__main__":
    obj = Solution()
    print(obj.pyramidTransition(bottom="BCD", allowed=["BCC", "CDE", "CEA", "FFF"]))
    print(
        obj.pyramidTransition(
            bottom="AAAA", allowed=["AAB", "AAC", "BCD", "BBE", "DEF"]
        )
    )
