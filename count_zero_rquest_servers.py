# 2747. Count Zero Request Servers

"""
you are given an integer 'n' denoting the total number of servers and a 2d
0-indexed integer array 'logs' where 'logs[i] = [server_id, time]' denotes
that the server with id 'server_id' received a request at time 'time'. you
are also given an integer 'x' and a 0-indexed integer array 'queries'. return
a 0-indexed integer array 'arr' of length 'queries.len' where 'arr[i]'
represents the number of servers that did not receive any requests during the
time interval '[queries[i] - x, queries[i]]'. note that the time intervals
are inclusive.
"""


class Solution:
    def countServers(
        self, n: int, logs: list[list[int]], x: int, queries: list[int]
    ) -> list[int]:
        logs.sort(key=lambda x: x[1])
        q = sorted((i, j) for j, i in enumerate(queries))
        ans = [0] * len(queries)
        cnt = [0] * (n + 1)
        l, r, active = 0, 0, 0
        for i, j in q:
            while r < len(logs) and logs[r][1] <= i:
                id = logs[r][0]
                cnt[id] += 1
                if cnt[id] == 1:
                    active += 1
                r += 1
            while l < r and logs[l][1] < i - x:
                id = logs[l][0]
                cnt[id] -= 1
                if cnt[id] == 0:
                    active -= 1
                l += 1
            ans[j] = n - active
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countServers(n=3, logs=[[1, 3], [2, 6], [1, 5]], x=5, queries=[10, 11]))
    print(
        obj.countServers(
            n=3, logs=[[2, 4], [2, 1], [1, 2], [3, 1]], x=2, queries=[3, 4]
        )
    )
