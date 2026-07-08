# 3756. Concatenate Non-Zero Digits and Multiply by Sum II
from itertools import accumulate

"""
you are given a string 's' of length 'm' consisting of digits. you are also
given a 2d integer array 'queries' where 'queries[i] = [l_i, r_i]'. for each
'queries[i]', extract the substring 's[l_i ... r_i]'. then perform the
following: form a new integer 'x' by concatenating all the non-zero digits
from the substring in their original order. if there are no non-zero digits,
'x = 0'. let 'sum' be the sum of digits in 'x'. the answer is 'x  sum'.
return an array of integers 'answer' where 'answer[i]' is the answer to the
i'th query. since the answers may be very large, return them modulo 10^9 + 7.
"""


class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7
        p = [
            *accumulate(
                map(int, s), lambda q, v: v and (q * 10 + v) % mod or q, initial=0
            )
        ]
        w = [*accumulate((c > "0" for c in s), initial=0)]
        q = [*accumulate(map(int, s), initial=0)]
        return [
            (p[r + 1] - p[l] * pow(10, w[r + 1] - w[l], mod)) * (q[r + 1] - q[l]) % mod
            for l, r in queries
        ]


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumAndMultiply(s="10203004", queries=[[0, 7], [1, 3], [4, 6]]))
    print(obj.sumAndMultiply(s="1000", queries=[[0, 3], [1, 1]]))
    print(obj.sumAndMultiply(s="9876543210", queries=[[0, 9]]))
