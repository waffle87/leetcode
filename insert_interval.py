# 57. Insert Interval


class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        ans, i = [], -1
        for i, (x, y) in enumerate(intervals):
            if y < newInterval[0]:
                ans.append([x, y])
            elif newInterval[1] < x:
                i -= 1
                break
            else:
                newInterval[0] = min(newInterval[0], x)
                newInterval[1] = max(newInterval[1], y)
        return ans + [newInterval] + intervals[i + 1 :]


if __name__ == "__main__":
    obj = Solution()
    print(obj.insert(intervals=[[1, 3], [6, 9]], newInterval=[2, 5]))
    print(
        obj.insert(
            intervals=[[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval=[4, 8]
        )
    )
