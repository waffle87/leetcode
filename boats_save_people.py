# 881. Boats to Save People

"""
given an array 'people' where 'people[i]' is the weight of the i'th person,
and an infinite number of boats where each boat can carry a maximum weight of
'limit'. each boat carries at most two people at the same time, provided the
sum of the weight of those people is at most 'limit'. return minimum number
of boats to carry every person
"""


class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort(reverse=True)
        i, j = 0, len(people) - 1
        while i <= j:
            if people[i] + people[j] <= limit:
                j -= 1
            i += 1
        return i


if __name__ == "__main__":
    obj = Solution()
    print(obj.numRescueBoats([1, 2], 3))
    print(obj.numRescueBoats([3, 2, 2, 1], 3))
    print(obj.numRescueBoats([3, 5, 3, 4], 5))
