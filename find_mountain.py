# 1095. Find in Mountain Array

"""
1. find peak and record location and value that's already been queried, and verify if target has happened
2. if target has happened and idx <= peak, exit and return ans
3. query right of mountain and return true if target is found
4. query left of mountain and return true if target is found
5. if target is not found, return -1
"""

class Solution(object):
    def findInMountainArray(self, target, A):
        n = A.length()
        l, r = 0, n - 1
        while l < r:
            m = (l + r) / 2
            if A.get(m) < A.get(m + 1):
                l = peak = m + 1
            else:
                r = m
        l, r = 0, peak
        while l <= r:
            m = (l + r) / 2
            if A.get(m) < target:
                l = m + 1
            elif A.get(m) > target:
                r = m - 1
            else:
                return m
        l, r = peak, n - 1
        while l <= r:
            m = (l + r) / 2
            if A.get(m) > target:
                l = m + 1
            elif A.get(m) < target:
                r = m - 1
            else:
                return m
        return -1
