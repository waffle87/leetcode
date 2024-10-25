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
        folder.sort(key=lambda x: len(x))
        vis = set()
        for i in folder:
            for j in range(2, len(i)):
                if i[j] == "/" and i[:j] in vis:
                    break
            else:
                vis.add(i)
        return list(vis)


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeSubfolders(folder=["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]))
    print(obj.removeSubfolders(folder=["/a", "/a/b/c", "/a/b/d"]))
    print(obj.removeSubfolders(folder=["/a/b/c", "/a/b/ca", "/a/b/d"]))
