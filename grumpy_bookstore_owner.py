# 1052. Grumpy Bookstore Owner

"""
there is a bookstore owner that has a store open for 'n' miniutes. every
minute some number of customers entre the store. you are given an integer
array 'customers' of size 'n' where 'customers[i]' is the number of the
customer that entres the store at the start of the i'th minute and all those
customers leave after the end of that minute. on some minutes, the bookstore
owner is grumpy. you are given an binary array 'grumpy' where 'grumpy[i]' is
1 if the bookstore owner is grumpy and zero otherwise. return the maximum
number of customers that can be satisfied throughout the day.
"""


class Solution(object):
    def maxSatisfied(self, customers, grumpy, minutes):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type minutes: int
        :rtype: int
        """
        total_satisfied, additional_satisifed, curr = 0, 0, 0
        for i in range(len(customers)):
            if grumpy[i] == 0:
                total_satisfied += customers[i]
                customers[i] = 0
        for i, time in enumerate(customers):
            curr += time
            if i >= minutes:
                curr -= customers[i - minutes]
            additional_satisifed = max(additional_satisifed, curr)
        return total_satisfied + additional_satisifed


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxSatisfied(
            customers=[1, 0, 1, 2, 1, 1, 7, 5],
            grumpy=[0, 1, 0, 1, 0, 1, 0, 1],
            minutes=3,
        )
    )
    print(obj.maxSatisfied(customers=[1], grumpy=[0], minutes=1))
