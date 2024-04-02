#include "hash.h"

int
main(void) {
    ht* table = ht_init();
    char* name[31] = {
        "Jacob",     "Natalie",   "Sara",  "Mpho",     "Tebogo", "Ron",      "Jane",    "Louanne",
        "Vonda",     "Candie",    "Eowyn", "Costella", "Mana",   "Carolina", "Kamilla", "Esdras",
        "Abdulaziz", "Sylvio",    "Azim",  "Arie",     "Levy",   "August",   "Dixie",   "Kaydence",
        "Yusuf",     "Alexandro", "Ara",   "Dianne",   "Ranya",  "Wendie",   "Brennan",
    };
    for (int i = 0; i < 31; i++) {
        ht_set(table, name[i], ht_key(name[i]));
    }
    ht_print(table);

    return 0;
}
