# 1488. Avoid Flood in The City
import heapq
from collections import defaultdict

"""
your country has an infinite number of lakes. initially, all the lakes are
empty. but when it rains over the n'th lake, the n'th lake becomes full of
water. if it rains over a lake that is full of water, there will be a flood.
your goal is to avoid any floods. if there are multiple valid answers, return
any of them. if it is impossible to avoid flood, return an empty array.
notice that if yo uchose to dry a full lake, it becomes empty. but if you
chose to dry an empty lake, nothing happens.
"""


class Solution(object):
    def avoidFlood(self, rains):
        """
        :type rains: List[int]
        :rtype: List[int]
        """
        d = defaultdict(list)
        ans = [-1] * len(rains)
        hash = []
        for i, j in enumerate(rains):
            d[j].append(i)
        for i in range(len(rains)):
            curr = rains[i]
            if curr:
                if d[curr] and d[curr][0] < i:
                    return []
                if d[curr] and len(d[curr]) > 1:
                    heapq.heappush(hash, d[curr][1])
            else:
                if hash:
                    ans[i] = rains[heapq.heappop(hash)]
                    d[ans[i]].pop(0)
                else:
                    ans[i] = 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.avoidFlood(rains=[1, 2, 3, 4]))
    print(obj.avoidFlood(rains=[1, 2, 0, 0, 2, 1]))
    print(obj.avoidFlood(rains=[1, 2, 0, 1, 2]))
