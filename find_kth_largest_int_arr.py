# 1985. Find the Kth Largest Integer in the Array
import heapq

"""
you are given an array of strings 'nums' and an integer 'k'. each string in
'nums' represents an integer without leading zeros. return the string that
represents the k'th largest integer in 'nums'. duplicate numbers should be
counted distinctly.
"""


class Solution(object):
    def kthLargestNumber(self, nums, k):
        """
        :type nums: List[str]
        :type k: int
        :rtype: str
        """
        max_heap = [-int(x) for x in nums]
        heapq.heapify(max_heap)
        while k > 1:
            heapq.heappop(max_heap)
            k -= 1
        return str(-max_heap[0])


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthLargestNumber(nums=["3", "6", "7", "10"], k=4))
    print(obj.kthLargestNumber(nums=["2", "21", "12", "1"], k=3))
    print(obj.kthLargestNumber(nums=["0", "0"], k=2))
