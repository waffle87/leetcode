# 70. Climbing Stairs

"""
you are climbinga staircase. it takes 'n' steps to reach the top. each time
you can either climb one or two steps. in how many distinct ways can you
climb to the top?
"""


class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        ways = 1
        for i in range(1, (n // 2) + 1):
            product = 1
            for j in range(i, 2 * i):
                product *= (n - j) / (j - i + 1)
            ways += product
        return int(ways)


if __name__ == "__main__":
    obj = Solution()
    print(obj.climbStairs(2))
    print(obj.climbStairs(3))
