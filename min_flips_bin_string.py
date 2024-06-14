# 1888. Minimum Number of Flips to Make the Binary String Alternating

"""
you are given a binary string 's'. you are allowed to perform two types of
operations on the string in any sequence: 1: remove the character at the
start of the string 's' and append it to the end of the string. 2: pick any
characters in 's' and flip its value, ie. if its value is 0 it becomes 1 and
vice versa. return the minimum number of type-2 operations needed to perform
such that 's' becomes alternating. the string is called alternating if no two
adjacent characters are equal. for example, the strings "010" and "1010" are
alternating, while the string "0110" is not.
"""


class Solution(object):
    def minFlips(self, s):
        n = len(s)
        k = len(s)
        s = s if k % 2 == 0 else s + s
        arr1, arr2 = [], []
        for i in range(n):
            arr1.append("0" if i % 2 == 0 else "1")
            arr2.append("1" if i % 2 == 0 else "0")
        alt1 = "".join(arr1)
        alt2 = "".join(arr2)
        diff1, diff2 = 0, 0
        i, j = 0, 0
        while j < n:
            if s[j] != alt1[j]:
                diff1 += 1
            if s[j] != alt2[j]:
                diff2 += 1
            if j - i + 1 < k:
                j += 1
            else:
                n = min(n, diff1, diff2)
                if s[i] != alt1[i]:
                    diff1 -= 1
                if s[i] != alt2[i]:
                    diff2 -= 1
                i += 1
                j += 1
        return n


if __name__ == "__main__":
    obj = Solution()
    print(obj.minFlips("111000"))  # expect: 2
    print(obj.minFlips("010"))  # expect: 0
    print(obj.minFlips("1110"))  # expect: 1
