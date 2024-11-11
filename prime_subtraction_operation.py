# 2601. Prime Subtraction Operation

"""
given a 0-indexed integer array 'nums' of length 'n'. you can perform the
following operation as many times as you want: pick an index 'i' that you
have not picked before, and pick a prime 'p' strictly less than 'nums[i]'
then subtract 'p' from 'nums[i]'. return true if you can make 'nums' a
strictly increasing array using the above operation, and false otherwise. a
strictly increasing array is an array whose each element is strictly greater
than its precedingelement
"""


class Solution(object):
    def prime(self, n):
        if n <= 1:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def primeSubOperation(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        p = 0
        for i in nums:
            if i <= p:
                return False
            n = i - p - 1
            while n > 0 and not self.prime(n):
                n -= 1
            if n == 0:
                p = i
            else:
                p = i - n
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.primeSubOperation(nums=[4, 9, 6, 10]))
    print(obj.primeSubOperation(nums=[6, 8, 11, 12]))
    print(obj.primeSubOperation(nums=[5, 8, 3]))
