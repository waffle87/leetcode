# 1726. Tuple with Same Product

"""
given an array 'nums' of distinct positive integers return the number of
tuples '(a,b,c,d)' such that 'a  b = c  d' where 'a,b,c,d' are elements of
'nums' and 'a != b != c != d'
"""


class Solution(object):
    def tupleSameProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, freq = 0, {}
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                key = nums[i] * nums[j]
                ans += freq.get(key, 0)
                freq[key] = 1 + freq.get(key, 0)
            return ans * 8


if __name__ == "__main__":
    obj = Solution()
    print(obj.tupleSameProduct(nums=[2, 3, 4, 6]))
    print(obj.tupleSameProduct(nums=[1, 2, 4, 5, 10]))
