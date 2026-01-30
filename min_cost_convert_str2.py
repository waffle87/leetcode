# 2977. Minimum Cost to Convert String II
import heapq
from collections import defaultdict

"""
you are given two 0 indexed strings 'source' and 'target'. both of length 'n'
and consisting of lowercase english letters. you are also given two 0 indexed
string arrays 'original' and 'changed', and an integer array 'cost' where
'cost[i]' represents the cost of converting the string 'original[i]' to the
string 'changed[i]'. you start with the string 'source'. in one operation,
you can pick a substring 'x' from the string and change it to 'y' at a cost
of 'z' if there exists any index 'j' such that 'cost[j] == z', 'original[j]
== x', and 'changed[j] == y'. you are allowed to do any number of operations
but any pair of operations must satisfy either of these two conditions.
return the minimum cost to convert the string 'source' to the string 'target'
using any number of operations. if it is impossible to convert 'source' to
'target', return -1. note that there may exist indices 'i', 'j' such that
'original[i] == original[j]' and 'changed[i] == changed[j]'
"""


class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        adj = defaultdict(lambda: defaultdict(int))
        change_lengths = set(len(sub) for sub in original)
        for i, start in enumerate(original):
            end = changed[i]
            c = cost[i]
            if end in adj[start]:
                adj[start][end] = min(adj[start][end], c)
            else:
                adj[start][end] = c

        def dijkstra(start, end):
            heap = [(0, start)]
            costs = defaultdict(lambda: float("inf"))
            costs[start] = 0
            while heap:
                path_cost, curr = heapq.heappop(heap)
                if curr == end:
                    return path_cost
                for nei in adj[curr]:
                    nei_cost = adj[curr][nei]
                    new_cost = nei_cost + path_cost
                    if new_cost < costs[nei]:
                        costs[nei] = new_cost
                        heapq.heappush(heap, (new_cost, nei))
            return float("inf")

        def dfs(i):
            if i >= len(target):
                return 0
            c = float("inf") if target[i] != source[i] else dfs(i + 1)
            for length in change_lengths:
                t_sub = target[i : i + length]
                s_sub = source[i : i + length]
                trans_cost = dijkstra(s_sub, t_sub)
                if trans_cost != float("inf"):
                    c = min(c, trans_cost + dfs(i + length))
            return c

        ans = dfs(0)
        return ans if ans != float("inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumCost(
            source="abcd",
            target="acbe",
            original=["a", "b", "c", "c", "e", "d"],
            changed=["b", "c", "b", "e", "b", "e"],
            cost=[2, 5, 5, 1, 2, 20],
        )
    )
    print(
        obj.minimumCost(
            source="abcdefgh",
            target="acdeeghh",
            original=["bcd", "fgh", "thh"],
            changed=["cde", "thh", "ghh"],
            cost=[1, 3, 5],
        )
    )
    print(
        obj.minimumCost(
            source="abcdefgh",
            target="addddddd",
            original=["bcd", "defgh"],
            changed=["ddd", "ddddd"],
            cost=[100, 1578],
        )
    )
