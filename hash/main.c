#include "hash.h"

int
main(void) {
    ht* table = ht_init();
    char* name[7] = {"Jacob", "Natalie", "Sara", "Mpho", "Tebogo", "Ron", "Jane"};
    for (int i = 0; i < 7; i++) {
        ht_set(table, name[i], ht_key(name[i]));
    }
    ht_print(table);

    return 0;
}
