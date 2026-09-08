# 3870. Count Commas in Range

"""
you are given an integer 'n'. return the total number of commas used when
writing all integers from '[1, n]' in standard formatting.
"""


class Solution:
    def countCommas(self, n: int) -> int:
        return max(0, n - 999)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countCommas(n=1002))
    print(obj.countCommas(n=998))
