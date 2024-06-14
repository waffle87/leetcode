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
        cost = 0
        i = 0
        j = 0
        while i < len(neededTime) and j < len(neededTime):
            curr_cost = 0
            curr_max = 0
            while j < len(neededTime) and colors[i] == colors[j]:
                curr_cost += neededTime[j]
                curr_max = max(curr_max, neededTime[j])
                j += 1
            cost += curr_cost - curr_max
            i = j
        return cost


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost("abaac", [1, 2, 3, 4, 5]))  # expect: 3
    print(obj.minCost("abc", [1, 2, 3]))  # expect: 0
    print(obj.minCost("aabaa", [1, 2, 3, 4, 1]))  # expect: 2
