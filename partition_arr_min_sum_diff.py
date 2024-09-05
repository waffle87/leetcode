# 2035. Partition Array Into Two Arrays to Minimize Sum Difference
from bisect import bisect_left
from itertools import combinations

"""
you are given an integer array 'nums' of '2  n' integers. you need to
partition 'nums' into two arrays of length 'n' to minimise the abresute
difference of sums of the arrays. to partition 'nums', put each element of
'nums' into one of the two arrays. return the minimum possible abresute
difference
"""


class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        def get_sums(nums):
            res = {}
            for k in range(1, n + 1):
                sums = []
                for c in combinations(nums, k):
                    s = sum(c)
                    sums.append(s)
                res[k] = sums
            return res

        left_part, right_part = nums[:n], nums[n:]
        left_sums, right_sums = get_sums(left_part), get_sums(right_part)
        ans = abs(sum(left_part) - sum(right_part))
        total = sum(nums)
        half = total // 2
        for i in range(1, n):
            left, right = left_sums[i], right_sums[n - i]
            right.sort()
            for j in left:
                r = half - j
                p = bisect_left(right, r)
                for k in [p, p - 1]:
                    if 0 <= k < len(right):
                        left_ans_sum = j + right[k]
                        right_ans_sum = total - left_ans_sum
                        diff = abs(left_ans_sum - right_ans_sum)
                        ans = min(ans, diff)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDifference(nums=[3, 9, 7, 3]))
    print(obj.minimumDifference(nums=[-36, 36]))
    print(obj.minimumDifference(nums=[2, -1, 0, 4, -2, -9]))
