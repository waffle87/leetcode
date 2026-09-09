# 3871. Count Commas in Range II

"""
you are given an integer 'n'. return the total number of commas used when
writing all integers from '[1, n]' in standard number formatting.
"""


class Solution:
    def countCommas(self, n: int) -> int:
        return sum(max(0, n - 1000**i + 1) for i in range(1, 6))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countCommas(n=1002))
    print(obj.countCommas(n=998))
