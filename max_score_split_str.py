# 1422. Maximum Score After Splitting a String

"""
given a string 's' of zeros and ones, return the maximum score after
splitting the string into two non-empty substrings (ie. left and right). the
score after splitting a string is the number of zeros in the left substring
plus the number of ones in the right substring.
"""


class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_score = prefix_zero = 0
        suffix_one = s.count("1")
        for i in range(len(s) - 1):
            prefix_zero += s[i] == "0"
            suffix_one -= s[i] == "1"
            max_score = max(max_score, prefix_zero + suffix_one)

        return max_score


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxScore("011101"))
    print(obj.maxScore("00111"))
    print(obj.maxScore("1111"))
