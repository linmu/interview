#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

static void stack_grow(stack *s) {
    s->alloc_length *= 2;
    s->elem = realloc(s->elem,s->alloc_length * s->elem_size);
}

void stack_new(stack *s,int elem_size,int alloc_length) {
    assert(elem_size > 0);
    s->elem_size = elem_size;
    s->log_length = 0;
    s->alloc_length = alloc_length;
    s->elem = malloc(s->alloc_length * s->elem_size);
    assert(NULL != s->elem);
}

void stack_dipose(stack *s) {
    free(s->elem);
}

void stack_push(stack *s,void *elem_addr) {
    if(s->log_length == s->alloc_length) {
        stack_grow(s);
    }
    void *target = (char*)s->elem + s->log_length * s->elem_size;
    memcpy(target,elem_addr,s->elem_size);
    s->log_length++;
}

void stack_pop(stack *s,void *elem_addr) {
    void *source = (char*)s->elem + (s->log_length - 1) * s->elem_size;
    memcpy(elem_addr,source,s->elem_size);
    s->log_length--;
}
