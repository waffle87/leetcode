# 1340. Jump Game V

"""
given an array of integers 'arr' and an integer 'd'. in one step you can jump
from index 'i' to index 'i + x' where 'i + x < arr.length' and '0 < x <= d',
or 'i - x' where 'i - x >= 0' and '0 < x <= d'. in addition, you only jump
from index 'i' to index 'j' if 'arr[i] > arr[j]' and 'arr[i] > arr[k]' for
all indices 'k' between 'i' and 'j'. you can choose any index of the array
and start jumping. return the maximum number of indices you can visit.
"""

from collections import defaultdict


class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        g = defaultdict(list)

        def jump(iter):
            s = []
            for i in iter:
                while s and arr[s[-1]] < arr[i]:
                    j = s.pop()
                    if abs(i - j) <= d:
                        g[j].append(i)
                s.append(i)

        jump(range(n))
        jump(reversed(range(n)))

        def height(i):
            return 1 + max(map(height, g[i]), default=0)

        return max(map(height, range(n)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxJumps(arr=[6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12], d=2))
    print(obj.maxJumps(arr=[3, 3, 3, 3, 3], d=3))
    print(obj.maxJumps(arr=[7, 6, 5, 4, 3, 2, 1], d=1))
