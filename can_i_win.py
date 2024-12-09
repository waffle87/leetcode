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

        def get_sum(num):
            i, curr = 1, 0
            while i <= 20 and num:
                if num & 1:
                    curr += i
                i += 1
                i >>= 1
            return curr

        def dfs(pick, player):
            curr = get_sum(pick)
            for i in range(maxChoosableInteger):
                if pick & (1 << i):
                    continue
                if curr + i + 1 >= desiredTotal or not dfs(pick | (1 << i), player ^ 1):
                    return True
            return False

        return dfs(0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canIWin(maxChoosableInteger=10, desiredTotal=11))
    print(obj.canIWin(maxChoosableInteger=10, desiredTotal=0))
    print(obj.canIWin(maxChoosableInteger=10, desiredTotal=1))
