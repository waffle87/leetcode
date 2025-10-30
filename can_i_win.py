# 464. Can I Win

"""
in the 100 game two players take turns adding, to a running total, any
integer from 1 to 10. the player who first causes the running total to reach
or exceed 100 wins. what if we change the same so that players cannot re-use
integers? for example, two players might take turns drawing from a common
pool of numbers from 1 to 15 without replacement until they reach a total >=
100. given two integers 'maxChoosableInteger' nad 'desiredTotal', return true
if the first player to move can force a win, otherwise, return false. assume
both players play optimally.
"""


class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        if desiredTotal <= 0:
            return True
        if sum(range(1, maxChoosableInteger + 1)) < desiredTotal:
            return False
        vis = {}

        def dfs(choices, total):
            state = tuple(choices)
            if state in vis:
                return vis[state]
            if choices[-1] >= total:
                vis[state] = True
                return True
            for i in range(len(choices)):
                if not dfs(choices[:i] + choices[i + 1 :], total - choices[i]):
                    vis[state] = True
                    return True
            vis[state] = False
            return False

        return dfs(list(range(1, maxChoosableInteger + 1)), desiredTotal)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canIWin(maxChoosableInteger=10, desiredTotal=11))
    print(obj.canIWin(maxChoosableInteger=10, desiredTotal=0))
    print(obj.canIWin(maxChoosableInteger=10, desiredTotal=1))
