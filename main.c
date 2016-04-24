#define _GNU_SOURCE

#include <stdint.h>
#include <string.h>
#include <sys/user.h>
#include <stdio.h>

#include "sys/mman.h"




int main() {

    void *code = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);


    int curr_offset = 0;

    int v = 0;

    memcpy(code, &&inc_start, &&inc_end - &&inc_start);

    goto *code;

    inc_start:
    v += 1;
    v += 1;
    void *p_end =&&end; goto *p_end;
    inc_end:;
    end:


    munmap(code, PAGE_SIZE);
    printf("%d", v);
    return 0;
}


