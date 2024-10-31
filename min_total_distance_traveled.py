# 2463. Minimum Total Distance Traveled

"""
there are some robots and factories on the x-axis. you are given an integer
array 'robot' where 'robot[i]' is the position of the i'th robot. you are
also given a 2d integer array 'factory' where 'factory[j] = [position_i,
limit_i]' indicates that 'position[j]' is the position of the j'th factory
and that the j'th factory can repair at most 'limit[j]' robots. the positions
of each robot are unique. note that a robot can be in the same position as a
factory initially. all the robots are initially broke; they keep moving in
one direction. the direction could be the negative or positive direction of
the x-axis. when a robot reaches a factory that did not reach its limit, the
factory repairs the robot and it stops moving. return the minimum total
distance traveled by all the robots. the test cases are generated as such
that all the robots can be repaired.
"""


class Solution(object):
    def minimumTotalDistance(self, robot, factory):
        """
        :type robot: List[int]
        :type factory: List[List[int]]
        :rtype: int
        """
        n, m = len(robot), len(factory)
        dp = [float("inf")] * (n + 1)
        dp[n] = 0
        robot.sort()
        factory.sort()
        for j in range(m - 1, -1, -1):
            for i in range(n):
                curr = 0
                for k in range(1, min(factory[j][1], n - i) + 1):
                    curr += abs(robot[i + k - 1] - factory[j][0])
                    dp[i] = min(dp[i], dp[i + k] + curr)
        return dp[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumTotalDistance(robot=[0, 4, 6], factory=[[2, 2], [6, 2]]))
    print(obj.minimumTotalDistance(robot=[1, -1], factory=[[-2, 1], [2, 1]]))
