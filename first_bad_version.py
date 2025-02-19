# 278. First Bad Version
from bisect import bisect_left

"""
you are a product manager and currently leading a team to develop a new
product. unfortunately, the latest version of your product fails the quality
check. since each version is developed based on the previous version, all the
versions after a bad version are also bad. suppose you have 'n' versions '[1,
,2, ..., n]' and you want to find out the first bad one, which causes all the
following ones to be bad. you are given an api 'bool isBadVersion(version)'
which returns whether 'version' is bad. implement a function to find the
first bad version. you should minimise the number of calls to the api.
"""


class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        return bisect_left(self, True, 1, n)

    def __getitem__(self, key):
        return isBadVersion(key)


if __name__ == "__main__":
    obj = Solution()
    print(obj.firstBadVersion(5))
    print(obj.firstBadVersion(1))
