# 1701. Average Waiting Time

"""
there is a restaurant with a single chef. you are given an array 'customers'
where 'customers[i] = [arrivali, timei]'. where 'arrivali' is the arrival
time of the i'th customer. the arrival times are sorted in non decreasing
order, and 'timei' is the time needed to prepare the order of the i'th
customer. when a customer arrives, he gives the chef his order and the chef
prepares it. return the average waiting time of all customers. solutions
within 10^-5 from actually answer are considered accepted
"""


class Solution(object):
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        wait, curr = 0, 0
        for c in customers:
            curr = max(curr, c[0]) + c[1]
            wait += curr - c[0]
        avg = wait / len(customers)
        return avg


if __name__ == "__main__":
    obj = Solution()
    print(obj.averageWaitingTime(customers=[[1, 2], [2, 5], [4, 3]]))
    print(obj.averageWaitingTime(customers=[[5, 2], [5, 4], [10, 3], [20, 1]]))
