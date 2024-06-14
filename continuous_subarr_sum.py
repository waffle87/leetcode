# 523. Continuous Subarray Sum


class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic, sum = {0: -1}, 0
        for i, n in enumerate(nums):
            if k != 0:
                sum = (sum + n) % k
            else:
                sum += n
            if sum not in dic:
                dic[sum] = i
            else:
                if i - dic[sum] >= 2:
                    return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkSubarraySum(nums=[23, 2, 4, 6, 7], k=6))
    print(obj.checkSubarraySum(nums=[23, 2, 6, 4, 7], k=6))
    print(obj.checkSubarraySum(nums=[23, 2, 6, 4, 7], k=13))
