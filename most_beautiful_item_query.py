# 2070. Most Beautiful Item for Each Query
from bisect import bisect

"""
you are given a 2d integer array 'items' where 'items[i] = [price_i,
beauty_i]' denotes the price and beauty of an item respectively. you are also
given a 0-indexed integer array 'queries'. for each 'queries[i]' you want to
determine the maximum beauty of an item whose price is less than or equal to
'queries[i]'. if no such item exists, then the answer to this query is 0.
return an array 'answer' of the same length as 'queries' where 'answer[i]' is
the answer to the i'th query.
"""


class Solution(object):
    def maximumBeauty(self, items, queries):
        """
        :type items: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        items = sorted(items + [[0, 0]])
        for i in range(len(items) - 1):
            items[i + 1][1] = max(items[i][1], items[i + 1][1])
        return [items[bisect(items, [q + 1]) - 1][1] for q in queries]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maximumBeauty(
            items=[[1, 2], [3, 2], [2, 4], [5, 6], [3, 5]], queries=[1, 2, 3, 4, 5, 6]
        )
    )
    print(obj.maximumBeauty(items=[[1, 2], [1, 2], [1, 3], [1, 4]], queries=[1]))
    print(obj.maximumBeauty(items=[[10, 1000]], queries=[5]))
