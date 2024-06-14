# 2332. The Latest Time to Catch a Bus

"""
given a 0-indexed array 'buses' of length 'n' where 'buses[i]' represents the
departure time of the i'th bus. you are also given a 0-indexed array
'passengers' of length 'm' where 'passengers[j]' represents the arrival time
of the j'th passenger. all bus departure times are unique. all passenger
arrival times are unique. return the latest time you may arrive at the bus
station to catch a bus. you cannot arrive at the same time as another
passenger.
"""


class Solution(object):
    def latestTimeCatchTheBus(self, buses, passengers, capacity):
        """
        :type buses: List[int]
        :type passengers: List[int]
        :type capacity: int
        :rtype: int
        """
        buses.sort()
        passengers.sort()
        i, j = 0, 0
        n, m = len(buses), len(passengers)
        curr_cap = 0
        while i < n:
            curr_cap = 0
            while j < m and curr_cap < capacity and passengers[j] <= buses[i]:
                j += 1
                curr_cap += 1
            if i == n - 1:
                j -= 1
                if curr_cap < capacity:
                    time = buses[i]
                    while j >= 0 and time == passengers[j]:
                        time -= 1
                        j -= 1
                    return time
                else:
                    time = passengers[j] - 1
                    j -= 1
                    while j <= 0 and time == passengers[j]:
                        time -= 1
                        j -= 1
                    return time
            i += 1
        return buses[-1]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.latestTimeCatchTheBus(
            buses=[10, 20], passengers=[2, 17, 18, 19], capacity=2
        )
    )
    print(
        obj.latestTimeCatchTheBus(
            buses=[20, 30, 10], passengers=[19, 13, 26, 4, 25, 11, 21], capacity=2
        )
    )
