# 3097. Shortest Subarray With OR at Least K II

"""
you are given an array 'nums' of non-negative integers and an integer 'k'. an
array is called special if the bitwise OR of all its elements is at least
'k'. return the length of the shortest special non-empty subarray of 'nums',
or return -1 if no special subarray exists.
"""


class Solution(object):
    def minimumSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = [0 for _ in range(32)]
        n, j, curr, ans = len(nums), 0, 0, float("inf")
        for i in range(n):
            curr |= nums[i]
            for b in range(32):
                if nums[i] & 1 << b:
                    cnt[b] += 1
            while curr >= k and j <= i:
                ans = min(ans, i - j + 1)
                for b in range(32):
                    if nums[j] & 1 << b:
                        cnt[b] -= 1
                        if not cnt[b]:
                            curr ^= 1 << b
                j += 1
        return ans if ans != float("inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumSubarrayLength(nums=[1, 2, 3], k=2))
    print(obj.minimumSubarrayLength(nums=[2, 1, 8], k=10))
    print(obj.minimumSubarrayLength(nums=[1, 2], k=0))
