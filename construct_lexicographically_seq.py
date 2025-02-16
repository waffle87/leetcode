# 1718. Construct the Lexicographically Largest Valid Sequence

"""
given an integer 'n', find a sequence that satisfies all of the following:
the integer '1' occurs once in the sequence, each integer between '2' and 'n'
occurs twice in the sequence, and for every integer 'i' between '2' and 'n',
the distance between the two occurence of 'i' is exactly 'i'. the distance
between two numbers on the sequence, 'a[i]' and 'a[j]' is the absolute
difference of their indices '|j - i|'.
"""


class Solution(object):
    def constructDistancedSequence(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        i, arr, vis = 0, [0] * (2 * n - 1), [False] * (n + 1)

        def dfs(arr, i, vis):
            if i >= 2 * n - 1:
                return True
            for j in range(n, 0, -1):
                if (
                    j > 1
                    and (
                        (not (arr[i] == 0 and (i + j < 2 * n - 1) and arr[i + j] == 0))
                        or vis[j]
                    )
                ) or (j == 1 and (arr[i] != 0 or vis[j])):
                    continue
                if j > 1:
                    arr[i] = j
                    arr[i + j] = j
                else:
                    arr[i] = j
                vis[j] = True
                next = i + 1
                while next < 2 * n - 1 and arr[next]:
                    next += 1
                if dfs(arr, next, vis):
                    return True
                if j > 1:
                    arr[i] = 0
                    arr[i + j] = 0
                else:
                    arr[i] = 0
                vis[j] = False
            return False

        dfs(arr, i, vis)
        return arr


if __name__ == "__main__":
    obj = Solution()
    print(obj.constructDistancedSequence(3))
    print(obj.constructDistancedSequence(5))
