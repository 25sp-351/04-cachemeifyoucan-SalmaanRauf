#include <stdlib.h>
#include <stdio.h>
#include "cache.h"
#define CACHE_SIZE 100

// each cache entry has a key, value and age to track when last used
typedef struct {
    int key;
    int value;
    int age;
} CacheEntry;

// cache is just a static array
static CacheEntry cache[CACHE_SIZE];
static int current_age = 0;

// initialize all cache entries with invalid keys
void cache_init() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;  // -1 means empty slot
    }
}

// nothing to free since we're using a static array
void cache_free() {}

// try to find a value in the cache
int cache_get(int key, int *value) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key == key) {
            cache[i].age = current_age++;  // update the age since we just used it
            *value = cache[i].value;  // put the value in the output parameter
            return 1;  // found
        }
    }
    return 0;  // not found
}

// add new entry to the cache, replacin oldest if needed
void cache_put(int key, int value) {
    int oldest = 0;  // start with first entry
    for (int i = 1; i < CACHE_SIZE; i++) {
        if (cache[i].age < cache[oldest].age) {
            oldest = i;  // found older entry
        }
    }
    cache[oldest].key = key;  // replace oldest entry
    cache[oldest].value = value;
    cache[oldest].age = current_age++;  // new newest entry
}