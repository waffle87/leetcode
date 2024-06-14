# 806. Number of Lines To Write String

"""
given a string 's' of lowercase english letters and an array 'widths'
denoting how many pixels wide each lowercase english letter is. specifically,
'widths[0]' is the width of 'a', 'widths[1]' is the width of 'b', and so on.
you are trying to write 's' across several lines, where each line is no
longer than 100 pixels. starting at the beginning of 's', write as many
letters on the first line such that the total width does not exceed 100
pixels. then from where you topped in 's', continue writing as many letters
as you can on the second line. continue this process until you have written
all of 's'.
"""


class Solution(object):
    def numberOfLines(self, widths, s):
        """
        :type widths: List[int]
        :type s: str
        :rtype: List[int]
        """
        ans, curr = 1, 0
        for i in s:
            width = widths[ord(i) - ord("a")]
            ans += 1 if curr + width > 100 else 0
            curr = width if curr + width > 100 else curr + width
        return [ans, curr]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.numberOfLines(
            widths=[
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
            ],
            s="abcdefghijklmnopqrstuvwxyz",
        )
    )
    print(
        obj.numberOfLines(
            widths=[
                4,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
                10,
            ],
            s="bbbcccdddaaa",
        )
    )
