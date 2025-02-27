#ifndef CACHE_H
#define CACHE_H

void cache_init();
void cache_free();
int cache_get(int key, int *value);
void cache_put(int key, int value);

#endif