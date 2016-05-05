typedef struct {
    void *elem;
    int elem_size;
    int log_length;
    int alloc_length;
} stack;

static void stack_grow(stack *s);
void stack_new(stack *s,int elem_size,int alloc_length);
void stack_dispose(stack *s);
void stack_push(stack *s,void *elem_addr);
void stack_pop(stack *s,void *elem_addr);
