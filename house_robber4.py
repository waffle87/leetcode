# 2560. House Robber IV

"""
there are several consecutive houses along a street, each of which has some
money inside. there is also a robber, who wants to steal money from the
homes, but he refuses to steal from adjacent homes. the capability of the
robber is the maximum amount of money he steals from one house of all the
houses he robbed. you are given an integer array 'nums' representing how much
money is stahsed in each house. more formally, the i'th house from the left
has 'nums[i]' dollars. you are also given an integer 'k', representing the
minimum number of houses the robber will steal from. it is always possible to
steal at least 'k' houses. return the minimum possible capability of the
robber out of all the possible ways to steal at least 'k' houses.
"""


class Solution(object):
    def minCapability(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left, right = min(nums), max(nums)
        while left < right:
            mid = (left + right) // 2
            prev, take = 0, False
            for i in nums:
                if prev:
                    prev = False
                    continue
                if i <= mid:
                    take += 1
                    prev = True
            if take >= k:
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCapability(nums=[2, 3, 5, 9], k=2))
    print(obj.minCapability(nums=[2, 7, 9, 3, 1], k=2))
