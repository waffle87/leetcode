# 1024. Video Stitching

"""
you are given a series of video clips from a sporting event that lasted
'time' seconds. these video clips can be overlapping with eachother and have
varying lengths. each video clip is described by an array 'clips' where
'clips[i] = [start_i, n_i]' indicates that the i'th clip started at
'start_i' n 'n_i'. we can cut these clips into segments freely. return
the minimum number of clips needed so that we can cut the clips needed so
that we can cut the clips into segments that cover the entire sporting event
'[0, time]'. if the task is impossible, return -1
"""


class Solution(object):
    def videoStitching(self, clips, time):
        """
        :type clips: List[List[int]]
        :type time: int
        :rtype: int
        """
        n, m, ans = -1, 0, 0
        for i, j in sorted(clips):
            if m >= time or i > m:
                break
            elif n < i <= m:
                ans, n = ans + 1, m
            m = max(m, j)
        return ans if m >= time else -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.videoStitching(
            clips=[[0, 2], [4, 6], [8, 10], [1, 9], [1, 5], [5, 9]], time=10
        )
    )
    print(obj.videoStitching(clips=[[0, 1], [1, 2]], time=5))
    print(
        obj.videoStitching(
            clips=[
                [0, 1],
                [6, 8],
                [0, 2],
                [5, 6],
                [0, 4],
                [0, 3],
                [6, 7],
                [1, 3],
                [4, 7],
                [1, 4],
                [2, 5],
                [2, 6],
                [3, 4],
                [4, 5],
                [5, 7],
                [6, 9],
            ],
            time=9,
        )
    )
