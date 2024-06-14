# 907. Sum of Subarray Minimums

"""
given an array of integers 'arr', find the sum of 'min(b)', where 'b' ranges
over every contiguous subarray of 'arr'. since the answer may be large,
return the answer modulo 10^9+7
"""


class Solution(object):
    def sumSubarrayMins(self, arr):
        stack = []
        ans = 0
        arr = [float("-inf")] + arr + [float("-inf")]
        for i, num in enumerate(arr):
            while stack and arr[stack[-1]] > num:
                curr = stack.pop()
                ans += arr[curr] * (i - curr) * (curr - stack[-1])
            stack.append(i)
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumSubarrayMins([3, 1, 2, 4]))
    # expect: 17
    print(obj.sumSubarrayMins([11, 81, 94, 43, 3]))
    # expect: 444
