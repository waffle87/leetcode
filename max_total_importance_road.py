# 2285. Maximum Total Importance of Roads

"""
given an integer 'n' denoting the number of cities in a country. the cities
are numbered from 0 to 'n - 1'. you are also given a 2d integer array 'roads'
where 'roads[i] = [ai, bi]', where each value can only be used once. the
importance of a road is then defined as the sum of the values of the two
cities it connects. return the maximum total importance of all roads possible
after assigning the values optimally.
"""


class Solution(object):
    def maximumImportance(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        sum, dp = 0, [0] * n
        for i, j in roads:
            dp[i] += 1
            dp[j] += 1
        roads.sort()
        for i in range(len(roads)):
            sum += dp[i] * (i + 1)
        return sum


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maximumImportance(
            n=5, roads=[[0, 1], [1, 2], [2, 3], [0, 2], [1, 3], [2, 4]]
        )
    )
    print(obj.maximumImportance(n=5, roads=[[0, 3], [2, 4], [1, 3]]))
