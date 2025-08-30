# 1237. Find Positive Integer Solution for a Given Equation

"""
given a callable function 'f(x, y)' with a hidden formula and a value 'z',
reverse engineer the formula and return all positive integer pairs 'x' and
'y' where 'f(x, y) == z'. you may return the pairs in any order. while the
exact formula is hidden, the function is monotonically increasing.
"""

function_id = 0


class customfunction(object):
    def f(self, x, y):
        if function_id == 1:
            return x + y
        if function_id == 2:
            return x * y


class Solution(object):
    def findSolution(self, customfunction, z):
        """
        :type num: int
        :type z: int
        :rtype: List[List[int]]
        """
        ans, y = [], 1000
        for x in range(1, 1001):
            while y > 1 and customfunction.f(x, y) > z:
                y -= 1
            if customfunction.f(x, y) == z:
                ans.append([x, y])
        return ans


if __name__ == "__main__":
    obj = Solution()
    function_id = 1
    print(obj.findSolution(customfunction, 5))
    function_id = 2
    print(obj.findSolution(customfunction, 5))
