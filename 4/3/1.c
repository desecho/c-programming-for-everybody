#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *text;
    struct lnode *next;
};

struct pylist {
  struct lnode *head;
  struct lnode *tail;
  int count;
};

/* Constructor - lst = list() */
struct pylist * pylist_new() {
    struct pylist *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(lst) */
void pylist_del(struct pylist* self) {
    struct lnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

/* --------------------------------------------------------------------------------------------------------------------- */

void pylist_print(struct pylist* self)
{
    struct lnode *node;
    node = self->head;
    printf("[");
    while (node != NULL) {
        printf("'%s'", node->text);
        node = node->next;
        if (node != NULL) {
            printf(", ");
        }
    }

    printf("]\n");
}

int pylist_len(const struct pylist* self)
{
    return self->count;
}

void pylist_append(struct pylist* self, char *str) {
    struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
    int i;
    if (self->tail != NULL) {
        self->tail->next = new;
    }

    new->text = malloc(100);
    strcpy(new->text, str);

    new->next = NULL;
    self->tail = new;

    if (self->head == NULL) {
        self->head = new;
    }

    self->count += 1;
}

/* lst.index("Hello world") - if not found -1 */
int pylist_index(struct pylist* self, char *str)
{
    int i = 0;
    struct lnode *node;

    node = self->head;

    while (node != NULL) {
        if (strcmp(node->text, str) == 0) {
            return i;
        }
        node = node->next;
        i++;
    }

    return -1;
}

/* --------------------------------------------------------------------------------------------------------------------- */

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    struct pylist * lst = pylist_new();
    pylist_append(lst, "Hello world");
    pylist_print(lst);
    pylist_append(lst, "Catch phrase");
    pylist_print(lst);
    pylist_append(lst, "Brian");
    pylist_print(lst);
    printf("Length = %d\n", pylist_len(lst));
    printf("Brian? %d\n", pylist_index(lst, "Brian"));
    printf("Bob? %d\n", pylist_index(lst, "Bob"));
    pylist_del(lst);
}
