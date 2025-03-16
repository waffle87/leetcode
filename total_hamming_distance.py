# 477. Total Hamming Distance

"""
the hamming distance between two integers is the number of positions at which
the corresponding bits are different. given an integer array 'nums', return
the sum of hamming distances between all the pairs of the integers in 'nums'.
"""


class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        bits = [[0, 0] for _ in range(32)]
        for i in nums:
            for j in bits:
                j[i % 2] += 1
                i /= 2
        return sum(x * y for x, y in bits)


if __name__ == "__main__":
    obj = Solution()
    print(obj.totalHammingDistance(nums=[4, 14, 2]))
    print(obj.totalHammingDistance(nums=[4, 14, 4]))
