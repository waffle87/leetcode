# 332. Reconstruct Itinerary
from collections import defaultdict

"""
given a list of airline 'tickets' where 'tickets[i] = [from[i], to[i]]'
represents the departure and the arrival airpots of one flight. reconstruct
the itinerary in order and return it. all of the tickets belong to a man who
departs from "JFK", thus, the itinerary must begin with "JFK". if there are
multiple valid entires, you should return the itinerary that has the smallest
lexical order when read as a string. you may assume all tickets form at least
one valid itinerary. you must all the tickets once and only once.
"""


class Solution(object):
    def findItinerary(self, tickets):
        targets = collections.defaultdict(list)
        for a, b in sorted(tickets)[::-1]:
            targets[a] += b
        route = []

        def visit(airport):
            while targets[airport]:
                visit(targets[airport].pop())
            route.append(airport)

        visit("JFK")
        return route[::-1]
