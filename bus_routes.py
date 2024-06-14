# 815. Bus Routes

"""
you are given an array 'routes' representing bus routes where 'routes[i]' is
a bus route that the i'th bus repeats forever. you will start at the bus stop
'source' you are not on any bus initially and you want to go to the bus stop
'target'. you can only travel between bus stops by buses only. return the
least number of buses you must take to travel from 'source' to 'target'.
return -1 if it is not possible.
"""


class Solution(object):
    def numBusesToDestination(self, routes, source, target):
        """
        :type routes: List[List[int]]
        :type source: int
        :type target: int
        :rtype: int
        """
        if source == target:
            return 0
        stop_to_route = defaultdict(set)
        for i, route in enumerate(routes):
            for stop in route:
                stop_to_route[stop].add(i)
        vis = set()
        q = deque([(source, 0)])
        while q:
            curr, num = q.popleft()
            for route_idx in stop_to_route[curr]:
                for next in routes[route_idx]:
                    if next == target:
                        return num + 1
                    if next not in vis:
                        vis.add(next)
                        q.append((next, num + 1))
                routes[route_idx] = []
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.numBusesToDestination(routes=[[1, 2, 7], [3, 6, 7]], source=1, target=6)
    )  # expect: 2
    print(
        obj.numBusesToDestination(
            routes=[[7, 12], [4, 5, 15], [6], [15, 19], [9, 12, 13]],
            source=15,
            target=12,
        )
    )  # expect: -1
