# 2121. Intervals Between Identical Elements

"""
given a 0-indexed array of 'n' integers 'arr'. the interval between two
elements in 'arr' is defined as the absolute difference between their
indices. more formally, the interval between 'arr[i]' and 'arr[j]' is |i -
j|. return an array intervals of length 'n' where 'intervals[i]' is the sum
of the intervals between 'arr[i]' and each element in 'arr' with the same
value as 'arr[i]'.
"""


class Solution(object):
    def getDistances(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        m, ans = {}, [0] * len(arr)
        for i, v in enumerate(arr):
            if v not in m:
                m[v] = list()
            m[v].append(i)
        for i in m:
            l = m[i]
            pre = [0] * (len(l) + 1)
            for j in range(len(l)):
                pre[j + 1] = pre[j] + l[j]
            for j, v in enumerate(l):
                ans[v] = (v * (j + 1) - pre[j + 1]) + (
                    (pre[len(l)] - pre[j]) - v * (len(l) - (i))
                )
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.getDistances(arr=[2, 1, 3, 1, 2, 3, 3]))
    print(obj.getDistances(arr=[10, 5, 10, 10]))
