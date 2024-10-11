# 1942. The Number of the Smallest Unoccupied Chair
import heapq

"""
there is a party where 'n' friends numbered from 0 to 'n - 1' are attending.
there is an infinite number of chairs in this part that are numbered from 0
to 'infinity'. when a friend arrives at the party, they sit on the unoccupied
chair with the smallest number. when a friend leaves the party their chair
becomes unoccupied at the moment they leave. if another friend arrives at
that same moment, they can sit in that chair. you are given a 0-indexed 2d
integer array 'times' where 'times[i] = [arrival[i], leaving[i]]' indicating
the arrival and leaving times of the i'th friend respectively. and an integer
'targetFriend'. all arrival times are distinct. return the chair number that
the friend numbered 'targetFriend' will sit on.
"""


class Solution(object):
    def smallestChair(self, times, targetFriend):
        """
        :type times: List[List[int]]
        :type targetFriend: int
        :rtype: int
        """
        order = sorted(range(len(times)), key=lambda x: times[x][0])
        empty, taken = list(range(len(times))), []
        for i in order:
            arrive, leave = times[i]
            while taken and taken[0][0] <= arrive:
                heapq.heappush(empty, heapq.heappop(taken)[1])
            seat = heapq.heappop(empty)
            if i == targetFriend:
                return seat
            heapq.heappush(taken, (leave, seat))


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestChair(times=[[1, 4], [2, 3], [4, 6]], targetFriend=1))
    print(obj.smallestChair(times=[[3, 10], [1, 5], [2, 6]], targetFriend=0))
