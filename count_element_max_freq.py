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
        freq = [0] * 101
        max_freq, ans = 0, 0
        for i in nums:
            freq[i] += 1
            max_freq = max(max_freq, freq[i])
        for i in freq:
            if i == max_freq:
                ans += i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFrequencyElements([1, 2, 2, 3, 1, 4]))
    print(obj.maxFrequencyElements([1, 2, 3, 4, 5]))
