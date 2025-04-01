# 2140. Solving Questions With Brainpower

"""
given a 0-indexed 2d integer array 'questions' where 'questions[i] =
[pointsi, brainpoweri]'. the array describes the questions of an exam, where
you have to process the questions in order (ie starting from question 0) and
make a decision whether to solve or skip each question. solving question 'i'
will earn you 'pointsi' points, but you will be unable to solve each of the
next 'brainpoweri' questions. if you skip question 'i', yo get to make the
decision on the next question. return maximum points you can score.
"""


class Solution(object):
    def mostPoints(self, questions):
        """
        :type questions: List[List[int]]
        :rtype: int
        """
        dp = [0] * (len(questions) + 1)
        for i in range(len(questions) - 1, -1, -1):
            points, jump = questions[i][0], questions[i][1]
            dp[i] = max(points + dp[min(jump + i + 1, len(questions))], dp[i + 1])
        return dp[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.mostPoints(questions=[[3, 2], [4, 3], [4, 4], [2, 5]]))
    print(obj.mostPoints(questions=[[1, 1], [2, 2], [3, 3], [4, 4], [5, 5]]))
