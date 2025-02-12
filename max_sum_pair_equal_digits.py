# 2342. Max Sum of a Pair With Equal Sum of Digits

"""
you are given a 0-indexed array 'nums' consisting of positive integers. you
can choose two indices 'i' and 'j', such that 'i != j', and the sum of the
digits of the number 'nums[i]' is equal to that of 'nums[j]'. return the
maximum value of 'nums[i] + nums[j]' that you can obtain over all
possible indices 'i' and 'j' that satisfy the conditions.
"""


class Solution(object):
    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        map, ans = [-1] * 82, -1
        for i in nums:
            digit_sum = sum(int(j) for j in str(i))
            if map[digit_sum] != -1:
                ans = max(ans, i + map[digit_sum])
            map[digit_sum] = max(map[digit_sum], i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumSum(nums=[18, 43, 36, 13, 7]))
    print(obj.maximumSum(nums=[10, 12, 19, 14]))
