# 1552. Magnetic Force Between Two Balls

"""
in the universe earth c-137 rick discovered a special form of magnetic force
between two balls if they are put in his new invented basket. rick has 'n'
empty baskets the i'th basket is at 'position[i]', more has 'm' ball and
needs to distribute the balls into the baskets such that the minimum magnetic
force between any two balls is maximum. rick stated that magnetic force
betweeen two different balls at positions 'x' and 'y' is '|x - y|'. given the
integer array 'position' and the integer 'm', return the required force.
"""


class Solution(object):
    def check(self, position, m, mid):
        cnt, prev = 1, position[0]
        for i in range(1, len(position)):
            if position[i] - prev >= mid:
                cnt += 1
                prev = position[i]
        return cnt >= m

    def maxDistance(self, position, m):
        """
        :type position: List[int]
        :type m: int
        :rtype: int
        """
        position.sort()
        left, right = 1, position[-1] - position[0]
        while right - left > 1:
            mid = (left + right) // 2
            if self.check(position, m, mid):
                left = mid
            else:
                right = mid - 1
        if self.check(position, m, right):
            return right
        return left


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistance(position=[1, 2, 3, 4, 7], m=3))
    print(obj.maxDistance(position=[5, 4, 3, 2, 1, 1000000000], m=2))
