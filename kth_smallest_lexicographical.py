# 440. K-th Smallest in Lexicographical Order

"""
given two integers 'n' and 'k', return the k'th lexicographically smallest
integer
"""


class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        curr = 1
        k -= 1
        while k > 0:
            cnt = 0
            interval = [curr, curr + 1]
            while interval[0] <= n:
                cnt += min(n + 1, interval[1]) - interval[0]
                interval = [10 * interval[0], 10 * interval[1]]
            if k >= cnt:
                curr += 1
                k -= cnt
            else:
                curr *= 10
                k -= 1
        return curr


if __name__ == "__main__":
    obj = Solution()
    print(obj.findKthNumber(13, 2))
    print(obj.findKthNumber(1, 1))
