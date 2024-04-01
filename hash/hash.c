#include "hash.h"

ht*
ht_init(void) {
    ht* table = (ht*)malloc(sizeof(ht));
    for (int i = 0; i < HT_MAX_CAPACITY + 1; i++) {
        table->entries[i] = NULL;
    }
    return table;
}

uint64_t
ht_key(const char* key) {
    size_t len = strnlen(key, 128);
    uint64_t hash_val = 0;
    for (size_t i = 0; i < len; i++) {
        hash_val += key[i];
        hash_val = (hash_val * key[i]) % HT_MAX_CAPACITY;
    }
    return hash_val;
}

void
ht_set(ht* ht, const char* key, int value) {
    uint64_t hash = ht_key(key) % HT_MAX_CAPACITY;

    ht_entry* ptr;
    ht_entry* hte = (ht_entry*)malloc(sizeof(ht_entry));
    hte->key = key;
    hte->value = value;
    hte->next = NULL;

    if (ht->entries[hash] == NULL) {
        ht->entries[hash] = hte;
        return;
    } else {
        ptr = ht_follow_list(ht->entries[hash]);
        ptr->next = hte;
    }
}

void
ht_print(ht* ht) {
    ht_entry* ptr;
    printf("\n");
    printf("bucket\tkey\tvalue\n");
    printf("|--------------------|\n");
    for (int i = 0; i < HT_MAX_CAPACITY; i++) {
        printf("|[%i]\t\t     |\n", i);
        ptr = ht->entries[i];
        if (ptr == NULL) {
            printf("|\tNA\tNA   |\n");
        } else {
            while (ptr != NULL) {
                printf("|\t%s\t%-3d  |\n", ptr->key, ptr->value);
                ptr = ptr->next;
            }
        }
        printf("|--------------------|\n");
    }
    printf("\n");
}

ht_entry*
ht_follow_list(ht_entry* hte) {
    ht_entry* ptr = hte;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}
