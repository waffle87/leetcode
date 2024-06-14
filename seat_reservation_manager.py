# 1845. Seat Reservation Manager

"""
design a system that manages the reservation state of 'n' seats that are
numbered 1 to 'n'. implement the 'SeatManager' class
- seatManagerCreate(int n) initalises a SeatManager object that will manage
'n' seats numbered from 1 to 'n'. all seats are initially available
- seatManagerReserve() fetches the smallest-numbered unreserved seat,
reserves it, and returns its number
- seatManagerUnreserve(int seat_num) unreserves the seat with the given
'seat_num'
"""

import heapq


class SeatManager(object):
    def __init__(self, n):
        self.heap = list(range(1, n + 1))

    def reserve(self):
        return heapq.heappop(self.heap)

    def unreserve(self, seatNumber):
        heapq.heappush(self.heap, seatNumber)
