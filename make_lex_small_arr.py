# 2948. Make Lexicographically Smallest Array by Swapping Elements

"""
you are given a 0-indexed array of positive integers 'nums' and a positive
integer 'limit'. in one operation, you can choose any two indices 'i' and 'j'
and swap 'nums[i]' and 'nums[j]' if '|nums[i] - nums[j]| <= limit'. return
the lexicographically smallest array that can be obtained by performingthe
operation any number of times.
"""


class Solution(object):
    def lexicographicallySmallestArray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: List[int]
        """
        n, indices = len(nums), []
        cpy, ans = sorted([(nums[i], i) for i in range(n)]), [0] * n
        for i in range(n):
            if i == 0 or cpy[i][0] - cpy[i - 1][0] > limit:
                indices.append([])
            indices[-1].append(cpy[i][1])
        for i in indices:
            curr = sorted(i)
            for j in range(len(i)):
                ans[curr[j]] = nums[i[j]]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.lexicographicallySmallestArray(nums=[1, 5, 3, 9, 8], limit=2))
    print(obj.lexicographicallySmallestArray(nums=[1, 7, 6, 18, 2, 1], limit=3))
    print(obj.lexicographicallySmallestArray(nums=[1, 7, 28, 19, 10], limit=3))
