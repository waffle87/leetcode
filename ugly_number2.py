# 264. Ugly Number II

"""
an ugly number is a positive integer whose prime factors are limited to
2,3,5. given an integer 'n', return the n'th ugly number
"""


class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        factors, k = [2, 3, 5], 3
        starts, Numbers = [0] * k, [1]
        for i in range(n - 1):
            candidates = [factors[i] * Numbers[starts[i]] for i in range(k)]
            new_num = min(candidates)
            Numbers.append(new_num)
            starts = [starts[i] + (candidates[i] == new_num) for i in range(k)]
        return Numbers[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.nthUglyNumber(10))
    print(obj.nthUglyNumber(1))
