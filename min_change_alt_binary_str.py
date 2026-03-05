# 1758. Minimum Changes To Make Alternating Binary String

"""
given a string 's' consisting only of the characters '0' and '1', in one
operation, you can change any '0' to '1' or vice versa. the string is called
alternating if no two adjacent characters are equal. for example the string
"010" is alternating, while the string "0100" is not. return the minimum
number of operations needed to make 's' alternating.
"""


class Solution:
    def minOperations(self, s: str) -> int:
        return min(
            cnt := sum((i & 1) == (ord(j) & 1) for i, j in enumerate(s)), len(s) - cnt
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations("0100"))  # expect: 1
    print(obj.minOperations("10"))  # expect: 0
    print(obj.minOperations("1111"))  # expect: 2
