#ifndef _H_PHANSO
#define _H_PHANSO

#include <stdio.h>

struct fraction{
    int numerator;// tu so
    int denominator;// mau so
};
typedef struct fraction fractions;

struct node{
    fractions data;
    struct node *pNext;
};
typedef struct node nodes;

struct list{
    nodes *pHead;
    nodes *pLast;
};
typedef struct list lists;

// khai bao function
void init_list(lists *l);
nodes *init_node(fractions ps);
void add_head(lists *l, nodes *n);
void add_last(lists *l, nodes *n);
void add_fraction(fractions *ps);
void add_any(lists *l, nodes *n, int position, int count);
void output(fractions ps);
void print(lists *l);
void free_list(lists *l);
void free_head(lists *l);
void free_last(lists *l);
void free_any(lists *l, int position, int count);
void menu(lists *l);

#endif