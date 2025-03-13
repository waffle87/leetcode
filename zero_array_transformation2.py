# 3356. Zero Array Transformation II

"""
you are given an integer array 'nums' of length 'n' and a 2d array 'queries'
where 'queries[i] [l_i, r_i, val_i]'. each 'queries[i]' represents the
following action on 'nums': decrement the value at each index in the range
'[l_i, r_i]' in 'nums' by at most 'val_i'. the amount by which each value is
decremented can be chosen independently for each index. a zero array is an
array with all its elements equal to 0. return the minimum possible
non-negative value of 'k', such that after processing the first 'k' queries
in sequence, 'nums' becomes a zero array. if no such 'k' exists, return -1.
"""


class Solution(object):
    def minZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        n, ans, k = len(nums), 0, 0
        cnt = [0 for _ in range(n + 1)]
        for i in range(n):
            while k + cnt[i] < nums[i]:
                ans += 1
                if ans - 1 >= len(queries):
                    return -1
                l, r, val = queries[ans - 1]
                if r < i:
                    continue
                cnt[max(l, i)] += val
                cnt[r + 1] -= val
            k += cnt[i]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minZeroArray(nums=[2, 0, 2], queries=[[0, 2, 1], [0, 2, 1], [1, 1, 3]]))
    print(obj.minZeroArray(nums=[4, 3, 2, 1], queries=[[1, 3, 2], [0, 2, 1]]))
