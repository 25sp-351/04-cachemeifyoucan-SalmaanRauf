#include <stdlib.h>
#include <stdio.h>
#include "cache.h"
#define CACHE_SIZE 100

// struct for storing key /val pairs in cache
typedef struct {
    int key;
    int value;
} CacheEntry;

// array to store cache entries
static CacheEntry cache[CACHE_SIZE];
static int next_index = 0;

// initialize cache by setting all keys to -1
void cache_init() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;
    }
}

// nothing to free since we use static array
void cache_free() {}

// search for key in cache and return value if found
int cache_get(int key, int *value) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key == key) {
            *value = cache[i].value;
            return 1;
        }
    }
    return 0;
}

// add new entry to cache, replace oldest entry if full
void cache_put(int key, int value) {
    cache[next_index].key = key;
    cache[next_index].value = value;
    next_index = (next_index + 1) % CACHE_SIZE;
}
