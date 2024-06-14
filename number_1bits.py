# 191. Number of 1 Bits

"""
write a function that takes the binary representation of an unsigned integer
and returns number of '1' bits (also known as hamming weight). note that in
some languages, such as java, there is no unsigned integer type. in this
case, the input will be given as a signed integer type. it should not affect
your implementation as the integers binary representation is the same, wehter
it is signed or unsigned. in java, the compiler represents the signed
integers using 2's complement notation. therefore in example 3, the input
represents the signed integer -3
"""

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        while n:
            n &= (n - 1)
            cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solutin()
    print(obj.hammingWeight(00000000000000000000000000001011)) # expect: 3
    print(obj.hammingWeight(00000000000000000000000010000000)) # expect: 1
    print(obj.hammingWeight(11111111111111111111111111111101)) # expect: 31
