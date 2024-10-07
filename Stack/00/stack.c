#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
};

Stack create(void)
{
  return NULL;
}

void destroy(Stack s)
{
}

void make_empty(Stack s)
{
}

bool is_empty(Stack s)
{
  return false;
}

void push(Stack s, Item item)
{
}

Item pop(Stack s)
{
  return NULL;
}

