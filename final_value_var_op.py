# 2011. Final Value of Variable After Performing Operations

"""
there is a programming language with only four operations and one variable
'x': '++x' and 'x++' increments the value of the variable 'x' by 1, and '--x'
and 'x--' decrements the value of the variable 'x' by 1. initially, the value
of 'x' is 0. given an array of strings 'operations' containing a list of
operations, return the final value of 'x' after performing all the
operations.
"""


class Solution(object):
    def finalValueAfterOperations(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        return sum(1 if op[1] == "+" else -1 for op in operations)


if __name__ == "__main__":
    obj = Solution()
    print(obj.finalValueAfterOperations(operations=["--X", "X++", "X++"]))
    print(obj.finalValueAfterOperations(operations=["++X", "++X", "X++"]))
    print(obj.finalValueAfterOperations(operations=["X++", "++X", "--X", "X--"]))
