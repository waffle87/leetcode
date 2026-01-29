# 2976. Minimum Cost to Convert String I
import heapq
from collections import defaultdict

"""
you are given two 0 indexed strings 'source' and 'target', both of length 'n'
and consisting of lowercase english letters. you are also given two 0 indexed
character arrays 'original' and 'changed', and an integer array 'cost' where
'cost[i]' represents the cost of changing the character 'original[i]' to the
character 'changed[i]' you start with the string 'source'. in one operation,
you can pick a character 'x' from te string and change it to the character
'y' at a cost of 'z' if there exists any index 'j' such that 'cost[j] == z,
original[j] == x, changed[j] == y'. return the minimum cost to conver the
string 'source' to the string 'target'.
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

        def build(original, changed, costs):
            graph = defaultdict(lambda: defaultdict(lambda: float("inf")))
            for ori, ch, cost in zip(original, changed, costs):
                graph[ori][ch] = min(graph[ori][ch], cost)
            return graph

        def dijkstra(graph, start_node, target_node):
            if start_node not in graph:
                return float("inf")

            visited_nodes = set()
            min_heap = [(0, start_node)]

            while min_heap:
                cost_to_current, current_node = heapq.heappop(min_heap)
                if current_node == target_node:
                    return cost_to_current
                if current_node in visited_nodes:
                    continue
                visited_nodes.add(current_node)
                for neighbor_node in graph[current_node]:
                    if neighbor_node not in visited_nodes:
                        heapq.heappush(
                            min_heap,
                            (
                                cost_to_current + graph[current_node][neighbor_node],
                                neighbor_node,
                            ),
                        )
            return float("inf")

        graph = build(original, changed, cost)
        total_cost = 0
        memo = {}

        for s, t in zip(source, target):
            if s != t:
                if (s, t) in memo:
                    cost = memo[(s, t)]
                else:
                    cost = dijkstra(graph, s, t)
                    memo[(s, t)] = cost
                if cost == float("inf"):
                    return -1
                total_cost += cost

        return total_cost


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
            source="aaaa",
            target="bbbb",
            original=["a", "c"],
            changed=["c", "b"],
            cost=[1, 2],
        )
    )
    print(
        obj.minimumCost(
            source="abcd", target="abce", original=["a"], changed=["e"], cost=[10000]
        )
    )
