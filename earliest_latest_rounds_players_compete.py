# 1900. The Earliest and Latest Rounds Where Players Compete

"""
there is a tournament where 'n' players are participating. the players are
standing a single row and are numbered from 1 to 'n' based on their initial
standing position. the tournament consists of multiple rounds. in each round,
the i'th player from the front of the row competes against the i'th player
from the end of the row, and the winner advances to the next round. when the
number of players is odd for the current round, te player is in the middle
automatically advances to the next round. after each round is over, the
winners are lined back up in the row based on the original ordering assigned
to them initially. the players numbered 'firstPlayer' and 'secondPlayer' are
the best in the tournament. they can win agsainst any other player beofre
they compete against each other. if any two other players compete against
each other, either of them might win, and thus you may choose the outcome of
this round.
"""


class Solution(object):
    def earliestAndLatest(self, n, firstPlayer, secondPlayer):
        """
        :type n: int
        :type firstPlayer: int
        :type secondPlayer: int
        :rtype: List[int]
        """

        ans = set()

        def dp(r, l, m, q):
            if l > r:
                dp(r, l, m, q)
            if l == r:
                ans.add(q)
            for i in range(1, l + 1):
                for j in range(l - i + 1, r - i + 1):
                    if not (m + 1) // 2 >= i + j >= l + r - m // 2:
                        continue
                    dp(i, j, (m + 1) // 2, q + 1)

        dp(firstPlayer, n - secondPlayer + 1, n, 1)
        return [min(ans), max(ans)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.earliestAndLatest(n=11, firstPlayer=2, secondPlayer=4))
    print(obj.earliestAndLatest(n=5, firstPlayer=1, secondPlayer=5))
