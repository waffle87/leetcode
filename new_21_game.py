# 837. New 21 Game

"""
alice plays the following game, loosely based on the card game "21". alice
starts with 0 points and draws numbers while she has less than 'k' points.
during each draw, she gains an integer number of points randomly from range
'[1, maxPts]', where 'maxPts' is an integer. each draw is independent and
the outcomes have equal posibilities. alice stops drawing numbers when she
gets 'k' or more points. return the probability that alice has 'n' or fewer
points. answers within 10^-5 of the actual answer are considered accepted
"""


class Solution(object):
    def new21Game(self, n, k, maxPts):
        """
        :type n: int
        :type k: int
        :type maxPts: int
        :rtype: float
        """
        if k == 0 or n >= k + maxPts:
            return 1
        dp = [1.0] + [0.0] * n
        sum = 1.0
        for i in range(1, n + 1):
            dp[i] = sum / maxPts
            if i < k:
                sum += dp[i]
            if i - maxPts >= 0:
                sum -= dp[i - maxPts]
        return sum(dp[k:])


if __name__ == "__main__":
    obj = Solution()
    print(obj.new21Game(n=10, k=1, maxPts=10))
    print(obj.new21Game(n=6, k=1, maxPts=10))
    print(obj.new21Game(n=21, k=17, maxPts=10))
