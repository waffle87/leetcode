# 3723. Maximize Sum of Squares of Digits

"""
you are given two positive integers 'num' and 'sum'. a positive integer 'n'
is good if it satisfies both of the following: the number of digits in 'n' is
exactly 'num', and the sum of digits in 'n' is exactly 'sum'. return a string
denoting the good integer 'n' that achieves the maximum score
"""


class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if num * 9 < sum:
            return ""
        q, r = divmod(sum, 9)
        ans = "9" * q + (str(r) if r else "")
        return ans + "0" * (num - len(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSumOfSquares(num=2, sum=3))
    print(obj.maxSumOfSquares(num=2, sum=17))
    print(obj.maxSumOfSquares(num=1, sum=10))
