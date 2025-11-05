# 3321. Find X-Sum of All K-Long Subarrays II
from collections import Counter

from sortedcontainers import SortedList

"""
you are given the array 'nums' of 'n' integers and two integers 'k' and 'x'.
the x-sum of an array is calcluated by the following procedure: count the
occurences of all elements in the array, keep only the occurences of the top
'x' most frequent elements. if two elements have the same number of
occurences, the element with the bigger value is considered more frequent.
calcluate the sum of the resulting array. note t hat if an array has less
than 'x' distinct elements, its x-sum is the sum of the array. return an
integer array 'answer' of length 'n - k + 1' where 'answer[i]' is the x-sum
of the subarray 'nums[i .. i + k - 1]'
"""


class Solution(object):
    def findXSum(self, nums, k, x):
        """
        :type nums: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        freq = Counter()
        top = SortedList()
        rest = SortedList()
        top_sum, ans = 0, []

        def balance():
            nonlocal top_sum
            while len(top) < x and rest:
                f, v = rest.pop()
                top.add((f, v))
                top_sum += f * v
            while len(top) > x:
                f, v = top.pop(0)
                top_sum -= f * v
                rest.add((f, v))
            while rest and top and rest[-1] > top[0]:
                f1, v1 = rest.pop()
                f2, v2 = top.pop(0)
                top_sum += f1 * v1 - f2 * v2
                top.add((f1, v1))
                rest.add((f2, v2))

        def add(num):
            nonlocal top_sum
            old = (freq[num], num)
            if old in top:
                top.remove(old)
                top_sum -= old[0] * old[1]
            elif old in rest:
                rest.remove(old)
            freq[num] += 1
            new = (freq[num], num)
            rest.add(new)
            balance()

        def remove(num):
            nonlocal top_sum
            old = (freq[num], num)
            if old in top:
                top.remove(old)
                top_sum -= old[0] * old[1]
            else:
                rest.remove(old)
            freq[num] -= 1
            if freq[num] > 0:
                rest.add((freq[num], num))
            else:
                del freq[num]
            balance()

        for i in range(k):
            add(nums[i])
        ans.append(top_sum)

        for i in range(k, len(nums)):
            remove(nums[i - k])
            add(nums[i])
            ans.append(top_sum)

        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findXSum(nums=[1, 1, 2, 2, 3, 4, 2, 3], k=6, x=2))
    print(obj.findXSum(nums=[3, 8, 7, 8, 7, 5], k=2, x=2))
