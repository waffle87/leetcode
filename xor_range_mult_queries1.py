# 3653. XOR After Range Multiplication Queries I
import numpy as np

"""
you are given an integer array 'nums' of length 'n' and a 2d integer array
'queries' of size 'q', where 'queries[i] = [l, r, k, v]'. for each query, you
must apply the following operations in order: set 'idx = l', while 'idx <=
r', update 'nums[idx] = (nums[idx]  v) % (10^9 + 7)', set 'idx += k'. return
the bitwise xor of all elements in 'nums' after processing all queries.
"""


class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        arr = np.array(nums, dtype=np.int64)
        mod = 10**9 + 7
        for l, r, k, v in queries:
            arr[l : r + 1 : k] = (arr[l : r + 1 : k] * v) % mod
        return int(np.bitwise_xor.reduce(arr))


if __name__ == "__main__":
    obj = Solution()
    print(obj.xorAfterQueries(nums=[1, 1, 1], queries=[[0, 2, 1, 4]]))
    print(
        obj.xorAfterQueries(nums=[2, 3, 1, 5, 4], queries=[[1, 4, 2, 3], [0, 2, 1, 2]])
    )
