# 2418. Sort the People

"""
you are given an array of strings 'names' and an array 'heights' that
consists of distinct positive integers. both arrays are of length 'n'. for
each index 'i', 'names[i]' and 'heights[i]' denote the name and height of the
i'th person. return 'names' sorted in descending order by the people's
heights.
"""


class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        ans = []
        for i in range(len(names)):
            ans.append([heights[i], names[i]])
        ans = sorted(ans, reverse=True)
        return [name for height, name in ans]


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortPeople(names=["Mary", "John", "Emma"], heights=[180, 165, 170]))
    print(obj.sortPeople(names=["Alice", "Bob", "Bob"], heights=[155, 185, 150]))
