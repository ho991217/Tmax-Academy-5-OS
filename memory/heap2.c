#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *mymalloc(int size) {
    void *p = sbrk(0);
    void *request = sbrk(size);
    if (request == (void*) -1) {
        return NULL;
    } else {
        return p;
    }
}