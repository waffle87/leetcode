# 502. IPO
import heapq

"""
suppose leetcode will start its ipo soon. in order to sell a good price of
its shares to venture capital, leetcode woule like to work on some projects
to increase its capital before the ipo. since it has limited resources, it
can only finish at most k distinct projects before the ipo. maximise capital
after finishing at most 'k' distinct projects. given 'n' projects where the
i'th project has a pure profit 'profits[i]' and min capital of 'capital[i]'
is needed to start it.
"""


class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        """
        :type k: int
        :type w: int
        :type profits: List[int]
        :type capital: List[int]
        :rtype: int
        """
        n, i = len(profits), 0
        projects = [(capital[i], profits[i]) for i in range(n)]
        projects.sort()
        maximise_capital = []
        while k > 0:
            while i < n and projects[i][0] <= w:
                heapq.heappush(maximise_capital, -projects[i][1])
                i += 1
            if not maximise_capital:
                break
            w -= heapq.heappop(maximise_capital)
            k -= 1
        return w


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaximizedCapital(k=2, w=0, profits=[1, 2, 3], capital=[0, 1, 1]))
    print(obj.findMaximizedCapital(k=3, w=0, profits=[1, 2, 3], capital=[0, 1, 2]))
