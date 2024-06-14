# 2424. Longest Uploaded Prefix

"""
given a string of 'n' videos, each represented by a distinct number from 1 to
n that you need to upload to a server. you need to implement a data structure
that calculates the length of the longest uploaded prefix at various points
in the upload process. we consider i to be uploaded prefix if all videos in
the range 1 to i inclusive have been uploaded to the server. the longest
uploaded prefix is the maximum value of 'i' that satisfies this definition.
"""


class LUPrefix(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self._longest = 0
        self._nums = set()

    def upload(self, video):
        """
        :type video: int
        :rtype: None
        """
        self._nums.add(video)
        while self._longest + 1 in self._nums:
            self._longest += 1

    def longest(self):
        """
        :rtype: int
        """
        return self._longest


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
if __name__ == "__main__":
    obj = LUPrefix(4)
    obj.upload(3)
    print(obj.longest())  # expect: 0
    obj.upload(1)
    print(obj.longest())  # expect: 1
    obj.upload(2)
    print(obj.longest())  # expect: 3
