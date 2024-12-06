# 2554. Maximum Number of Integers to Choose From a Range I

"""
you are given an integer array 'banned' and two integers 'n' and a 'maxSum'.
you are choosing some number of integers following the below rules: the
chosen integers have to be in the range '[1, n]', each integer can be chosen
at most once, the chosen integers should not be in the array 'banned', and
the sum of the chosen ntegers should not exceed 'maxSum'. return the maximum
number of integers you can choose following the mentioned rules.
"""


class Solution(object):
    def maxCount(self, banned, n, maxSum):
        """
        :type banned: List[int]
        :type n: int
        :type maxSum: int
        :rtype: int
        """
        ans, banned = -1, set(banned)
        for i in range(1, n + 1):
            if i not in banned:
                maxSum -= i
                ans += 1
            if maxSum < 0:
                return ans
        return ans + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxCount(banned=[1, 6, 5], n=5, maxSum=6))
    print(obj.maxCount(banned=[1, 2, 3, 4, 5, 6, 7], n=8, maxSum=1))
    print(obj.maxCount(banned=[11], n=7, maxSum=50))
