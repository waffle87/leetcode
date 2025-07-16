# 388. Longest Absolute File Path

"""
suppose we have a file system that stores both files and directories. every
file and directory has a unique absolute path in the file system which is the
order of directories that must be opened to reach the file/directory it self,
all concatenated by '/'s. each directory name consists of letters, digits,
and/or spaces. each filename is of the form 'name.extension', where 'name'
and 'extension' consist of letters, digits, and/or spaces. given a string
'input' representing the file system in the explained format, return the
length of the longest absolute path to a file in the abstracted file system.
if there ino file in the system, return 0
"""


class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        max_len, path_len = 0, {0: 0}
        for i in input.splitlines():
            name = i.lstrip("\t")
            depth = len(i) - len(name)
            if "." in name:
                max_len = max(max_len, path_len[depth] + len(name))
            else:
                path_len[depth + 1] = path_len[depth] + len(name) + 1
        return max_len


if __name__ == "__main__":
    obj = Solution()
    print(obj.lengthLongestPath(input="dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"))
    print(
        obj.lengthLongestPath(
            input="dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
        )
    )
    print(obj.lengthLongestPath(input="a"))
