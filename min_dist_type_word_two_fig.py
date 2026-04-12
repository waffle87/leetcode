# 1320. Minimum Distance to Type a Word Using Two Fingers

"""
you have a keyboard layout shown above in the xy plane, where each english
uppercase letter is located at some coordinate. for example, the letter 'A'
is located at coordinate '(0, 0)'. given the string 'word', return the
minimum total distance to type such string use only two fingers. the distance
between coordinates '(x1, y1)' and '(x2, y2)' is '|x1 - x2| + |y1 - y2|'.
note that the initial positions of your two fingers are considered free so do
not count twoards your total distance. aslso your two fingers do no have to
start at he first letter or the first two letters
"""


class Solution:
    def minimumDistance(self, word: str) -> int:
        def dist(p, q):
            if p == 26 or q == 26:
                return 0
            return abs(p // 6 - q // 6) + abs(p % 6 - q % 6)

        n = len(word)
        arr = ord("A")
        idx = [ord(c) - arr for c in word]
        dp = [[float("inf")] * 27 for _ in range(27)]
        dp[26][26] = 0
        for c in idx:
            ndp = [[float("inf")] * 27 for _ in range(27)]
            for i in range(27):
                for j in range(27):
                    v = dp[i][j]
                    if v >= float("inf"):
                        continue
                    if v + dist(i, c) < ndp[c][j]:
                        ndp[c][j] = v + dist(i, c)
                    if v + dist(j, c) < ndp[i][c]:
                        ndp[i][c] = v + dist(j, c)
            dp = ndp
        return min(min(row) for row in dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDistance(word="CAKE"))
    print(obj.minimumDistance(word="HAPPY"))
