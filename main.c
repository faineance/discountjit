#define _GNU_SOURCE

#include <stdint.h>
#include <string.h>
#include <sys/user.h>
#include <stdio.h>

#include "sys/mman.h"

int main() {

    void *code = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE , MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    void *p_end = &&end;

    int v = 0;

    size_t offset = 0;
    memcpy(code, &&inc_start, &&inc_end - &&inc_start);
    offset += &&inc_end - &&inc_start;
    memcpy(code + offset, &&end_start, &&end_end - &&end_start);
    offset += &&end_end - &&end_start;


    mprotect(code, PAGE_SIZE, PROT_READ | PROT_EXEC); // hah safety
    goto *code;

    inc_start:
        v += 1;
        v += 1;
    inc_end:;


    end_start:
    goto *p_end;
    end_end:;

    end:

    munmap(code, PAGE_SIZE);
    printf("%d\n", v);
    return 0;
}


