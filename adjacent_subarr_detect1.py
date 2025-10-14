# 3349. Adjacent Increasing Subarrays Detection I

"""
given an array 'nums' of 'n' integers and an integer 'k', determine whther
there exist two adjacent subarrays of length 'k' such that both subarrays are
strictly increasing. specifically, check if there are two subarrays starting
at indices 'a' and 'b' ('a < b') where both subarrays 'nums[a..a + k - 1]'
and 'nums[b..b + k - 1]' are strictly increasing, and the subarrays must be
adjacent, meaning 'b = a + k'. return true if it is possible to find two such
subarrays and 'false'  otherwise.
"""


class Solution(object):
    def hasIncreasingSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        inc, prev, max_len = 1, 0, 0
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                inc += 1
            else:
                prev = inc
                inc = 1
            max_len = max(max_len, max(inc >> 1, min(prev, inc)))
            if max_len >= k:
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasIncreasingSubarrays(nums=[2, 5, 7, 8, 9, 2, 3, 4, 3, 1], k=3))
    print(obj.hasIncreasingSubarrays(nums=[1, 2, 3, 4, 4, 4, 4, 5, 6, 7], k=5))
