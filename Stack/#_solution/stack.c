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
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL){
    printf("Error in create: stack could not be created.");
    exit(EXIT_FAILURE);
  }
  s->top = NULL;
  return s;
}

void destroy(Stack s)
{
  make_empty(s);
  free(s);
}

void make_empty(Stack s)
{
  while (!is_empty(s))
    pop(s);
}

bool is_empty(Stack s)
{
  return s->top == NULL;
}

void push(Stack s, Item item)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL){
    printf("Error in push: stack is full.");
    exit(EXIT_FAILURE);
  }

  new_node->data = item;
  new_node->next = s->top;
  s->top = new_node;
}

Item pop(Stack s)
{
  struct node *old_top;
  Item item;

  if (is_empty(s))
    return NULL;

  old_top = s->top;
  item = old_top->data;
  s->top = old_top->next;
  free(old_top);
  return item;
}

