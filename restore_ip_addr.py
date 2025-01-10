# 93. Restore IP Addresses

"""
a valid ip address consists of exactly 4 integers separated by single dots
each integer is between 0 and 255 (inclusive) and cannot have leading 0's
given: string 's' containing only digits, return all possible valid ip
addresses that can be formed by insert dots into 's'. digits cannot be
reordered or removed. return addresses in any order.
"""


class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        for a in range(1, 4):
            for b in range(1, 4):
                for c in range(1, 4):
                    d = len(s) - a - b - c
                    if (
                        1 <= d <= 3
                        and (1 == a or "0" != s[0])
                        and (a != 3 or s[:a] <= "255")
                        and (1 == b or "0" != s[a])
                        and (b != 3 or s[a : a + b] <= "255")
                        and (1 == c or "0" != s[a + b])
                        and (c != 3 or s[a + b : a + b + c] <= "255")
                        and (1 == d or "0" != s[a + b + c])
                        and (d != 3 or s[a + b + c :] <= "255")
                    ):
                        ans.append(
                            ".".join(
                                [
                                    s[0:a],
                                    s[a : a + b],
                                    s[a + b : a + b + c],
                                    s[a + b + c :],
                                ]
                            )
                        )
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.restoreIpAddresses(s="25525511135"))
    print(obj.restoreIpAddresses(s="0000"))
    print(obj.restoreIpAddresses(s="101023"))
