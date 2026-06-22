# 1189. Maximum Number of Balloons
from collections import Counter

"""
given a string 'text', you want to use the characters of 'text' to form as
many instances of the word "balloon" as possible. you can use each character
in 'text' at most once. return the maximum number of instances that can be
formed.
"""


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = Counter(text)
        return min(freq["b"], freq["a"], freq["l"] >> 1, freq["o"] >> 1, freq["n"])


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxNumberOfBalloons(text="nlaebolko"))
    print(obj.maxNumberOfBalloons(text="loonbalxballpoon"))
    print(obj.maxNumberOfBalloons(text="leetcode"))
