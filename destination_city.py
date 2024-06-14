# 1436. Destination City

"""
given the array 'paths' where 'paths[i] = [citya[i], cityb[i]]' means there
exists a direct path going from 'citya[i]' to 'cityb[i]'. return the
destination city that is the city without any path outgoing to another city.
it is guaranteed that the graph of paths forms a line without any loop,
therefore there will be exactly one destination.
"""


class Solution(object):
    def destCity(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: str
        """
        cities = set()
        for i in paths:
            cities.add(i[0])
        for i in paths:
            dest = i[1]
            if dest not in cities:
                return dest
        return ""


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.destCity(
            paths=[["London", "New York"], ["New York", "Lima"], ["Lima", "Sao Paulo"]]
        )
    )
    print(obj.destCity(paths=[["B", "C"], ["D", "B"], ["C", "A"]]))
