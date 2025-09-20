# 3508. Implement Router
import bisect
from collections import defaultdict, deque

"""
design a data structure that can efficiently manage data packets in a network
router. each data packet consists of the following attributes: 'source',
'destination', 'timestamp'. note that the queries for 'routerAddPacket' will
be made in increasing order of timestamp
"""


class Router(object):
    def __init__(self, memoryLimit):
        """
        :type memoryLimit: int
        """
        self.size = memoryLimit
        self.packets = {}
        self.counts = defaultdict(list)
        self.queue = deque()

    def addPacket(self, source, destination, timestamp):
        """
        :type source: int
        :type destination: int
        :type timestamp: int
        :rtype: bool
        """
        key = self._encode(source, destination, timestamp)
        if key in self.packets:
            return False
        if len(self.packets) >= self.size:
            self.forwardPacket()
        self.packets[key] = [source, destination, timestamp]
        self.queue.append(key)
        self.counts[destination].append(timestamp)
        return True

    def forwardPacket(self):
        """
        :rtype: List[int]
        """
        if not self.packets:
            return []
        key = self.queue.popleft()
        packet = self.packets.pop(key)
        dest = packet[1]
        self.counts[dest].pop(0)
        return packet

    def getCount(self, destination, startTime, endTime):
        """
        :type destination: int
        :type startTime: int
        :type endTime: int
        :rtype: int
        """
        timestamps = self.counts.get(destination, [])
        if not timestamps:
            return 0
        left = bisect.bisect_left(timestamps, startTime)
        right = bisect.bisect_right(timestamps, endTime)
        return right - left

    def _encode(self, source, destination, timestamp):
        return (source << 40) | (destination << 20) | timestamp


if __name__ == "__main__":
    obj = Router(3)
    print(obj.addPacket(1, 4, 90))
    print(obj.addPacket(2, 5, 90))
    print(obj.addPacket(1, 4, 90))
    print(obj.addPacket(3, 5, 95))
    print(obj.addPacket(4, 5, 105))
    print(obj.forwardPacket())
    print(obj.addPacket(5, 2, 110))
    print(obj.getCount(5, 100, 110))
