# 1963. Minimum Number of Swaps to Make the String Balanced

"""
you are given a 0-indexed string 's' of even length 'n'. the string consists
of exactly 'n / 2' opening and closing square brackets. a string is called
balanced if and only if it is empty string, it can be written as 'AB' where
both 'A' and 'B' are balanced strings, or it can be written as '[C]' where
'C' is a balanced string. you may swap the brackets at any two indices any
number of times. return the minimum number of swaps to make 's' balanced
"""


class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        bal, ans = 0, 0
        for c in s:
            if c == "[":
                bal += 1
            else:
                bal -= 1
            ans = min(ans, bal)
        return (-ans + 1) // 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSwaps(s="][]["))
    print(obj.minSwaps(s="]]][[["))
    print(obj.minSwaps(s="[]"))
