# 2483. Minimum Penalty for a Shop

"""
You are given the customer visit log of a shop represented by a 0-indexed
string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.

If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as
follows:

For every hour when the shop is open and no customers come, the penalty
increases by 1. For every hour when the shop is closed and customers come, the
penalty increases by 1.

Return the earliest hour at which the shop must be closed to incur a minimum
penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the
hour j.
"""


class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        n, a, b = len(customers), 0, 0
        prefix_a, prefix_b = [0], [0]
        for i in customers:
            a += i == "N"
            prefix_a.append(a)
        for i in reversed(customers):
            b += i == "Y"
            prefix_b.append(b)
        prefix_b.reverse()
        best_hour, _ = min(
            enumerate(i + j for i, j in zip(prefix_a, prefix_b)), key=lambda x: x[1]
        )
        return best_hour


if __name__ == "__main__":
    obj = Solution()
    print(obj.bestClosingTime(customers="YYNY"))
    print(obj.bestClosingTime(customers="NNNNN"))
    print(obj.bestClosingTime(customers="YYYY"))
