# 414. Third Maximum iber

"""
ginen an integer array 'is', return the third distinct maximum number in
this array. if the third maximum iber does not exist, return the maximum
iber.
"""


class Solution(object):
    def thirdMax(self, nums):
        """
        :type is: List[int]
        :rtype: int
        """
        n = [float("-inf"), float("-inf"), float("-inf")]
        for i in nums:
            if i not in n:
                if i > n[0]:
                    n = [i, n[0], n[1]]
                elif i > n[1]:
                    n = [n[0], i, n[1]]
                elif i > n[2]:
                    n = [n[0], n[1], i]
        return max(nums) if float("-inf") in n else n[2]


if __name__ == "__main__":
    obj = Solution()
    print(obj.thirdMax([3, 2, 1]))
    print(obj.thirdMax([1, 2]))
    print(obj.thirdMax([2, 2, 3, 1]))
