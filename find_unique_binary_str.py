# 1980. Find Unique Binary String
from typing import List

"""
given an array of strings 'nums' containing 'n' unique binary strings each of
length 'n', return a binary string of length 'n' that does not appear in
'nums'. if there are multiple answers, you may return any of them.
"""


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        return "".join(["1" if n[i] == "0" else "0" for i, n in enumerate(nums)])


if __name__ == "__main__":
    obj = Solution()
    print(obj.findDifferentBinaryString(nums=["01", "10"]))
    print(obj.findDifferentBinaryString(nums=["00", "01"]))
    print(obj.findDifferentBinaryString(nums=["111", "011", "001"]))
