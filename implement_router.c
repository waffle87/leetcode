// 3508. Implement Router
#include "leetcode.h"

/*
 * design a data structure that can efficiently manage data packets in a network
 * router. each data packet consists of the following attributes: 'source',
 * 'destination', 'timestamp'. note that the queries for 'routerAddPacket' will
 * be made in increasing order of timestamp
 */

#define HASH_SIZE 200925

struct packet {
  int source;
  int destination;
  int timestamp;
  struct packet *next;
};

struct key_node {
  char *key;
  struct key_node *next;
};

struct destination_info {
  int *timestamps;
  int size;
  int capacity;
};

typedef struct {
  int memoryLimit;
  int size;
  struct packet *head;
  struct packet *tail;
  struct key_node *packet_set[HASH_SIZE];
  struct destination_info *dest_map[HASH_SIZE];
} Router;

unsigned int hash_str(const char *s) {
  unsigned int res = 0;
  while (*s)
    res = res * 31 + (unsigned char)(*s++);
  return res % HASH_SIZE;
}

unsigned int hash_int(int x) { return ((unsigned int)x) % HASH_SIZE; }

char *make_key(int src, int dst, int ts) {
  char *res = (char *)malloc(32 * sizeof(char));
  sprintf(res, "%d-%d-%d", src, dst, ts);
  return res;
}

bool key_exists(Router *obj, const char *key) {
  unsigned int hash = hash_str(key);
  struct key_node *curr = obj->packet_set[hash];
  while (curr) {
    if (!strcmp(curr->key, key))
      return true;
    curr = curr->next;
  }
  return false;
}

void key_insert(Router *obj, char *key) {
  unsigned int hash = hash_str(key);
  struct key_node *node = (struct key_node *)malloc(sizeof(struct key_node));
  node->key = key;
  node->next = obj->packet_set[hash];
  obj->packet_set[hash] = node;
}

void key_remove(Router *obj, const char *key) {
  unsigned int hash = hash_str(key);
  struct key_node *curr = obj->packet_set[hash], *prev = NULL;
  while (curr) {
    if (!strcmp(curr->key, key)) {
      if (prev)
        prev->next = curr->next;
      else
        obj->packet_set[hash] = curr->next;
      free(curr->key);
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

struct destination_info *get_dest(Router *obj, int dst) {
  unsigned int hash = hash_int(dst);
  return obj->dest_map[hash];
}

struct destination_info *create_dest(void) {
  struct destination_info *obj =
      (struct destination_info *)malloc(sizeof(struct destination_info));
  obj->timestamps = (int *)malloc(8 * sizeof(int));
  obj->size = 0;
  obj->capacity = 0;
  return obj;
}

void add_dest_timestamp(Router *obj, int dst, int ts) {
  unsigned int hash = hash_int(dst);
  struct destination_info *d = obj->dest_map[hash];
  if (!d) {
    d = create_dest();
    obj->dest_map[hash] = d;
  }
  if (d->size == d->capacity) {
    d->capacity *= 2;
    d->timestamps = (int *)realloc(d->timestamps, d->capacity * sizeof(int));
  }
  d->timestamps[d->size++] = ts;
}

void remove_dest_timestamp(Router *obj, int dst, int ts) {
  unsigned int hash = hash_int(dst);
  struct destination_info *d = obj->dest_map[hash];
  if (!d)
    return;
  int i;
  for (int i = 0; i < d->size; i++)
    if (d->timestamps[i] == ts)
      break;
  if (i == d->size)
    return;
  for (int j = i; j < d->size; j++)
    d->timestamps[j] = d->timestamps[j + 1];
  d->size--;
  if (!d->size) {
    free(d->timestamps);
    free(d);
    obj->dest_map[hash] = NULL;
  }
}

int lower_bound(int *arr, int n, int target) {
  int l = 0, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] < target)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int upper_bound(int *arr, int n, int target) {
  int l = 0, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] <= target)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

Router *routerCreate(int memoryLimit) {
  Router *obj = (Router *)malloc(sizeof(Router));
  obj->memoryLimit = memoryLimit;
  obj->size = 0;
  obj->head = obj->tail = NULL;
  memset(obj->packet_set, 0, sizeof(obj->packet_set));
  memset(obj->dest_map, 0, sizeof(obj->dest_map));
  return obj;
}

bool routerAddPacket(Router *obj, int source, int destination, int timestamp) {
  char *key = make_key(source, destination, timestamp);
  if (key_exists(obj, key)) {
    free(key);
    return false;
  }
  if (obj->size == obj->memoryLimit) {
    struct packet *old = obj->head;
    obj->head = old->next;
    if (!obj->head)
      obj->tail = NULL;
    obj->size--;
    char *prev_key = make_key(old->source, old->destination, old->timestamp);
    key_remove(obj, prev_key);
    free(prev_key);
    remove_dest_timestamp(obj, old->destination, old->timestamp);
    free(old);
  }
  struct packet *p = (struct packet *)malloc(sizeof(struct packet));
  p->source = source;
  p->destination = destination;
  p->timestamp = timestamp;
  p->next = NULL;
  if (!obj->tail)
    obj->head = obj->tail = p;
  else {
    obj->tail->next = p;
    obj->tail = p;
  }
  obj->size++;
  key_insert(obj, key);
  add_dest_timestamp(obj, destination, timestamp);
  return true;
}

int *routerForwardPacket(Router *obj, int *retSize) {
  if (!obj->head) {
    *retSize = 0;
    return NULL;
  }
  struct packet *p = obj->head;
  obj->head = p->next;
  if (!obj->head)
    obj->tail = NULL;
  obj->size--;
  char *key = make_key(p->source, p->destination, p->timestamp);
  key_remove(obj, key);
  free(key);
  remove_dest_timestamp(obj, p->destination, p->timestamp);
  int *res = (int *)malloc(3 * sizeof(int));
  res[0] = p->source;
  res[1] = p->destination;
  res[2] = p->timestamp;
  *retSize = 3;
  free(p);
  return res;
}

int routerGetCount(Router *obj, int destination, int startTime, int endTime) {
  unsigned int hash = hash_int(destination);
  struct destination_info *d = obj->dest_map[hash];
  if (!d)
    return 0;
  int l = lower_bound(d->timestamps, d->size, startTime);
  int r = upper_bound(d->timestamps, d->size, endTime);
  return r - l;
}

void routerFree(Router *obj) {
  while (obj->head) {
    struct packet *tmp = obj->head;
    obj->head = obj->head->next;
    free(tmp);
    for (int i = 0; i < HASH_SIZE; i++) {
      struct key_node *key = obj->packet_set[i];
      while (key) {
        struct key_node *t = key;
        key = key->next;
        free(t->key);
        free(t);
      }
      struct destination_info *d = obj->dest_map[i];
      if (d) {
        free(d->timestamps);
        free(d);
      }
    }
  }
  free(obj);
}

int main() {
  Router *obj = routerCreate(3);
  printf("%d\n", routerAddPacket(obj, 1, 4, 90));  // expect: 1
  printf("%d\n", routerAddPacket(obj, 2, 5, 90));  // expect: 1
  printf("%d\n", routerAddPacket(obj, 1, 4, 90));  // expect: 0
  printf("%d\n", routerAddPacket(obj, 3, 5, 95));  // expect: 1
  printf("%d\n", routerAddPacket(obj, 4, 5, 105)); // expect: 1
  int rs, *rfp = routerForwardPacket(obj, &rs);
  for (int i = 0; i < rs; i++)
    printf("%d ", rfp[i]); // expect: 2 5 90
  free(rfp);
  printf("%d\n", routerAddPacket(obj, 5, 2, 110));  // expect: 1
  printf("%d\n", routerGetCount(obj, 5, 100, 110)); // expect:
  routerFree(obj);
}
