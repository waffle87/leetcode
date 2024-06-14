# 377. Combination Sum IV

"""
given an array of disticint integers 'nums' and a target integer 'target',
return the number of possible combinations that add up to 'target'. the test
cases are generated such that the answer can fit in a 32 bit integer.
"""


class Solution(object):
    def combinationSum4(self, nums, target):
        nums.sort()
        memo = {}

        def helper(n):
            if n in memo:
                return memo[n]
            if n == 0:
                return 1
            if n < nums[0]:
                return 0
            cnt = 0
            for i in nums:
                if n - i < 0:
                    break
                cnt += helper(n - i)
            memo[n] = cnt
            return cnt

        return helper(target)


if __name__ == "__main__":
    obj = Solution()
    print(obj.combinationSum4([1, 2, 3], 4))  # expect: 7
    print(obj.combinationSum4([9], 3))  # expect: 0
