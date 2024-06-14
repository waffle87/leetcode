# 274. H-Index
from itertools import accumulate

"""
given an array of integers 'citations' where 'citations[i]' is the number of
citations a researcher received for their i'th paper, return the researchers
h-index. according to the definition of h-index on wikipedia: the h-index is
given as the maximum value of 'h' such that the given researcher published at
least 'h' papers that have each been cited 'h' times.
"""


class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        buckets = [0] * (n + 1)
        for i in citations:
            buckets[min(i, n)] += 1
        accum = list(accumulate(buckets[1:][::-1]))[::-1]
        compr = [accum[i] >= i + 1 for i in range(n)]
        return (compr + [0]).index(0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.hIndex([3, 0, 6, 1, 5]))
    print(obj.hIndex([1, 3, 1]))
