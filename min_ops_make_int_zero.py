# 2749. Minimum Operations to Make the Integer Zero

"""
you are given two integers 'nums1' and 'nums2'. in one operation you can
choose integer 'i' in the range '[0, 60]' and subtract '2^i + num2' from
'num1'. return the integer denoting the minimum number of operations needed
to make 'nums1' equal to 0. if it is impossible to make 'nums1' equal to 0,
return -1.
"""


class Solution(object):
    def bit_cnt(self, num):
        cnt = 0
        while num > 0:
            cnt += num & 1
            num >>= 1
        return cnt

    def makeTheIntegerZero(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        if num1 < num2:
            return -1
        for i in range(101):
            diff = num1 - 1 * num2 * i
            bits = self.bit_cnt(diff)
            if bits <= i and i <= diff:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.makeTheIntegerZero(num1=3, num2=-2))
    print(obj.makeTheIntegerZero(num1=5, num2=7))
