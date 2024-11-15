# 1574. Shortest Subarray to be Removed to Make Array Sorted

"""
given an integer array 'arr', remove a subarray (can be empty) from 'arr'
such that the remaining elements in 'arr' are non-decreasing. return the
length of the shortest subarray to remove. a subarray is a contiguous
subsequence of the array.
"""


class Solution(object):
    def findLengthOfShortestSubarray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        left, right = 0, len(arr) - 1
        while left < right and arr[left + 1] >= arr[left]:
            left += 1
        if left == len(arr) - 1:
            return 0
        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
        ans = min(len(arr) - left - 1, right)
        for i in range(left + 1):
            if arr[i] <= arr[right]:
                ans = min(ans, right - i - 1)
            elif right < len(arr) - 1:
                right += 1
            else:
                break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findLengthOfShortestSubarray(arr=[1, 2, 3, 10, 4, 2, 3, 5]))
    print(obj.findLengthOfShortestSubarray(arr=[5, 4, 3, 2, 1]))
    print(obj.findLengthOfShortestSubarray(arr=[1, 2, 3]))
