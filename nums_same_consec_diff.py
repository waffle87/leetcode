# 967. numbers With Same Consecutive Differences

"""
given two integers 'n' and 'k' return an array of all the integers of length
'n' where the difference between every two consecutive digits is 'k'. you may
return the answer in any order. note that the integers should not have
leading zeros. integers as 02 and 043 are not allowed.
"""


class Solution(object):
    def numsSameConsecDiff(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        curr = range(1, 10)
        for i in range(n - 1):
            curr = {
                x * 10 + y
                for x in curr
                for y in [x % 10 + k, x % 10 - k]
                if 0 <= y <= 9
            }
        return list(curr)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numsSameConsecDiff(3, 7))
    print(obj.numsSameConsecDiff(2, 1))
