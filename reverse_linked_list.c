#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node* next;
} LNode,*LNode_ptr;

void print_list(LNode_ptr head)
{
    LNode_ptr pn = head;
    while(NULL != pn) {
        printf("%d ",pn->data);
        pn = pn->next;
    }
    printf("\n");

    return;
}

LNode_ptr reverse_list(LNode_ptr head)
{
    if(NULL == head) {
        printf("empty list\n");
        return;
    }

    if(NULL == head->next) {
        printf("only one item\n");
        return;
    }

    LNode_ptr previous = head;
    LNode_ptr current = head->next;
    LNode_ptr tmp = NULL;
    while(NULL != current) {
        tmp = current->next;
        current->next = previous;
        previous = current;
        current = tmp;
    }
    
    head->next = tmp;
    head = previous;

    return head;
}

LNode_ptr create_list(int len)
{
    int i;
    LNode_ptr pn = NULL;
    LNode_ptr tmp = NULL;
    for(i = 0;i<len;i++) {
        tmp = (LNode_ptr)malloc(sizeof(LNode));
        tmp->data = i;
        tmp->next = pn;
        pn = tmp;
    }
    return pn;
}

int main(int argc,char **argv)
{
    int list_size = atoi(argv[1]);
    printf("The list size is %d\n",list_size);

    LNode_ptr head = create_list(list_size);
    print_list(head);

    head = reverse_list(head);
    print_list(head);
    return 0;
}
