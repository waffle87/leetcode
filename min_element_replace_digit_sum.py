# 3300. Minimum Element After Replacement With Digit Sum

"""
you are given an integer array 'nums'. you replace each element in 'nums'
with the sum of its digits. return the minimum element in 'nums' after all
replacements.
"""


class Solution:
    def minElement(self, nums: List[int]) -> int:
        d = lambda n: sum(int(i) for i in str(n))
        return min(map(d, nums))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minElement(nums=[10, 12, 13, 14]))
    print(obj.minElement(nums=[1, 2, 3, 4]))
    print(obj.minElement(nums=[999, 19, 199]))
