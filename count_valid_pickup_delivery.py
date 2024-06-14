# 1359. Count All Valid Pickup and Delivery Options

"""
given 'n' orders, each order consists in pickup and delivery services. count
all valid pickup/delivery possible sequences such that 'delivery[i]' is
always after 'pickup[i]'. since the answer may be too large, return it modulo
10^9+7
"""


class Solution(object):
    def countOrders(self, n):
        dp = [0] * (n + 1)
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = (i * dp[i - 1] * (2 * i - 1)) % (10**9 + 7)
        return dp[n]


if __name__ == "__main__":
    obj = Solution
    print(obj.countOrders(1))  # expect: 1
    print(obj.countOrders(2))  # expect: 6
    print(obj.countOrders(3))  # expect: 90
