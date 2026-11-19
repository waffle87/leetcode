# 2567. Minimum Score by Changing Two Elements

from heapq import nlargest, nsmallest
from operator import sub


class Solution:
    def minimizeSum(self, nums: list[int]) -> int:
        return min(map(sub, nlargest(3, nums), reversed(nsmallest(3, nums))))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimizeSum(nums=[1, 4, 7, 8, 5]))
    print(obj.minimizeSum(nums=[1, 4, 3]))
