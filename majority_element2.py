# 229. Majority Element II

"""
given an integer array of size 'n', find all elements that appear more than n
/ 3 times (floored)
"""


class Solution(object):
    def majorityElement(self, nums):
        if not nums:
            return []
        cnt1, cnt2, cdd1, cdd2 = 0, 0, 0, 1
        for n in nums:
            if n == cdd1:
                cnt1 += 1
            elif n == cdd2:
                cnt2 += 1
            elif cnt1 == 0:
                cdd1, cnt1 = n, 1
            elif cnt2 == 0:
                cdd2, cnt2 = n, 1
            else:
                cnt1, cnt2 = cnt1 - 1, cnt2 - 1
        return [n for n in (cdd1, cdd2) if nums.count(n) > len(nums) // 3]


if __name__ == "__main__":
    obj = Solution()
    print(obj.majorityElement([3, 2, 3]))  # expect: 3
    print(obj.majorityElement([1]))  # expect: 1
    print(obj.majorityElement([1, 2]))  # expect: 1 2
