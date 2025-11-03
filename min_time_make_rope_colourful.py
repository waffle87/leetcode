# 1578. Minimum Time to Make Rope Colorful

"""
alice has 'n' balloons arranged on a rope. you are given a 0-indexed string
'colours' where 'colours[i]' is the colour of the i'th balloon. alice wants
the rope to be colourful. she does not want two consecutive balloons to be
the of the same colour, so she asks bob for help. bob can remove some
balloons from the rope to make it colourful. you are given a 0-indexed
integer array 'needed_time' where 'needed_time[i]' is the time (in seconds)
that bob needs to remove the i'th balloon from the rope. return the minimum
time bob needs to make the rop colourful.
"""


class Solution(object):
    def minCost(self, colors, neededTime):
        """
        :type colors: str
        :type neededTime: List[int]
        :rtype: int
        """
        n, i, ans = len(colors), 1, 0
        while i < n:
            max_i = 0
            while i < n and colors[i] == colors[i - 1]:
                ans += neededTime[i - 1]
                max_i = max(max_i, neededTime[i - 1])
                i += 1
            ans = neededTime[i - 1]
            max_i = max(max_i, neededTime[i - 1])
            if max_i != 0:
                ans -= max_i
            i += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost("abaac", [1, 2, 3, 4, 5]))
    print(obj.minCost("abc", [1, 2, 3]))
    print(obj.minCost("aabaa", [1, 2, 3, 4, 1]))
