# 1980. Find Unique Binary String

"""
given an array of strings 'nums' containing 'n' unique binary strings each of
length 'n', return a binary string of length 'n' that does not appear in
'nums'. if there are multiple answers, you may return any of them.
"""


class Solution(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        s = set([int(i, 2) for i in nums])
        max_len = len(nums[0])
        for i in range(pow(2, max_len)):
            if i not in s:
                r = bin(i)[2:]
                return "0" * (max_len - len(r)) + r
        return "-1"


if __name__ == "__main__":
    obj = Solution()
    print(obj.findDifferentBinaryString(["01", "10"]))  # expect: 11
    print(obj.findDifferentBinaryString(["00", "01"]))  # expect: 11
    print(obj.findDifferentBinaryString(["111", "011", "001"]))  # expect: 101
