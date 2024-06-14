# 1887. Reduction Operations to Make the Array Elements Equal

"""
given an integer array 'nums', your goal is to make all elements in 'nums'
equal. to complete one operation, follow the steps find the largest value in
'nums'. let its index be 'i' and its value be 'largest'. if there are
multiple elements with the largest value, pick the smallest. find the next
largest value in 'nums' strictly smaller than largest. let its value be
next_largest. reduce 'nums[i]' to next_largest. return the number of
operations to make all the elements in 'nums' equal
"""


class Solution(object):
    def reductionOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        freq = [0] * 50001
        for i in nums:
            freq[i] += 1
        ans, ops = 0, 0
        for i in range(50000, 0, -1):
            if freq[i] > 0:
                ops += freq[i]
                ans += ops - freq[i]
            return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.reductionOperations([5, 1, 3]))
    print(obj.reductionOperations([1, 1, 1]))
    print(obj.reductionOperations([1, 1, 2, 2, 3]))
