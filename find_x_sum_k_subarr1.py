# 3318. Find X-Sum of All K-Long Subarrays I
from collections import Counter

"""
you are given an array 'nums' of 'n' integers and two integers 'k' and 'x'.
the x-sum of an array is calcluated by the follow procedure: count the
occurences of all elements in the array, keep only the occurences of the top
'x' most frequent elements. if two elements have the same number of
occurences, the element with the bigger value is considered more frequent.
calcluate the sum of the resulting array. note tht if an array has less than
'x' distinct eleents, its x-sum is the sum of the array. return an integer
array 'ans' of length 'n - k + 1' where 'ans[i]' is the x-sum of the subarray
'nums[i .. i + k - 1]'
"""


class Solution(object):
    def findXSum(self, nums, k, x):
        """
        :type nums: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        n, ans = len(nums), []
        for i in range(n - k + 1):
            window = nums[i : i + k]
            freq = Counter(window)
            sort_freq = sorted(freq.items(), key=lambda x: (-x[1], -x[0]))
            top_x = set(i for i, _ in sort_freq[:x])
            x_sum = sum(i for i in window if i in top_x)
            ans.append(x_sum)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findXSum(nums=[1, 1, 2, 2, 3, 4, 2, 3], k=6, x=2))
    print(obj.findXSum(nums=[3, 8, 7, 8, 7, 5], k=2, x=2))
