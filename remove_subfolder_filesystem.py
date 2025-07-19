# 1233. Remove Sub-Folders from the Filesystem

"""
given a list of folders 'folder', return the folders after removing all the
sub-folders in those folders. you may return the answer in any order. if a
'folder[i]' is located within another 'folder[j]', it is called a sub-folder
of it. a sub-folder of 'folder[j]' must start with 'folder[j]', followed by
'/'. the format of a path is one ormore concatenated strings of the form: '/'
followed by one or more lowercase english letters.
"""


class Solution(object):
    def removeSubfolders(self, folder):
        """
        :type folder: List[str]
        :rtype: List[str]
        """
        n = len(folder)
        folder.sort()
        ans = []
        ans.append(folder[0])
        for i in range(1, n):
            last = ans[-1]
            if not folder[i].startswith(last + "/"):
                ans.append(folder[i])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeSubfolders(folder=["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]))
    print(obj.removeSubfolders(folder=["/a", "/a/b/c", "/a/b/d"]))
    print(obj.removeSubfolders(folder=["/a/b/c", "/a/b/ca", "/a/b/d"]))
