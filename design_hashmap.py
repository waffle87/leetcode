# 706. Design HashMap

"""
design a hashmap without usin any built-in hash table libraries. implement
the 'MyHashMap' class:
- myHashMapCreate() initialises the object with an empty map
- put() inserts a key, value pair into the hashmap. if the key already exists
in the map, update the corresponding value
- get() returns the value to which the specified key is mapped, or -1 if this
map contains no mapping for the key
- remove() removes the key and its corresponding value if the map contains
the mapping for the key
"""


class MyHashMap(object):
    def __init__(self):
        self.data = [None] * 1000001

    def put(self, key, value):
        self.data[key] = value

    def get(self, key):
        value = self.data[key]
        return value if value != None else -1

    def remove(self, key):
        self.data[key] = None
