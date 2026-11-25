#  3934. Smallest Unique Subarray


from bisect import bisect_left

import numpy as np


class Solution:
    def smallestUniqueSubarray(self, nums: list[int]) -> int:
        n = len(nums)
        names = [np.unique(nums, return_inverse=True)[1]]
        for k in range(n.bit_length() - 1):
            if 1 in np.bincount(names[k]):
                break
            pairs = names[k][: -(2**k)] * n + names[k][2**k :]
            names.append(np.unique(pairs, return_inverse=True)[1])

        def found(len):
            k = len.bit_length() - 1
            pairs = names[k][: n - len + 1] * n + names[k][len - 2**k :]
            return 1 in np.unique(pairs, return_counts=True)[1]

        return bisect_left(range(1, min(2 ** len(names), n)), True, key=found) + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestUniqueSubarray(nums=[3, 3, 3]))
    print(obj.smallestUniqueSubarray(nums=[2, 1, 2, 3, 3]))
    print(obj.smallestUniqueSubarray(nums=[1, 1, 2, 2, 1]))
