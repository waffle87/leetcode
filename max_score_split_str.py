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
        ans, zeros, ones = 0, 0, s.count("1")
        for i in range(len(s) - 1):
            if s[i] == "1":
                ones -= 1
            else:
                zeros += 1
            ans = max(ans, zeros + ones)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxScore("011101"))
    print(obj.maxScore("00111"))
    print(obj.maxScore("1111"))
