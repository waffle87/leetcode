# 3346. Maximum Frequency of an Element After Performing Operations I

"""
you are given an integer array 'nums' and two integers 'k' and
'numOperations'. you must perform an operation 'numOperations' times on
'nums', where in each operation you select an index 'i' that was not selected
in any previous operations, and add an integer in the range '[-k, k]' to
nums. return the maximum possible frequency of any element in 'nums' after
performing the operations.
"""


class Solution(object):
    def maxFrequency(self, nums, k, numOperations):
        """
        :type nums: List[int]
        :type k: int
        :type numOperations: int
        :rtype: int
        """
        mx, ans = max(nums), 0
        n = mx + k + 2
        freq, pre = [0] * n, [0] * n
        for i in nums:
            freq[i] += 1
        pre[0] = freq[0]
        for i in range(1, n):
            pre[i] = pre[i - 1] + freq[i]
        for i in range(n):
            if freq[i] == 0 and numOperations == 0:
                continue
            l, r = max(0, i - k), min(n - 1, i + k)
            total = pre[r] - (pre[l - 1] if l > 0 else 0)
            adj = total - freq[i]
            val = freq[i] + min(numOperations, adj)
            ans = max(ans, val)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFrequency(nums=[1, 4, 5], k=1, numOperations=2))
    print(obj.maxFrequency(nums=[5, 11, 20, 20], k=5, numOperations=1))
