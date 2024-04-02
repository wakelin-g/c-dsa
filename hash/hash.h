#ifndef __HASH_H_
#define __HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_MAX_CAPACITY 29

typedef struct ht_entry {
    const char* key;
    int value;
    struct ht_entry* next;
} ht_entry;

typedef struct ht {
    ht_entry* entries[HT_MAX_CAPACITY + 1];
} ht;

ht* ht_init(void);

uint64_t ht_key(const char* key);

void ht_set(ht* ht, const char* key, int value);

ht_entry* ht_get(ht* ht, const char* key);

void ht_print(ht* ht);

ht_entry* ht_follow_list(ht_entry* ht);

#endif // __HASH_H_
