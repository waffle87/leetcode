// 146. LRU Cache
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define DEBUG_MODE 0
#define REALLY_DEBUG 0

/*
 * design a data structure that follows the constraints of a least recently used
 * cache (LRU). implete the 'LRUCache' class. the functions 'get' and 'put' must
 * each run in O(1) average time complexity
 */

typedef struct QNode {
  struct QNode *prev, *next;
  unsigned bucket;
  int key;
  int data;
} QNode;

typedef struct Queue {
  unsigned count;
  unsigned capacity;
  QNode *front, *rear;
} Queue;

typedef struct Hash {
  int capacity;
  QNode **array; // array of pointers, or pointer to a range of pointers.
} Hash;

typedef struct LRUCache {
  unsigned int capacity;
  Queue *queue;
  Hash *hash;

} LRUCache;

struct QNode *newQNode(unsigned bucket) {
  struct QNode *temp = malloc(sizeof(struct QNode));
  temp->bucket = bucket;
  temp->prev = temp->next = NULL;
  return temp;
}

struct Queue *createQueue(int capacity) {
  struct Queue *queue = malloc(sizeof(struct Queue));
  queue->count = 0;
  queue->capacity = capacity;
  queue->front = queue->rear = NULL;
  return queue;
}

struct Hash *createHash(int capacity) {
  struct Hash *hash = malloc(sizeof(struct Hash));
  hash->capacity = capacity;
  hash->array = malloc(sizeof(struct QNode) * hash->capacity);
  for (int i = 0; i < hash->capacity; i++) {
    hash->array[i] = NULL;
  }
  return hash;
}

unsigned int hashfunc(unsigned capacity, int key);
void Enqueue(struct LRUCache *cache, struct Queue *queue, struct Hash *hash,
             int value, int key);
int searchCache(struct LRUCache *cache, int key);

void deQueue(Queue *queue) { // we could have return QNode but how would affect
                             // memory mgmt?

  if (DEBUG_MODE) {
    QNode *n = queue->front;
    int c = 0;
    QNode *p = n->prev;
    while (n != NULL) {
      if (REALLY_DEBUG)
        printf("QueueNode %d data = %d  n->prev:%d, n->next:%d\n", c, n->data,
               n->prev != NULL, n->next != NULL);
      c++;
      n = n->next;
    }
    if (REALLY_DEBUG)
      printf("next queue node is NULL\n");
    if (p == NULL)
      if (REALLY_DEBUG)
        printf("Front's prev points to null\n");
  }
  if (queue->rear == NULL)
    return;
  if (queue->front == queue->rear) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count--;
    return;
  }
  // QNode* temp = queue->rear;
  // LL two or more

  queue->rear = queue->rear->prev; // could be front if size = 2. That's fine
  if (queue->rear)
    queue->rear->next =
        NULL; // orphan the remaining, no need for memory freeing until it runs

  queue->count--;
  return;
  // free(temp); // This creates an AddressSanitizer error heap-use-after-free.
}

void dehash(Queue *queue, Hash *hash, unsigned bucket,
            int key) { // sets hash to null. Doesn't free
  unsigned test_bucket = hashfunc(
      hash->capacity, key); // should be same as passed in. for checking
  if (test_bucket != bucket) {
    if (REALLY_DEBUG)
      printf(
          "Warning, hash values coming out differently in dehash function\n");
  }
  if (hash->array[bucket]) { // we have to be certain this is right bucket
                             // adjusted for collision
    if (hash->array[bucket]->key == key) { // double check for debug
      // QNode* tmp = hash->array[bucket];
      if (REALLY_DEBUG)
        printf("Goodbye to hash[%d] with data %d\n", bucket,
               hash->array[bucket]->data);
      hash->array[bucket] = NULL;
      // free(tmp);
    } else if (REALLY_DEBUG)
      printf("entry found in hash but keys don't match. No action taken.\n");
    return;
  }
}

unsigned getGoodBucket(Hash *hash, int key) {
  unsigned try_bucket = hashfunc(hash->capacity, key);
  int hc = hash->capacity;
  if (REALLY_DEBUG)
    printf("try bucket and key %d , %d\n", try_bucket, key);
  if (hash->array[try_bucket] == NULL)
    return try_bucket;
  unsigned original_try = try_bucket;
  int c = 0;
  while (hash->array[try_bucket] != NULL) { // spot is taken
    // try_bucket = ((try_bucket + 1)) % hash->capacity;  //THIS IS NOT WORKING
    // FOR SOME REASON, STAYING AT 1 1 1 1 1 1 1 1 1 1 if (try_bucket ==
    // original_try)
    if (REALLY_DEBUG)
      printf("Try bucket %d and original try %d\n", try_bucket, original_try);
    try_bucket++;
    if (try_bucket == hc)
      try_bucket = 0;
    if (c == hc) { // no space found (erroneously I think)
      if (REALLY_DEBUG)
        printf("Sorry no space found in hash for new node, looped through "
               "everything (but should be found as hash entry should have been "
               "dequeued\n");
      return -1;
    }
    c++;
  }
  return try_bucket; // hope this works no collisions.
}

void EnqueueNewNode(struct LRUCache *cache, struct Queue *queue,
                    struct Hash *hash, int value, int key) {
  // remember queue was just dequeueed
  QNode *temp = newQNode(0);
  temp->data = value; // obviously have to put the value in there
  temp->key = key;    // needed for handling hash collisions
  int goodBucket = getGoodBucket(hash, key);
  if (REALLY_DEBUG)
    printf("GoodBucket to hash index on %d\n", goodBucket);
  temp->bucket = goodBucket; // Get it a bucket
  temp->prev = NULL;         // because it will go at head
  temp->next = queue->front;

  // attach node
  if (queue->rear == NULL) { // should mean queue is empty but double check
    if (queue->front != NULL)
      if (REALLY_DEBUG)
        printf("Rear null but head not, error\n");
    queue->rear = temp;
    queue->front = temp;
  } else if (queue->front == queue->rear) {
    queue->front = temp;
    queue->front->next = queue->rear;
    queue->front->next->prev = queue->front;
  } else { // min capacity 3
    queue->front->prev = temp;
    queue->front = temp;
  }
  hash->array[goodBucket] = temp; // pass to hash
  queue->count++;
  return;
}

void MoveNodeToFront(struct LRUCache *cache, struct Queue *queue,
                     struct Hash *hash, int value, int key,
                     int bucket) {  // can happen on get requests
  QNode *tmp = hash->array[bucket]; // pointer to the node in question
  if (tmp == queue->front) { // Already at head, don't need to do anything.
    return;
  } else if (queue->front ==
             queue->rear) { // shouldn't be triggered based on above condition.
    if (REALLY_DEBUG)
      printf("This should never run. Should be handled by the above condition. "
             "Implying error\n");
    if (REALLY_DEBUG)
      printf("Q count should be 1. Queue count is %d\n", queue->count);
    return;
  } else // standard case
  { // if in hash, should(!!) also be in the queue. If not, VERY BAD. Not super
    // easy to check
    if (REALLY_DEBUG)
      printf("bucket is still %d and key is %d (1)\n", bucket, key);
    if (tmp == NULL)
      if (REALLY_DEBUG)
        printf("QNode not found in Enqueue function bucket\n");
    if (tmp->prev == NULL)
      if (REALLY_DEBUG)
        printf(
            "Temp previous is null but should not be (because not at head)\n");

    if (REALLY_DEBUG)
      printf("hash[bucket]->data is %d\n", tmp->data);

    tmp->prev->next = tmp->next;
    if (tmp != queue->rear)
      tmp->next->prev = tmp->prev; // SEG FAULT if tmp is rear!!
    if (tmp == queue->rear)
      queue->rear = tmp->prev;
    tmp->prev->next = tmp->next;
    queue->front->prev = tmp;
    tmp->next = queue->front;
    queue->front =
        tmp; // queue front could point to queue->rear, or to an intermediary
    queue->front->prev = NULL; // Now the node in question is right pointed
    return; // queue count doesn't change. we're done? Will it work?
  }
  return;
}

void Enqueue(struct LRUCache *cache, struct Queue *queue, struct Hash *hash,
             int value, int key) {
  int bucket = searchCache(
      cache, key); // bucket can be -1 not found or bucket where exists
  if (REALLY_DEBUG)
    printf("Enqueuing key %d and bucket is: %d\n", key, bucket);

  if (queue->count == queue->capacity && bucket < 0) {
    if (REALLY_DEBUG)
      printf("Ready to dequeue rear and add new node\n");
    unsigned hashbucket = queue->rear->bucket;
    deQueue(queue);
    dehash(queue, hash, hashbucket, hash->array[hashbucket]->key);
  }

  if (bucket == -1) {
    EnqueueNewNode(cache, queue, hash, value, key);
    return;
  } else if (bucket >= 0) { // explicitly double checked, existing in cache
    MoveNodeToFront(cache, queue, hash, value, key, bucket);
    return;
  }
}

unsigned int hashfunc(unsigned capacity, int key) {
  unsigned int provisional_bucket = (key * 353) % capacity;
  return provisional_bucket; // may need adjustment (linear probing)
}

int searchCache(struct LRUCache *cache, int key) {
  // look in hash for item of "key"; double check key=key in case of collision
  unsigned test_bucket = hashfunc(cache->capacity, key);
  if (REALLY_DEBUG)
    printf("test bucket %d\n ", test_bucket); // 9
  if (cache->hash->array[test_bucket] != NULL) {
    if (cache->hash->array[test_bucket]->key == key) {
      return test_bucket; // simplest case, returns location
    } else {              // linear probe time
      int cap = cache->capacity;
      unsigned original_test_bucket = test_bucket;
      while (cache->hash->array[test_bucket] != NULL) {
        test_bucket = ((test_bucket + 1) % cap);
        if (test_bucket ==
            original_test_bucket) { // back to start, avoid infinite looping
          if (REALLY_DEBUG)
            printf("Probed hash, object not found. returning -1\n");
          return -1; // returns -1
        }
        if (cache->hash->array[test_bucket] != NULL &&
            cache->hash->array[test_bucket]->key == key)
          return test_bucket;
      }
    }
  } else { // just have else for good measure. Simply not found in array
    return -1;
  }
  return -1;
}
// Declarations
void freeQueue(Queue *queue);
void freeHash(Hash *hash);
void freeQNode(QNode *qnode);
void printQueueData(LRUCache *cache, char *op);

struct LRUCache *lRUCacheCreate(int capacity) {
  struct LRUCache *cache = malloc(sizeof(struct LRUCache));
  cache->capacity = capacity;
  cache->queue = createQueue(capacity);
  cache->hash = createHash(capacity);
  return cache;
} // THIS IS WHERE THE ERROR HAPPEN(ED) -- fixed- (sort of), but not understood

int lRUCacheGet(struct LRUCache *obj, int key) {
  if (REALLY_DEBUG)
    printf("\nGetting key %d\n", key);
  int location = searchCache(obj, key);
  if (location >= 0) { // found, else searchCache returns -1
    // printf("location found at %d\n", location);  // PRINTF
    struct QNode *tempNode =
        obj->hash->array[location]; // found in hash  SEG FAULT HERE!!
    int tempData = tempNode->data;  // Preserve Data before enqeueing
    Enqueue(obj, obj->queue, obj->hash, tempData,
            key); // TODO redundantly recalculates hash. Should be separate
                  // funtion "reorder" or "move_to_head"?
    return tempData;
  } else {
    return location; // is -1 already
  }
}

void lRUCachePut(struct LRUCache *obj, int key, int value) {
  int bucket = searchCache(obj, key); // already checks that key is right
  if (bucket >= 0) {
    int existing_value = obj->hash->array[bucket]->data;
    if (value != existing_value) {
      obj->hash->array[bucket]->data = value;
    }
    MoveNodeToFront(obj, obj->queue, obj->hash, value, key, bucket);
    return;
  }
  // unsigned bucket = hashfunc(obj->capacity, key); // gets original bucket
  if (REALLY_DEBUG)
    printf("\nPutting key %d value %d\n", key, value);
  Enqueue(obj, obj->queue, obj->hash, value,
          key); // also dequeues/dehashes, adds to hash, moves to front
}

void lRUCacheFree(struct LRUCache *obj) {
  freeQueue(obj->queue);
  freeHash(obj->hash);
  free(obj);
  return;
}

void freeQueue(struct Queue *queue) {
  struct QNode *curr = queue->front;
  while (curr) {
    QNode *tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  free(queue);
}
void freeHash(
    Hash *hash) { // if you free the nodes associated with the hash in the
                  // linked list, you also free them in the hash right? Because
                  // they're pointed at. They'll point at null or rather out of
                  // range things (seg fault territory?)
  free(hash);
}
void freeQNode(QNode *qnode);

void printQueueData(LRUCache *cache, char *op) {
  QNode *n = cache->queue->front;
  int c = 0;
  QNode *p = n->prev;
  while (n != NULL) {
    printf("QC:%d ", cache->queue->capacity);
    printf("QueueNode %d k:%d data = %d  n->prev:%d, n->next:%d\n", c, n->key,
           n->data, n->prev != NULL, n->next != NULL);
    c++;
    n = n->next;
  }
  if (p == NULL)
    printf("Front's prev points to null. ");
  printf("next queue node is NULL\n");
  QNode *r = cache->queue->rear;
  if (r)
    printf("Queue Rear exists:%d and its data: %d\n", r != NULL, r->data);
}

void printCurrentState(LRUCache *cache, char *op) {
  if (DEBUG_MODE) {
    printf("\nCURRENT STATE after %s::::::::::\n", op);
    printf("cache has capacity of %d\n", cache->capacity);
    printQueueData(cache, op);
    for (int i = 0; i < cache->capacity; i++) {
      if (cache->hash->array[i] != NULL)
        printf("Hashtable[%d] = %d\n", i, cache->hash->array[i]->data);
    }
  }
}
