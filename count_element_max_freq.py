# 3005. Count Elements With Maximum Frequency

"""
given an array 'nums' consisting of positive integers. return the total
frequencies of elements in 'nums' such that those elements all have the
maximum frequency. the frequency of an element is the number of occurences of
that in the array
"""


class Solution(object):
    def maxFrequencyElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        u_map = {}
        for i in nums:
            u_map[i] = u_map.get(i, 0) + 1
        max_i = 0
        for key, val in u_map.items():
            max_i = max(max_i, val)
        ans = 0
        for key, val in u_map.items():
            if val == max_i:
                ans += val
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFrequencyElements([1, 2, 2, 3, 1, 4]))
    print(obj.maxFrequencyElements([1, 2, 3, 4, 5]))
