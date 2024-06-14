// 460. LFU Cache
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_CACHE_ITEM 3192
#define MAX_FREQ 128

// https://en.wikipedia.org/wiki/Least_frequently_used
// http://dhruvbird.com/lfu.pdf

typedef struct LFUCache LFUCache;
typedef struct LFUCache {
  int freq;
  int val;
  bool valid;
  LFUCache *prev;
  LFUCache *next;
} LFUCache;

struct Freq {
  LFUCache *head;
  LFUCache *tail;
};

struct CacheData {
  int capacity;
  int size;
  int freqIdx;
  LFUCache *cache;
  struct Freq *fm;
};

inline void *cacheAlloc(int capacity);
inline void cacheDealloc(void *cache);
inline void refreshCache(LFUCache *item, struct CacheData *cdata,
                         bool newEntry);

LFUCache *lFUCacheCreate(int capacity) { return cacheAlloc(capacity); }

int lFUCacheGet(LFUCache *obj, int key) {
  struct CacheData *cdata = (void *)obj;
  LFUCache *item = &cdata->cache[key];
  if (cdata->capacity <= 0 || !item->valid)
    return -1;
  refreshCache(item, cdata, false);
  return item->val;
}

void lFUCachePut(LFUCache *obj, int key, int value) {
  struct CacheData *cdata = (void *)obj;
  LFUCache *item = &cdata->cache[key];
  if (cdata->capacity <= 0 || key >= MAX_CACHE_ITEM)
    return;
  refreshCache(item, cdata, !item->valid);
  item->val = value;
}

void lFUCacheFree(LFUCache *obj) { cacheDealloc(obj); }

inline void *cacheAlloc(int capacity) {
  if (capacity > MAX_CACHE_ITEM)
    return NULL;
  struct CacheData *cdata = calloc(1, sizeof(*cdata));
  cdata->capacity = capacity;
  cdata->cache = calloc(1, sizeof(LFUCache[MAX_CACHE_ITEM]));
  cdata->fm = calloc(1, sizeof(struct Freq[MAX_FREQ]));
  return cdata;
}

inline void cacheDealloc(void *cache) {
  struct CacheData *cdata = cache;
  free(cdata->cache);
  free(cdata->fm);
  free(cdata);
}

inline void fixNode(LFUCache *item) {
  LFUCache **prev = &item->prev, **next = &item->next;
  *prev ? (*prev)->next = *next : 0;
  *next ? (*next)->prev = *prev : 0;
}

inline void fixHeadTailFreq(LFUCache *item, struct CacheData *cdata) {
  struct Freq *fm = &cdata->fm[item->freq];
  LFUCache **head = &fm->head, **tail = &fm->tail;
  item == *head ? *head = item->next : 0;
  item == *tail ? *tail = item->prev : 0;
  item->freq == cdata->freqIdx && !fm->head ? cdata->freqIdx++ : 0;
}

inline void fixHeadTail(LFUCache *item, struct CacheData *cdata) {
  struct Freq *fm = &cdata->fm[++item->freq];
  item->prev = NULL;
  item->next = fm->head;
  fm->head = fm->head ? fm->head->prev = item : (fm->tail = item);
}

inline void evictFreqNode(struct CacheData *cdata) {
  struct Freq *fm = &cdata->fm[cdata->freqIdx];
  LFUCache *lu = fm->tail;
  lu->prev ? lu->prev->next = NULL : 0;
  lu->freq = 0;
  lu->valid = false;
  !(fm->tail = lu->prev) ? fm->head = NULL : 0;
  lu->prev = lu->next = NULL;
}

inline void refreshCache(LFUCache *item, struct CacheData *cdata,
                         bool newEntry) {
  if (newEntry)
    if (cdata->size == cdata->capacity)
      evictFreqNode(cdata);
    else
      cdata->size++;
  else {
    fixNode(item);
    fixHeadTailFreq(item, cdata);
  }
  fixHeadTail(item, cdata);
  if (!cdata->freqIdx || cdata->freqIdx > item->freq)
    cdata->freqIdx = item->freq;
  item->valid = true;
}
