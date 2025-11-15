# 3234. Count the Number of Substrings With Dominant Ones

"""
you are given a binary string 's'. return the number of substrings with
dominant ones. a string has dominant ones if the number of ones in the string
is greater than or equal to the sqaure of the number of zeroes in the string.
"""


class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, ans = len(s), 0
        pre = [-1] * (n + 1)
        for i in range(n):
            if i == 0 or s[i - 1] == "0":
                pre[i + 1] = i
            else:
                pre[i + 1] = pre[i]
        for i in range(1, n + 1):
            cnt0, j = 1 if s[i - 1] == "0" else 0, i
            while j > 0 and cnt0 * cnt0 <= n:
                cnt1 = (i - pre[j]) - cnt0
                if cnt0 * cnt0 <= cnt1:
                    ans += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1)
                j = pre[j]
                cnt0 += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSubstrings(s="00011"))
    print(obj.numberOfSubstrings(s="101101"))
