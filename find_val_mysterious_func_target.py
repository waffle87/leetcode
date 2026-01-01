# 1521. Find a Value of a Mysterious Function Closest to Target

"""
winston was given the above mysterious function 'func'. he has an integer
array 'arr' and an integer 'target' and he wants to find the values 'r' and
'l' that make the value '|func(arr, l, r) - target|' minimum possible. return
the minimum possible value of '|func(arr, l, r) - target|'. notice that
'func' should be called with vaues 'l' and 'r' where '0 <= l, r <
arr.length'.
"""


class Solution(object):
    def closestToTarget(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        ans, curr = float("inf"), set()
        for i in arr:
            curr = {j & i for j in curr} | {i}
            ans = min(ans, min(abs(j - target) for j in curr))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.closestToTarget(arr=[9, 12, 3, 7, 15], target=5))
    print(obj.closestToTarget(arr=[1000000, 1000000, 1000000], target=1))
