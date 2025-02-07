# 3160. Find the Number of Distinct colours Among the Balls

"""
you are given an integer 'limit' and a 2d array 'queries' of size 'n x 2'.
there are 'limit + 1' balls with distinct labels in the range '[0, limit]'.
initially, all balls are uncoloured. for every query in 'queries' that is of
the form '[x, y]', you makr ball 'x' with the colour 'y'. after each query,
you need to find the number of distinct colours among the balls. return an
array 'result' of length 'n' where 'result[i]' denotes the number of distinct
colours after the i'th query.
"""


class Solution(object):
    def queryResults(self, limit, queries):
        """
        :type limit: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        colours, cnt, ans = {}, {}, []
        for i in queries:
            ball, colour = i
            if ball in colours:
                prev = colours[ball]
                cnt[prev] -= 1
                if cnt[prev] == 0:
                    del cnt[prev]
            colours[ball] = colour
            cnt[colour] = cnt.get(colour, 0) + 1
            ans.append(len(cnt))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.queryResults(limit=4, queries=[[1, 4], [2, 5], [1, 3], [3, 4]]))
    print(obj.queryResults(limit=4, queries=[[0, 1], [1, 2], [2, 2], [3, 4], [4, 5]]))
