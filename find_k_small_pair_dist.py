# 719. Find K-th Smallest Pair Distance

"""
the distance of a pair of integers 'a' and 'b' is defined as the absolute
different between 'a' and 'b'. given an integer array 'nums' and an integer
'k', return the smallest k'th distance among all the pairs 'nums[i]' and
'nums[j]' where '0 <= i < j < nums.len'.
"""


class Solution(object):
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        def enough(dist):
            cnt, i, j = 0, 0, 0
            while i < n or j < n:
                while j < n and nums[j] - nums[i] <= dist:
                    j += 1
                cnt += j - i - 1
                i += 1
            return cnt >= k

        nums.sort()
        n = len(nums)
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = left + (right - left) // 2
            if not enough(mid):
                left = mid + 1
            else:
                left = mid
        return left


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestDistancePair(nums=[1, 3, 1], k=1))
    print(obj.smallestDistancePair(nums=[1, 1, 1], k=2))
    print(obj.smallestDistancePair(nums=[1, 6, 1], k=3))
