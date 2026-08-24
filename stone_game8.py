# 1872. Stone Game VIII

"""
alice and bob take turns playing a game, with alice starting first. there are
'n' stones arranged in a row. on each player's turn, while the number of
stones is more than 1, they will do the following: chosen an integer 'x > 1'
and remove the leftmost 'x' stones from the row. add the sum of the removed
stones values to the player's score, and place a new stone whose value is
equal to the that sum on the left side of the row. the game stops when only
one stone is left in the row. the score difference between alice and bob is
'alice - bob'. alice's goal is to maximise the score difference, and bob's
goal is to minimise the score difference. given an integer array 'stones' of
length 'n' where 'stones[i]' represents the value of the i'th stone from the
left, return the score difference.
"""


class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        n = len(stones)
        for i in range(1, n):
            stones[i] += stones[i - 1]
        best = stones[-1]
        for i in stones[-2:0:-1]:
            best = max(best, i - best)
        return best


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGameVIII(stones=[-1, 2, -3, 4, -5]))
    print(obj.stoneGameVIII(stones=[7, -6, 5, 10, 5, -2, -6]))
    print(obj.stoneGameVIII(stones=[-10, -12]))
