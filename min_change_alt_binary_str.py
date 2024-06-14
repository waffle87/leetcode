# 1758. Minimum Changes To Make Alternating Binary String

"""
given a string 's' consisting only of the characters '0' and '1', in one
operation, you can change any '0' to '1' or vice versa. the string is called
alternating if no two adjacent characters are equal. for example the string
"010" is alternating, while the string "0100" is not. return the minimum
number of operations needed to make 's' alternating.
"""


class Solution(object):
    def count(self, s, pre):
        cnt = 0
        for i in range(1, len(s)):
            curr = s[i]
            if curr == pre:
                cnt += 1
                pre = "0" if pre == "1" else "1"
            else:
                pre = curr
        return cnt

    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        c0 = s[0]
        cnt1 = self.count(s, c0)
        cnt2 = self.count(s, "0" if c0 == "1" else "1") + 1
        return min(cnt1, cnt2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations("0100"))  # expect: 1
    print(obj.minOperations("10"))  # expect: 0
    print(obj.minOperations("1111"))  # expect: 2
