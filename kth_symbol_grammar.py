# 779. K-th Symbol in Grammar

"""
we build a table of 'n' rows (1-indexed) we start by writing 0 in the first
row. now in every subsequent row, we look at the previous row and replace
each occurence of zero with '01', and each occurence of 1 with '10'. for
example for 'n = 3', the first row is the 0, the second row is the 01, and
the third row is 0110. given two integer 'n' and 'k', return the k'th
(1-indexed) symbol in the n'th row of a table of 'n' rows.
"""


class Solution(object):
    def kthGrammar(self, n, k):
        return bin(k - 1).count("1") & 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthGrammar(1, 1))  # expect: 0
    print(obj.kthGrammar(2, 1))  # expect: 0
    print(obj.kthGrammar(2, 2))  # expect: 1
