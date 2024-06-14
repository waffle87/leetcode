# 2125. Number of Laser Beams in a Bank

"""
anti-theft security devices are activated inside a bank. you are given a
0-indexed binary string array 'bank' representing the floor plan of the bank,
which is an 'm x n' 2d matrix. 'bank[i]' represents the i'th row, consisting
of '0's and '1's. '0' means the cell is empty, while '1' means the cell has a
security device. there is one laser beam between any two security devices if
both conditions are met. the two devices are located on two different rows
'r1' and 'r2', where 'r1 < r2'. for each row 'i' where 'r1 < i < r2' there
are no security devices in the i'th row. laser beams are independent. return
the total number of laser beams in the bank.
"""


class Solution(object):
    def numberOfBeams(self, bank):
        """
        :type bank: List[str]
        :rtype: int
        """
        pre, tot = 0, 0
        for row in bank:
            curr = self.calc(row)
            if curr == 0:
                continue
            tot += curr * pre
            pre = curr
        return tot

    def calc(self, s):
        return sum(int(c) for c in s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfBeams(bank=["011001", "000000", "010100", "001000"]))  # expect: 8
    print(obj.numberOfBeams(bank=["000", "111", "000"]))  # expect: 0
