# 1606. Find Servers That Handled Most Number of Requests

from heapq import heappop, heappush
from statistics import multimode


class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        free = list(range(k))
        handled, busy = [], []
        for i, (t, d) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= t:
                heappush(free, i + (heappop(busy)[1] - i) % k)
            if free:
                x = heappop(free) % k
                heappush(busy, (t + d, x))
                handled.append(x)
        return multimode(handled)


if __name__ == "__main__":
    obj = Solution()
    print(obj.busiestServers(k=3, arrival=[1, 2, 3, 4, 5], load=[5, 2, 3, 3, 3]))
    print(obj.busiestServers(k=3, arrival=[1, 2, 3, 4], load=[1, 2, 1, 2]))
    print(obj.busiestServers(k=3, arrival=[1, 2, 3], load=[10, 12, 11]))
