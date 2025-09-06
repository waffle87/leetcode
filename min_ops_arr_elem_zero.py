# 3495. Minimum Operations to Make Array Elements Zero

"""
you are given a 2d array 'queries' where 'queries[i]' is of the form '[l,
r]'. each 'queries[i]' defines an array of integers 'nums' consisting of
elements ranging from 'l' to 'r' both inclusive. in one operation you can
select two integers 'a' and 'b' from the array and replace them with 'floor(a
/ 4)' and 'floor(b / 4)'. your task is to determine the minimum number of
operations required to reduce all the elements of the array to zero for each
query. return the sum of the results for all queries.
"""


class Solution(object):
    def count(self, a):
        res, k, v = 0, 1, 1
        while a >= v * 4:
            res += (v * 4 - v) * k
            k += 1
            v *= 4
        return res + (a - v + 1) * k

    def minOperations(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: int
        """
        ans = 0
        for l, r in queries:
            ans += (self.count(r) - self.count(l - 1)) // 2
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(queries=[[1, 2], [2, 4]]))
    print(obj.minOperations(queries=[[2, 6]]))
