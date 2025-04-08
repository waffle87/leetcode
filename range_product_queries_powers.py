# 2438. Range Product Queries of Powers

"""
given a positive integer 'n', there exists a 0-indexed array called 'powers'
composed of the minimum number of powers of 2 that sum to 'n'. the array is
sorted in non-decreasing order, and there is only one way to form the array.
you are also given a 0-indexed 2d integer array 'queries' where 'queries[i] =
[left_i, right_i]'. each 'queries[i]' represents a query where you have to
find the product of all 'powers[j]' with 'left_i <= j <= right_i'. return an
array 'answers', equal in length to 'queries', where 'answers[i]' is the
answer to each i'th query. since the answer may be too large, each
'answers[i]' should be returned modulo 10e9+7.
"""


class Solution(object):
    def productQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        mod, powers, i = 10**9 + 7, [], 0
        while n > 0:
            if n & 1:
                powers.append(1 << i)
            n >>= 1
            i += 1
        ans = []
        for left, right in queries:
            prod = 1
            for i in range(left, right + 1):
                prod = (prod * powers[i]) % mod
            ans.append(prod)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.productQueries(n=15, queries=[[0, 1], [2, 2], [0, 3]]))
    print(obj.productQueries(n=2, queries=[[0, 0]]))
