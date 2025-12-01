# 2141. Maximum Running Time of N Computers

"""
you have 'n' computers. you are given the integer 'n' and a 0-indexed integer
array 'batteries' where the i'th battery can run a computer for
'batteries[i]' minutes. you are interested in running all 'n' computers
simultaneously using the given batteries. initially, you can insert at most
one battery into each computer. after that and at any integer time moment,
you can remove a battery from a computer and insert another battery any
number of times. the inserted battery can be a totally new battery or a
battery forom another computer. you may assume that the removing and
inserting process takes no time. note that the batteries canot be recharged.
return the maximum number of minutes you can run all the 'n' computers
simultaneously.
"""


class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        total = sum(batteries)
        batteries.sort()
        for i in range(len(batteries) - 1, -1, -1):
            if batteries[i] > total // n:
                total -= batteries[i]
                n -= 1
            else:
                break
        return total // n


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxRunTime(n=2, batteries=[3, 3, 3]))
    print(obj.maxRunTime(n=2, batteries=[1, 1, 1, 1]))
