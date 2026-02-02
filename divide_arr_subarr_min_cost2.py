# 3013. Divide an Array Into Subarrays With Minimum Cost II
import bisect

"""
you are given a 0 indexed array of integers 'nums' of length 'n', and two
positive integers 'k' and 'dist'. the cost of an array is the value of its
first element. for example, the cost of '1,2,3' is 1. you need to divide 'nums'
into 'k' disjoint contiguous subarrays, such that the difference between the
starting index of the second subarray and the starting index of the k'th
subarray should be less than or equal to 'dist'. in other words, if you divide
'nums' into the subarrays, then 'i_k-1 - i_1 <= dist'. return the minimum
possible sum of the cost of these subarrays.
"""


class Solution(object):
    class smart_window:
        def __init__(self, k):
            self.k = k
            self.low = []
            self.high = []
            self.sumLow = 0

        def window_size(self):
            return len(self.low) + len(self.high)

        def erase_one(self, arr, x):
            i = bisect.bisect_left(arr, x)
            if i < len(arr) and arr[i] == x:
                arr.pop(i)
                return True
            return False

        def rebalance(self):
            need = min(self.k, self.window_size())
            while len(self.low) > need:
                x = self.low.pop()
                self.sumLow -= x
                bisect.insort(self.high, x)
            while len(self.low) < need and self.high:
                x = self.high.pop(0)
                bisect.insort(self.low, x)
                self.sumLow += x

        def add(self, x):
            if not self.low or x <= self.low[-1]:
                bisect.insort(self.low, x)
                self.sumLow += x
            else:
                bisect.insort(self.high, x)
            self.rebalance()

        def remove(self, x):
            if self.erase_one(self.low, x):
                self.sumLow -= x
            else:
                self.erase_one(self.high, x)
            self.rebalance()

        def query(self):
            return self.sumLow

    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        :type k: int
        :type dist: int
        :rtype: int
        """
        n = len(nums)
        k -= 1
        window = self.smart_window(k)
        for i in range(1, 1 + dist + 1):
            window.add(nums[i])
        ans = window.query()
        for i in range(2, n - dist):
            window.remove(nums[i - 1])
            window.add(nums[i + dist])
            ans = min(ans, window.query())
        return ans + nums[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumCost(nums=[1, 3, 2, 6, 4, 2], k=3, dist=3))
    print(obj.minimumCost(nums=[10, 1, 2, 2, 2, 1], k=4, dist=3))
    print(obj.minimumCost(nums=[10, 8, 18, 9], k=3, dist=1))
