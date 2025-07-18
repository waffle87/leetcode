# 2163. Minimum Difference in Sums After Removal of Elements
import heapq

"""
you are given a 0-indexed integer array 'nums' consisting of '3 * n'
elements. you are allowed to remove any subsequence ofd elements of size
exactly 'n' from 'nums'. the remaining '2 * n' elements will be divided into
two equal parts: the first 'n' elements belonging to the first part and their
sum is 'sum_first', and the next 'n' elements belonging to the second part
and their sum is 'sum_second'. the difference in sums of  the two parts is
denoted as 'sum_first - sum_second'. return the minimum different possible
between the sums of the two parts after the removal of 'n' elements.
"""


class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums) // 3
        diff = [0] * (n + 1)
        heapq.heapify(pq_l := [-i for i in nums[:n]])
        heapq.heapify(pq_r := nums[2 * n :])
        total = sum(nums[:n])
        ans = total
        for i in range(n, 2 * n + 1):
            diff[i - n] = total
            curr = nums[i]
            if curr >= -pq_l[0]:
                continue
            total += curr + pq_l[0]
            heapq.heapreplace(pq_l, -curr)
        total = sum(nums[2 * n :])
        ans -= total
        for i in range(2 * n - 1, n - 2, -1):
            diff[i - n + 1] -= total
            ans = min(ans, diff[i - n + 1])
            curr = nums[i]
            if curr <= pq_r[0]:
                continue
            total += curr - pq_r[0]
            heapq.heapreplace(pq_r, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDifference(nums=[3, 1, 2]))
    print(obj.minimumDifference(nums=[7, 9, 5, 8, 1, 3]))
