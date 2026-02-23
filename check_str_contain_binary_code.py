# 1461. Check If a String Contains All Binary Codes of Size K

"""
given a binary string 's', and an integer 'k', return true if every binary
code of length 'k' is a substring of 's', otherwise return 'false'.
"""


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        return len({s[i - k : i] for i in range(k, len(s) + 1)}) == 1 << k


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasAllCodes(s="00110110", k=2))
    print(obj.hasAllCodes(s="0110", k=1))
    print(obj.hasAllCodes(s="0110", k=2))
