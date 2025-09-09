# 2327. Number of People Aware of a Secret

"""
on day 1, one person discovers  decret. you are given an integer 'delay'
which means that each person will share the secret with a new person every
day starting from 'delay' days after discovering the secret. you are also
given an integer 'forget', which means that each person will forget the
secret 'forget' days after discovering it. a person cannot share the secret
on the same day they forgot it, or any day afterwards. given an integer 'n',
return the number of people who know the secret at the end of day 'n'. since
the answer may be very large, return it modulo 10^9+7.
"""


class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """
        dp = [1] + [0] * forget
        share, mod = 0, 10**9 + 7
        for i in range(1, n):
            dp[i % forget] = share = (
                share + dp[(i - delay) % forget] - dp[i % forget]
            ) % forget
        return sum(dp) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.peopleAwareOfSecret(6, 2, 4))
    print(obj.peopleAwareOfSecret(4, 1, 3))
