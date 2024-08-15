# 2643. Row With Maximum Ones

"""
given an 'm * n' binary matrix 'mat' find the 0 indexed position of the row
that contains the maximum count of ones and the number of ones in that row.
in case there are multiple rows that have the maximum count of ones, the row
with the smallest number should be selected. return an array containing the
index of the row and the number of ones in it
"""


class Solution(object):
    def rowAndMaximumOnes(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        cnt, ans = 0, []
        ans.append(0)
        ans.append(0)
        for row in range(len(mat)):
            for col in mat[row]:
                if col == 1:
                    cnt += 1
            if ans[1] < cnt:
                ans[0] = row
                ans[1] = cnt
            cnt = 0
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.rowAndMaximumOnes(mat=[[0, 1], [1, 0]]))
    print(obj.rowAndMaximumOnes(mat=[[0, 0, 0], [0, 1, 1]]))
    print(obj.rowAndMaximumOnes(mat=[[0, 0], [1, 1], [0, 0]]))
