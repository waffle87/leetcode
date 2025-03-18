# 526. Beautiful Arrangement

"""
suppose you have 'n' integers labeled 1 through 'n'. a permutation of those
'n' integers 'perm' (1-indexed) is considered a beautiful arrangement if for
every 'i' ('1 <= i <= n') either of the following is true: 'perm[i]' is
divisible by 'i', and 'i' is divisible by 'perm[i]'. given an integer 'n',
return the number of the beautiful arrangements that you can construct.
"""


class Solution(object):
    def countArrangement(self, n):
        """
        :type n: int
        :rtype: int
        """

        def dfs(mask, place):
            if place == 0:
                return 1
            res = 0
            for i in range(n):
                if not mask & 1 << i and ((i + 1) % place == 0 or place % (i + 1) == 0):
                    res += dfs(mask ^ 1 << i, place - 1)
            return res

        return dfs(0, n)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countArrangement(n=2))
    print(obj.countArrangement(n=1))
