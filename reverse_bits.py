# 190. Reverse Bits

"""
reverse the bitof a given 32 bits unsigned integer.
"""


class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        ans = 0
        for _ in range(32):
            ans = (ans << 1) + (n & 1)
            n >>= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    r1 = obj.reverseBits(0b00000010100101000001111010011100)
    r2 = obj.reverseBits(0b11111111111111111111111111111101)
    print(r1, "(", bin(r1), ")")
    print(r2, "(", bin(r2), ")")
