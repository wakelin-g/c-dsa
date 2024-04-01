#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

int
main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage:\n\t%s query\n", argv[0]);
        exit(1);
    }
    int a[] = {1,  2,  15, 16, 21, 22,  23,  24,  25,  30,  34,  35,  36,  79, 80,
               81, 90, 91, 92, 93, 144, 155, 156, 178, 200, 204, 205, 320, 321};
    int n = sizeof(a) / sizeof(int);
    int q = atoi(argv[1]);
    int result = search(a, q, 0, n - 1);
    printf("index position of %d: %d\n", q, result);
    for (int i = 0; i < n; i++) {
        printf("idx: %3d | %-3d ", i, a[i]);
        if (i == result) {
            printf("<-\n");
        } else {
            printf("\n");
        }
    }

    return 0;
}
