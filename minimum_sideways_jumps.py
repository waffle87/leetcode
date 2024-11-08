# 1824. Minimum Sideway Jumps

"""
there is a 3 lane road of length 'n' that consists of 'n + 1' points labeled
from 0 to 'n'. a frog starts at point 0 in the second lane and wants to jump
to point 'n'. however there could be obstacles along the way. you are given
an array 'obstacles' of length 'n + 1' where each 'obstacles[i]' (ranging
from 0 to 3) describes an obstacle on the lane 'obstacles[i]' at point 'i'.
if 'obstacles[i] == 0' there are no obstacles at point 'i'. there will be at
most one obstacles in the 3 lanes at each point. the frog can only travel
from point 'i' to point 'i + 1' on the same lane if there is not an obstacle
on the lane at point 'i + 1'. return the minimum number of side jumps the
frog needs to reach any lane at point 'n' starting from lane 2 at point 0.
"""


class Solution(object):
    def minSideJumps(self, obstacles):
        """
        :type obstacles: List[int]
        :rtype: int
        """
        dp = [1, 0, 1]
        for i in obstacles:
            if i:
                dp[i - 1] = float("inf")
            for j in range(3):
                if i != j + 1:
                    dp[j] = min(dp[j], dp[(j + 1) % 3] + 1, dp[(j + 2) % 3] + 1)
        return min(dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSideJumps(obstacles=[0, 1, 2, 3, 0]))
    print(obj.minSideJumps(obstacles=[0, 1, 1, 3, 3, 0]))
    print(obj.minSideJumps(obstacles=[0, 2, 1, 0, 3, 0]))
