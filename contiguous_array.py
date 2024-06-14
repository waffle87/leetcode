# 525. Contiguous Array

"""
given a binary array 'nums' return the maximum length of a contiguous
subarray with an equal number of 0 and 1.
"""


class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, max_length = 0, 0
        table = {0: 0}
        for idx, n in enumerate(nums, 1):
            if n == 0:
                cnt -= 1
            else:
                cnt += 1
            if cnt in table:
                max_length = max(max_length, idx - table[cnt])
            else:
                table[cnt] = idx
        return max_length


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaxLength([0, 1]))
    print(obj.findMaxLength([0, 1, 0]))
