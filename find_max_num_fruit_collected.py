# 3363. Find the Maximum Number of Fruits Collected

"""
there is a game dungeon comprised of 'n x n' rooms arranged in a grid. you
are given a 2d array 'fruits' of size 'n x n' where 'fruits[i][j]' represents
the number of fruits in the room '(i, j)'. three children will play in the
game dungeon, with initial positions at the corner rooms '(0, 0)', '(0, n -
1)', and '(n - 1, 0)'. when a child enters a room, they will collect all the
fruits there. if two or more children enter the same room, only one child
will collect the fruits and the room will be emptied after they leave. return
the maximum number of fruits the children can collect from the dungeon.
"""


class Solution(object):
    def maxCollectedFruits(self, fruits):
        """
        :type fruits: List[List[int]]
        :rtype: int
        """
        n, ans = len(fruits), 0
        for i in range(n):
            ans += fruits[i][i]
        for i in range(2):
            if i == 1:
                for j in range(n):
                    for k in range(j + 1, n):
                        fruits[j][k], fruits[k][j] = fruits[k][j], fruits[j][k]
            curr, prev = [-1] * n, [-1] * n
            prev[n - 1] = fruits[0][n - 1]
            for j in range(1, n - 1):
                for k in range(n):
                    if prev[k] < 0:
                        continue
                    if k > 0:
                        curr[k - 1] = max(curr[k - 1], prev[k] + fruits[j][k - 1])
                    if k < n - 1:
                        curr[k + 1] = max(curr[k + 1], prev[k] + fruits[j][k + 1])
                    curr[k] = max(curr[k], prev[k] + fruits[j][k])
            ans += prev[n - 1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxCollectedFruits(
            fruits=[[1, 2, 3, 4], [5, 6, 8, 7], [9, 10, 11, 12], [13, 14, 15, 16]]
        )
    )
    print(obj.maxCollectedFruits(fruits=[[1, 1], [1, 1]]))
