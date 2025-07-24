# 600. Non-negative Integers without Consecutive Ones

"""
given a positive integer 'n', return the number of the integers in the range
'[0, n]' whose binary representations do not contain consecutive ones.
"""


class Solution(object):
    def findIntegers(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = bin(n + 1)[2:]
        num = len(s)
        dp = [1, 2] + [0] * (num - 2)
        for i in range(2, num):
            dp[i] = dp[i - 1] + dp[i - 2]
        flag, ans = False, 0
        for i in range(num):
            if s[i] == "0":
                continue
            if flag:
                break
            if i > 0 and s[i - 1] == "1":
                flag = True
            ans += dp[-i - 1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findIntegers(n=5))
    print(obj.findIntegers(n=1))
    print(obj.findIntegers(n=2))
