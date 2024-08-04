# 1508. Range Sum of Sorted Subarray Sums

"""
you are given the array 'nums' consisting of 'n' positive integers. you
computed the sum of all non empty continuous subarrays from the array and
then sorted them in non decreasing order, creating a new array of 'n  (n +
1) / 2' numbers. return the sum of the numbers from index 'left' to index
'right' inclusive, in the new array. since the answer may be very large,
return it modulo 1e9+7
"""


class Solution(object):
    def rangeSum(self, nums, n, left, right):
        """
        :type nums: List[int]
        :type n: int
        :type left: int
        :type right: int
        :rtype: int
        """
        b, c = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            b[i + 1] = b[i] + nums[i]
            c[i + 1] = c[i] + b[i + 1]

        def cnt_sum_und(score):
            res, i = 0, 0
            for j in range(n + 1):
                while b[j] - b[i] > score:
                    i += 1
                res += j - i
            return res

        def kth_score(k):
            l, r = 0, b[n]
            while l < r:
                m = (l + r) / 2
                if cnt_sum_und(m) < k:
                    l = m + 1
                else:
                    r = m
            return l

        def sum_k_sums(k):
            score = kth_score(k)
            res, i = 0, 0
            for j in range(n + 1):
                while b[j] - b[i] > score:
                    i += 1
                res += b[j] * (j - i + 1) - (c[j] - (c[i - 1] if i else 0))
            return res - (cnt_sum_und(score) - k) * score

        return sum_k_sums(right) - sum_k_sums(left - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.rangeSum(nums=[1, 2, 3, 4], n=4, left=1, right=5))
    print(obj.rangeSum(nums=[1, 2, 3, 4], n=4, left=3, right=4))
    print(obj.rangeSum(nums=[1, 2, 3, 4], n=4, left=1, right=10))
