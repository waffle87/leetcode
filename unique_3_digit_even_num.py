# 3483. Unique 3-Digit Even Numbers
from collections import Counter

"""
you are given an array of digits called 'digits'. your task is to determine
the number of distinct three digit even numbers that can be formed using
these digits. note: each copy of a digit can only be used once per number,
and there may not be leading zeros.
"""


class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = Counter(digits)
        ans = 0
        for i in range(100, 1000, 2):
            ans += Counter(map(int, str(i))) <= freq
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.totalNumbers(digits=[1, 2, 3, 4]))
    print(obj.totalNumbers(digits=[0, 2, 2]))
    print(obj.totalNumbers(digits=[6, 6, 6]))
    print(obj.totalNumbers(digits=[1, 3, 5]))
