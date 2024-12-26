# 1014. Best Sightseeing Pair

"""
you are given an integer array 'values' where 'values[i]' represents the
value of the i'th sightseeing spot. two sightseeing spots 'i' and 'j' have a
distance 'j - i' between them. the score of a pair ('i < j') of sightseeing
spots is 'values[i] + values[j] + i - j': the sum of the values of the
sightseeing spots. minus the distance between them. return the maximum score
of a pair of sightseeing spots.
"""


class Solution(object):
    def maxScoreSightseeingPair(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        ans, curr = 0, 0
        for i in values:
            ans = max(ans, curr + i)
            curr = max(curr, i) - 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxScoreSightseeingPair(values=[8, 1, 5, 2, 6]))
    print(obj.maxScoreSightseeingPair(values=[1, 2]))
