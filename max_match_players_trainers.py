# 2410. Maximum Matching of Players With Trainers
import heapq

"""
you are given a 0-indexed integer array 'players' where 'players[i]'
represents the ability of the i'th player. you are also given a 0-indexed
integer array 'trainers', where 'trainers[j]' represents the j'th  capacity
of the trainer. the i'th player can match with the j'th trainer if the
players ability is less than or equal to the trainers training capacity.
additionally, the i'th player can matchedwith at most one trainer, and the
j'th trainer can be matched with at most one player. return the maximum
number of matchings between 'players' and 'trainers' that satisfy these
conditions.
"""


class Solution(object):
    def matchPlayersAndTrainers(self, players, trainers):
        """
        :type players: List[int]
        :type trainers: List[int]
        :rtype: int
        """
        heapq.heapify(players)
        trainers.sort()
        return sum(
            bool(players and players[0] <= i and heapq.heappop(players))
            for i in trainers
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.matchPlayersAndTrainers(players=[4, 7, 9], trainers=[8, 2, 5, 8]))
    print(obj.matchPlayersAndTrainers(players=[1, 1, 1], trainers=[10]))
