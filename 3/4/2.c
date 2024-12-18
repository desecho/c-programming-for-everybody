#include <stdio.h>
#include <stdlib.h>

struct lnode {
    int value;
    struct lnode *next;
};

struct list {
  struct lnode *head;
  struct lnode *tail;
};

void list_add(lst, value)
    struct list *lst;
    int value;
{
    struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
    if (lst->tail != NULL) {
        lst->tail->next = new;
    }

    new->value = value;
    new->next = NULL;
    lst->tail = new;

    if (lst->head == NULL) {
        lst->head = new;
    }
}

void list_remove(lst, value)
    struct list *lst;
    int value;
{
    struct lnode *cur;

    // If element is the first in the list
    if (lst->head->value == value) {
        lst->head = lst->head->next;
    }

    // If element is not the first in the list
    for(cur=lst->head; cur != NULL; cur=cur->next) {
        if (cur->next != NULL && cur->next->value == value) {
            cur->next = cur->next->next;
        }
    }

    // Set proper tail
    for(cur=lst->head; cur != NULL; cur=cur->next) {
        lst->tail = cur;
    }
}

int main()
{
    void list_add();
    void list_dump();
    struct lnode * list_find();

    struct list mylist;
    struct lnode * mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 42);

    list_remove(&mylist, 10);
    list_dump(&mylist);

    list_remove(&mylist, 30);
    list_dump(&mylist);

    list_add(&mylist, 40);
    list_dump(&mylist);

}

void list_dump(lst)
    struct list *lst;
{
    struct lnode *cur;
    printf("\nDump:\n");
    for(cur=lst->head; cur != NULL; cur=cur->next) {
        printf("  %d\n", cur->value);
    }
}
