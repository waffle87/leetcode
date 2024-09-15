# 1054. Distant Barcodes
from collections import Counter

"""
in a warehouse, there is a row of barcodes where the i'th barcode is
'barcodes[i]'. rearrange the barcodes so that no two adjacent barcodes are
equal. you may return any answer, and it is guaranteed that an answer exists
"""


class Solution(object):
    def rearrangeBarcodes(self, barcodes):
        """
        :type barcodes: List[int]
        :rtype: List[int]
        """
        cnt = Counter(barcodes)
        barcodes.sort(key=lambda b: (cnt[b], b))
        barcodes[1::2], barcodes[::2] = (
            barcodes[0 : len(barcodes) / 2],
            barcodes[len(barcodes) / 2 :],
        )
        return barcodes


if __name__ == "__main__":
    obj = Solution()
    print(obj.rearrangeBarcodes(barcodes=[1, 1, 1, 2, 2, 2]))
    print(obj.rearrangeBarcodes(barcodes=[1, 1, 1, 1, 2, 2, 3, 3]))
