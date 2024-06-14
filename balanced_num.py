# 2048. Next Greater Numerically Balanced Number
from collections import Counter

"""
an integer 'x' is numerically balanced if for every digit 'd' in the number
'x', there are exactly 'd' occurences of that digit in 'x'. given an integer
'n', return the smallest numerically balanced number strictly greater than
'n'
"""


class Solution(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """

        def backtracking(i, numLen, curNum, counter):
            if i == numLen:
                isBalanceNumber = True
                for d, freq in counter.items():
                    if freq != 0 and d != freq:
                        isBalanceNumber = False
                if isBalanceNumber:
                    yield curNum
                return

            for d in range(1, numLen + 1):
                if counter[d] >= d:
                    continue
                if counter[d] + (numLen - i) < d:
                    continue
                counter[d] += 1
                yield from backtracking(i + 1, numLen, curNum * 10 + d, counter)
                counter[d] -= 1

        for numLen in range(len(str(n)), len(str(n)) + 2):
            for num in backtracking(0, numLen, 0, Counter()):
                if num > n:
                    return num


if __name__ == "__main__":
    obj = Solution()
    print(obj.nextBeautifulNumber(1))
    print(obj.nextBeautifulNumber(1000))
    print(obj.nextBeautifulNumber(3000))
