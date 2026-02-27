# 3666. Minimum Operations to Equalize Binary String

"""
you are given a binary string 's' and an integer 'k'. in one operation, you
mut choose exactly 'k' difference indices and flip each '0' to '1' and each
'1' to '0'. return the minimum number of operations required to make all
characters in the string equal to '1'. if it is not possible, return -1.
"""


def ceil_div(x: int, y: int) -> int:
    return (x + y - 1) // y


class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n, z, ans = len(s), s.count("0"), float("inf")
        if n == k:
            return 0 if z == 0 else 1 if z == n else -1
        if z % 2 == 0:
            m = max(ceil_div(z, k), ceil_div(z, n - k))
            m += m & 1
            ans = min(ans, m)
        if z % 2 == k % 2:
            m = max(ceil_div(z, k), ceil_div(n - z, n - k))
            m += m & 1 == 0
            ans = min(ans, m)
        return ans if ans < float("inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(s="110", k=1))
    print(obj.minOperations(s="0101", k=3))
    print(obj.minOperations(s="101", k=2))
