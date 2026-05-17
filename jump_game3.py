# 1306. Jump Game III
from collections import deque

"""
given an array of non-negative integers 'arr', you are initially positioned
at 'start' index of the array. when you are at index 'i', you can jump to 'i
+ arr[i]' or 'i - arr[i]', check if you can reach any index with value 0.
notice that you cannot jump outside of the array at any time.
"""


class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = deque([start])
        while q:
            start = q.popleft()
            if arr[start] == 0:
                return True
            if arr[start] < 0:
                continue
            if start + arr[start] < len(arr):
                q.append(start + arr[start])
            if start - arr[start] >= 0:
                q.append(start - arr[start])
            arr[start] = -arr[start]
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.canReach(arr=[4, 2, 3, 0, 3, 1, 2], start=5))
    print(obj.canReach(arr=[4, 2, 3, 0, 3, 1, 2], start=0))
    print(obj.canReach(arr=[3, 0, 2, 1, 2], start=2))
