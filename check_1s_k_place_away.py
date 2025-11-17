# 1437. Check If All 1's Are at Least Length K Places Away

"""
given a binary array 'nums' and an integer 'k', return true if all 1s are at
least 'k' places away from eachother, otherwise return false.
"""


class Solution(object):
    def kLengthApart(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        prev = None
        for i, j in enumerate(nums):
            if j == 1:
                if prev is not None and i - prev <= k:
                    return False
                prev = i
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.kLengthApart(nums=[1, 0, 0, 0, 1, 0, 0, 1], k=2))
    print(obj.kLengthApart(nums=[1, 0, 0, 1, 0, 1], k=2))
