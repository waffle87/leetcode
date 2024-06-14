# 1239. Maximum Length of a Concatenated String with Unique Characters

"""
given an array of strings 'arr'. a string 's' is formed by the concatenation
of subsequence of 'arr', that has unique characters. return the maximum
possible length of 's'. a subsequence is an array that can be derived from
another array by deleting some or no elements without changing the order of
the remaining elements.
"""


class Solution(object):
    def maxLength(self, arr):
        """
        :type arr: List[str]
        :rtype: int
        """
        dp = [set()]
        for i in arr:
            if len(set(i)) < len(i):
                continue
            i = set(i)
            for c in dp[:]:
                if i & c:
                    continue
                dp.append(i | c)
        return max(len(i) for i in dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxLength(arr=["un", "iq", "ue"]))
    print(obj.maxLength(arr=["cha", "r", "act", "ers"]))
    print(obj.maxLength(arr=["abcdefghijklmnopqrstuvwxyz"]))
