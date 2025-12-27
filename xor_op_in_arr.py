# 1486. XOR Operation in an Array

"""
you are given an integer 'n' and an integer 'start'. define an array 'nums'
where 'nums[i] = star + 2  i' and 'n == nums.length'. return bitwise xor of
all elements of 'nums'.
"""


class Solution(object):
    def xorOperation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: int
        """
        ans = 0
        nums = [start + i * 2 for i in range(n)]
        for i in nums:
            ans ^= i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.xorOperation(n=5, start=0))
    print(obj.xorOperation(n=4, start=3))
