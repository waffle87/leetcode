# 2402. Meeting Rooms III

"""
you are given an integer 'n', there are 'n' rooms numbered 0 to 'n - 1'.
guven a 2d integer array 'meetings', where 'meetings[i] = start[i], end[i]'
means that a meeting will be held during the half closed time interval
'[start[i], end[i]]'. all thevalues of 'start[i]' are unique. meetings are
allocated to rooms in the following manner: each meeting will take place in
the unused room with the lowest number. if there are no available rooms, the
meeting will be delayed until a room becoms free. the dleayed meeting should
have the same duration as the original meeting. when a room becoms unused,
meetings that have an earlier original start time should be given the room,
return the number of the room that held the most meetings. if there are
multiple rooms, return the room with the lowest number. a half closed
interval '[a, b)' is the interval between 'a' and 'b' including 'a' and not
including 'b'.
"""


class Solution(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        ready = [r for r in range(n)]
        rooms = []
        heapify(ready)
        ans = [0] * n
        for s, e in sorted(meetings):
            while rooms and rooms[0][0] <= s:
                t, r = heappop(rooms)
                heappush(ready, r)
            if ready:
                r = heappop(ready)
                heappush(rooms, [e, r])
            else:
                t, r = heappop(rooms)
                heappush(rooms, [t + e - s, r])
            ans[r] += 1
        return ans.index(max(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.mostBooked(n=2, meetings=[[0, 10], [1, 5], [2, 7], [3, 4]]))
    print(obj.mostBooked(n=3, meetings=[[1, 20], [2, 10], [3, 5], [4, 9], [6, 8]]))
