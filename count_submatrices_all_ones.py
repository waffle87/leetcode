# 1504. Count Submatrices With All Ones

"""
given an 'm x n' binary matrix 'mat', return the number of submatrices that
have all ones.
"""


class Solution(object):
    def numSubmat(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        n, m = len(mat), len(mat[0])
        dp, ans = [0] * m, 0
        for i in range(n):
            for j in range(m):
                dp[j] = dp[j] + 1 if mat[i][j] else 0
            total, st = [0] * m, []
            for j in range(m):
                while st and dp[st[-1]] >= dp[j]:
                    st.pop()
                if st:
                    curr = st[-1]
                    total[j] = total[curr] + dp[j] * (j - curr)
                else:
                    total[j] = dp[j] * (j + 1)
                st.append(j)
                ans += total[j]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSubmat(mat=[[1, 0, 1], [1, 1, 0], [1, 1, 0]]))
    print(obj.numSubmat(mat=[[0, 1, 1, 0], [0, 1, 1, 1], [1, 1, 1, 0]]))
