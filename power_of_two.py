# 231. Power of Two

"""
given an integer 'n', return true if it is a power of two. otherwise, return
false. an integer 'n' is a power of two if there exists an integer 'x' such
that 'n == 2^x'
"""


class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        return not (n & (n - 1))
       
if __name__ == "__main__":
    obj = Solution()
    print(obj.isPowerOfTwo(1))
    print(obj.isPowerOfTwo(16))
    print(obj.isPowerOfTwo(3))
