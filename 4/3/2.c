#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode {
    char *key;
    char *value;
    struct dnode *next;
};

struct pydict {
  struct dnode *head;
  struct dnode *tail;
  int count;
};

/* Constructor - dct = dict() */
struct pydict * pydict_new() {
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(dct) */
void pydict_del(struct pydict* self) {
    struct dnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

/* ------------------------------------------------------------------------------------------------------------ */
/* print(dct) */
/* {'z': 'W', 'y': 'B', 'c': 'C', 'a': 'D'} */
void pydict_print(struct pydict* self)
{
    struct dnode *node;
    node = self->head;
    printf("{");
    while (node != NULL) {
        printf("'%s': '%s'", node->key, node->value);
        node = node->next;
        if (node != NULL) {
            printf(", ");
        }
    }

    printf("}\n");
}

int pydict_len(const struct pydict* self)
{
    return self->count;
}

/* find a node - used in get and put */
struct dnode* pydict_find(struct pydict* self, char *key)
{
    struct dnode *node;

    node = self->head;

    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

/* x.get(key) - Returns NULL if not found */
char* pydict_get(struct pydict* self, char *key)
{
    struct dnode *entry = pydict_find(self, key);
    if (entry != NULL) {
        return entry->value;
    } else {
        return NULL;
    }
}

/* x[key] = value; Insert or replace the value associated with a key */
void pydict_put(struct pydict* self, char *key, char *value) {
    struct dnode *old = pydict_find(self, key);
    struct dnode *new = (struct dnode *) malloc(sizeof(struct dnode));

    if (old != NULL) {
        free(old->value);
        old->value = malloc(100);
        strcpy(old->value, value);
    } else {
        if (self->tail != NULL) {
            self->tail->next = new;
        }

        new->key = malloc(100);
        strcpy(new->key, key);

        new->value = malloc(100);
        strcpy(new->value, value);

        new->next = NULL;
        self->tail = new;

        if (self->head == NULL) {
            self->head = new;
        }

        self->count += 1;
    }
}

/* ------------------------------------------------------------------------------------------------------------ */

int main(void)
{
    struct dnode * cur;
    struct pydict * dct = pydict_new();

    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);
    pydict_put(dct, "z", "W");
    pydict_print(dct);
    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");
    pydict_print(dct);
    printf("Length =%d\n",pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");
    for(cur = dct->head; cur != NULL ; cur = cur->next ) {
        printf("%s=%s\n", cur->key, cur->value);
    }

    pydict_del(dct);
}
