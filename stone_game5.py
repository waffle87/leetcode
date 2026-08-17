# 1563. Stone Game V
from functools import lru_cache

"""
there are several stones arranged in a row, and each stone has an associated
value which is an integer given in the array 'stoneValue'. in each round of
the game, alice divides the row into two non-empty rows, then bob calculates
the value of each row which is the sum of the values of all the stones in
this row. bob throws away the row which has the maximum value, and alice's
score increases by the value of the remaining row. if the value of the two
rows are equal, bob lets alice decicde which row will be thrown away. the
next round starts with the remaining row. the game ends when there is only
one stone remaining. alice's score is initially zero. return the maximum
score that alice can obtain.
"""


class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        pre = [0]
        for i in stoneValue:
            pre += (pre[-1] + i,)

        def sm(i, j):
            return pre[j + 1] - pre[i]

        @lru_cache(None)
        def helper(i, j):
            if i == j:
                return 0
            if all(stoneValue[k] == stoneValue[j] for k in range(i, j)):
                cnt = 0
                l = j - i + 1
                while l > 1:
                    l //= 2
                    cnt += l
                return cnt * stoneValue[j]
            res = 0
            for k in range(i, j):
                if sm(i, k) < sm(k + 1, j):
                    score = helper(i, k) + sm(i, k)
                elif sm(i, k) > sm(k + 1, j):
                    score = sm(k + 1, j) + helper(k + 1, j)
                else:
                    score = max(
                        helper(i, k) + sm(i, k), sm(k + 1, j) + helper(k + 1, j)
                    )
                res = max(res, score)
            return res

        return helper(0, len(stoneValue) - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGameV(stoneValue=[6, 2, 3, 4, 5, 5]))
    print(obj.stoneGameV(stoneValue=[7, 7, 7, 7, 7, 7, 7]))
    print(obj.stoneGameV(stoneValue=[4]))
