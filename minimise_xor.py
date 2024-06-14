# 2429. Minimize XOR

"""
given two positive integers 'num1' and 'num2', find the positive integer 'x'
such that 'x' has the same number of set bits as 'num2', and the value 'x ^
num1' is minimal. note that 'xor' is the bitwise xor operator. return the
integer 'x'. the test cases are generated such that 'x' is uniqueley
determined. the number of set bits of an integer is the number of 1's in its
binary representation
"""

class Solution(object):
    def minimizeXor(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        a, b = num1.bit_count(), num2.bit_count()
        ans = num1
        for i in range(32):
            if a > b and (1 << i) & num1 > 0:
                ans ^= 1 << i
                a -= 1
            if a < b and (1 << i) & num1 == 0:
                ans ^= 1 << i
                a += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimizeXor(3, 5)) # expect: 3
    print(obj.minimizeXor(1, 12)) # expect: 3
    
