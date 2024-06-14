# 2225. Find Players With Zero or One Losses

"""
given an integer array 'matches' where 'matches[i] = [winner[i], loser[i]]'
indicates a defeated player 'loser[i]' in a match. return a list 'answer' of
size 2 where 'answer[0]' is a list of all players that have not lost any
matches. 'answer[1]' is a list of all players that have lost exactly one
match. the values in the two lists should be returned in increasing order.
"""


class Solution(object):
    def findWinners(self, matches):
        """
        :type matches: List[List[int]]
        :rtype: List[List[int]]
        """
        losses = [0] * 100001
        for winner, loser in matches:
            if losses[winner] == 0:
                losses[winner] = -1
            if losses[loser] == -1:
                losses[loser] = 1
            else:
                losses[loser] += 1
        zero_loss = [i for i in range(1, 100001) if losses[i] == -1]
        one_loss = [i for i in range(1, 100001) if losses[i] == 1]
        return [zero_loss, one_loss]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findWinners(
            matches=[
                [1, 3],
                [2, 3],
                [3, 6],
                [5, 6],
                [5, 7],
                [4, 5],
                [4, 8],
                [4, 9],
                [10, 4],
                [10, 9],
            ]
        )
    )
    print(obj.findWinners(matches=[[2, 3], [1, 3], [5, 4], [6, 4]]))
