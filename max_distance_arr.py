# 624. Maximum Distance in Arrays

"""
you are given 'm' arrays where each array is sorted in ascending order. you
can pick up two integers from two different arrays (each array picks one) and
calculate the distance. we define the distance between two integer 'a' and
'b' to be their absolute idfferent '|a - b|'. return the maximum distance
"""


class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        ans, curr_min, curr_max = 0, 10000, -10000
        for i in arrays:
            ans = max(ans, max(i[-1] - curr_min, curr_max - i[0]))
            curr_min, curr_max = min(curr_min, i[0]), max(curr_max, i[-1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistance(arrays=[[1, 2, 3], [4, 5], [1, 2, 3]]))
    print(obj.maxDistance(arrays=[[1], [1]]))
