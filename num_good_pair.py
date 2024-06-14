# 1512. Number of Good Pairs

"""
given an array of integers 'nums', return the number of good pairs. a pair
'(i, j)' is called good if 'nums[i] == nums[j]' and 'i < j'
"""

class Solution(object):
    def numIdenticalPairs(self, nums):
        cnt = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numIdenticalPairs([1,2,3,1,1,3])) # expect: 4
    print(obj.numIdenticalPairs([1,1,1,1])) # expect: 6
    print(obj.numIdenticalPairs([1,2,3])) # expect: 0
