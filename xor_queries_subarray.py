# 1310. XOR Queries of a Subarray

"""
you are given an array 'arr' of positive integers. you are also given the
array 'queries' where 'queries[i] = [left_i, right_i]'. for each query 'i'
compute the xor of elements from 'left_i' to 'right_i'. return an array
'answer' where 'answer[i]' is the answer to the i'th query
"""


class Solution(object):
    def xorQueries(self, arr, queries):
        """
        :type arr: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        for i in range(len(arr) - 1):
            arr[i + 1] ^= arr[i]
        return [arr[j] ^ arr[i - 1] if i else arr[j] for i, j in queries]


if __name__ == "__main__":
    obj = Solution()
    print(obj.xorQueries(arr=[1, 3, 4, 8], queries=[[0, 1], [1, 2], [0, 3], [3, 3]]))
    print(obj.xorQueries(arr=[4, 8, 2, 10], queries=[[2, 3], [1, 3], [0, 0], [0, 3]]))
