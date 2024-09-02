# 1894. Find the Student that Will Replace the Chalk

"""
there are 'n' students in a class numbered from 0 to 'n - 1'. the teacher
will give each student a problem starting with the student number 0, then the
student number 1, and so on until the teach reaches the student number 'n -
1'. after that the teach will restart the processes, starting with the
student number 0 again. you are given a 0-indexed integer array 'chalk' and
an integer 'k'. there are initially 'k' pieces of chalk. when the student
number 'i' is given a problem to solve, they will use 'chalk[i]' pieces of
chalk to solve that problem. however, if the current number of chalk pieces
is strictly less than 'chalk[i]', then the student number 'i' will be asked
to replace the chalk. return the index of the student that will replace the
chalk pieces.
"""


class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        k %= sum(chalk)
        for i, j in enumerate(chalk):
            if k < j:
                return i
            k -= j
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.chalkReplacer(chalk=[5, 1, 5], k=22))
    print(obj.chalkReplacer(chalk=[3, 4, 1, 2], k=25))
