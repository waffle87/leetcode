# 1784. Check if Binary String Has at Most One Segment of Ones

"""
given a binary string 's' without leading zeros, return 'true' if 's'
contains at most one contiguous segment of ones. otherwise, return false.
"""


class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return "01" not in s


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkOnesSegment(s="1001"))
    print(obj.checkOnesSegment(s="110"))
