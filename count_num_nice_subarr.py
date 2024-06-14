# 1248. Count Number of Nice Subarrays

"""
given an array of integers 'nums' and an integers 'k'. a continuous subarray
is called nice if there are 'k' odd numbers on it. return the number of nice
subarrays.
"""


class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        i, cnt, ans = 0, 0, 0
        for j in range(len(nums)):
            if nums[j] & 1:
                k -= 1
                cnt = 0
            while k == 0:
                k += nums[i] & 1
                i += 1
                cnt += 1
            ans += cnt
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSubarrays(nums=[1, 1, 2, 1, 1], k=3))
    print(obj.numberOfSubarrays(nums=[2, 4, 6], k=1))
    print(obj.numberOfSubarrays(nums=[2, 2, 2, 1, 2, 2, 1, 2, 2, 2], k=2))
