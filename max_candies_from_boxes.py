# 1298. Maximum Candies You Can Get from Boxes

"""
you have 'n' boxes labeled from 0 to 'n - 1'. you are given four arrays:
'status', 'candies', 'keys', and 'containedBoxes' where 'status[i]' is 1 if
the i'th box is open and 0 if the i'th box is closed. 'candies[i]' is the
number of candies in the i'th box. 'keys[i]' is a list of the labels of the
boxes that you can open after opening the i'th box. 'containedBoxes[i]' is a
list of the boxes you found inside the i'th box. you are given an integer
array 'initialBoxes' that contains the labels of the boxes you initially
have. you can take all the candies in any open box and you can use the keys
in it to open new boxes and you can also use the boxes you find in it. return
the maximum number of candies you can get following the rules.
"""


class Solution(object):
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        """
        :type status: List[int]
        :type candies: List[int]
        :type keys: List[List[int]]
        :type containedBoxes: List[List[int]]
        :type initialBoxes: List[int]
        :rtype: int
        """
        boxes = set(initialBoxes)
        dfs = [i for i in boxes if status[i]]
        for i in dfs:
            for j in containedBoxes[i]:
                boxes.add(j)
                if status[j]:
                    dfs.append(j)
            for j in keys[i]:
                if status[j] == 0 and j in boxes:
                    dfs.append(j)
                status[j] = 1
        return sum(candies[i] for i in dfs)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxCandies(
            status=[1, 0, 1, 0],
            candies=[7, 5, 4, 100],
            keys=[[], [], [1], []],
            containedBoxes=[[1, 2], [3], [], []],
            initialBoxes=[0],
        )
    )
    print(
        obj.maxCandies(
            status=[1, 0, 0, 0, 0, 0],
            candies=[1, 1, 1, 1, 1, 1],
            keys=[[1, 2, 3, 4, 5], [], [], [], [], []],
            containedBoxes=[[1, 2, 3, 4, 5], [], [], [], [], []],
            initialBoxes=[0],
        )
    )
