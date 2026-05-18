# 1345. Jump Game IV
from collections import defaultdict, deque

"""
given array of integers 'arr', you are initially positioned at first index of
array. in one step, you can jump from index 'i' to index 'j'. return minimum
number of steps to reach lat index of array. notice, you cannot jump outside
of array at any time.
"""


class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n, q = len(arr), deque([(0, 0)])
        vis = set([0])
        neighbour = defaultdict(list)
        for i, v in enumerate(arr):
            neighbour[v].append(i)
        while q:
            step, cur = q.popleft()
            if cur == n - 1:
                return step
            for nxt in [cur - 1, cur + 1, *neighbour[arr[cur]]]:
                if 0 <= nxt < n and nxt not in vis:
                    q.append((step + 1, nxt))
                    vis.add(nxt)
            del neighbour[arr[cur]]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minJumps(arr=[100, -23, -23, 404, 100, 23, 23, 23, 3, 404]))
    print(obj.minJumps(arr=[7]))
    print(obj.minJumps(arr=[7, 6, 9, 6, 9, 6, 9, 7]))
