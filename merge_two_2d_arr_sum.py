# 2570. Merge Two 2D Arrays by Summing Values

"""
you are given two 2d integer arrays 'nums1' and 'nums2'. 'nums1[i] = [id_i,
val_i]' indicate that the number with id 'id_i' has a value equal. to
'val_i'. 'nums2[i] = [id_i, val_i]' indicates that the number with the id
'id_i' has a value equal to 'val_i'. each array contains unique ids and is
sorted in ascending order by id. merge the two arrays into one array that is
sorted in ascending order by id. return the resulting array. the returned
array must be sorted in ascending order by id.
"""


class Solution(object):
    def mergeArrays(self, nums1, nums2):
        """
        :type nums1: List[List[int]]
        :type nums2: List[List[int]]
        :rtype: List[List[int]]
        """
        i, j, ans = 0, 0, []
        n1, n2 = len(nums1), len(nums2)
        while i < n1 or j < n2:
            if i < n1 and (j >= n2 or nums1[i][0] < nums2[j][0]):
                ans.append(nums1[i])
                i += 1
            elif j < n2 and (i >= n1 or nums1[i][0] > nums2[j][0]):
                ans.append(nums2[j])
                j += 1
            else:
                ans.append([nums1[i][0], nums1[i][1] + nums2[j][1]])
                i += 1
                j += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.mergeArrays(nums1=[[1, 2], [2, 3], [4, 5]], nums2=[[1, 4], [3, 2], [4, 1]])
    )
    print(obj.mergeArrays(nums1=[[2, 4], [3, 6], [5, 5]], nums2=[[1, 3], [4, 3]]))
