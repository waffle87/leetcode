# 2593. Find Score of an Array After Marking All Elements

"""
given an array 'nums' consisting of positive integers. starting with 'score =
0', apply the following algorithm
- choose the smallest integer of the array that is not marked. if there is a
tie, choose the one with the smallest index
- add the value of the chosen integer to 'score'
- mark the chosen element and its two adjacent elements if they exist
- repeat until all the array elements are marked
return the score you get after applying the above algorithm
"""


class Solution(object):
    def findScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seen, ans = [0] * (len(nums) + 1), 0
        for i, j in sorted([i, j] for j, i in enumerate(nums)):
            if seen[j]:
                continue
            ans += i
            seen[j] = seen[j - 1] = seen[j + 1] = 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findScore(nums=[2, 1, 3, 4, 5, 2]))
    print(obj.findScore(nums=[2, 3, 5, 1, 3, 2]))
