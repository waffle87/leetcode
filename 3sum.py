# 15. 3Sum

"""
given an integer array 'nums', return all the triplets '[nums[i], nums[j],
nums[k]]' such that 'i != j', 'i != k', 'j != k', and 'nums[i] + nums[j] +
nums[k] == 0'. notice that the solution set must not contain duplicate
triplets
"""


class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        ans = []
        if len(nums) < 3:
            return ans
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, len(nums) - 1
            while j < k:
                total_sum = nums[i] + nums[j] + nums[k]
                if total_sum > 0:
                    k -= 1
                elif total_sum < 0:
                    j += 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    prev_j, prev_k = nums[j], nums[k]
                    while j < k and nums[j] == prev_j:
                        j += 1
                    while j < k and nums[k] == prev_k:
                        k -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.threeSum(nums=[-1, 0, 1, 2, -1, -4]))
    print(obj.threeSum(nums=[0, 1, 1]))
    print(obj.threeSum(nums=[0, 0, 0]))
