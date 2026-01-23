# 3510. Minimum Pair Removal to Sort Array II
from sortedcontainers import SortedList

"""
given an array 'nums', you can perfor the following operation any number of
times: select the adjacent pair with the minimum sum in 'nums'. if multiple
such pairs exist, choose the leftmost one. replace the pair with their sum.
return the minimum number of operations needed to make the array
non-decreasing. an array is said to be non-decreasing if each element is
greater than or equal to its previous element.
"""


class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = (len(nums),)
        l = list(range(-1, n - 1))
        r = list(range(1, n + 1))
        self.inversions = sum(nums[i] > nums[i + 1] for i in range(n - 1))
        s = SortedList([nums[i] + nums[i + 1], i] for i in range(n - 1))

        def add(i):
            j = r[i]
            if 0 <= i < j < n:
                s.add([nums[i] + nums[j], i])
                self.inversions += nums[i] > nums[j]

        def remove(i):
            j = r[i]
            if 0 <= i < j < n:
                s.discard([nums[i] + nums[j], i])
                self.inversions -= nums[i] > nums[j]

        ans = 0
        while self.inversions:
            ans += 1
            total, i = s.pop()
            j = r[i]
            h, k = l[i], r[j]
            remove(h)
            remove(i)
            remove(j)
            nums[i] += nums[j]
            r[i] = k
            if k < n:
                l[k] = i
            add(h)
            add(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumPairRemoval(nums=[5, 2, 3, 1]))
    print(obj.minimumPairRemoval(nums=[1, 2, 2]))
