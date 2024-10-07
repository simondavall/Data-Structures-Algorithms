#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash_table.h"

struct node *hash_table[HASH_TABLE_SIZE] = {NULL};

static int hash(char *content){
  int i, value = 0;
  for(i = 0; i < (int)strlen(content); i++){
    value = ((value + content[i]) * 17) % HASH_TABLE_SIZE;
  }
  return value;
}

void add_item(char *content){
  struct node *new_node, *cur, *prev;
 
  new_node = find_item(content);
  if (new_node != NULL)
    return;
  
  new_node = malloc(sizeof(struct node));
  if(new_node == NULL){
    printf("Unable to allocate memory for new node in hash table\n");
    exit(EXIT_FAILURE);
  }
  new_node->content = malloc(strlen(content) + 1);
  if (new_node->content == NULL){
    printf("Unable to allocate memory for content in hash table\n");
    free(new_node);
    exit(EXIT_FAILURE);
  }
  strcpy(new_node->content, content);

  int id = hash(content);
  new_node->next = hash_table[id];
  hash_table[id] = new_node;
}

struct node *find_item(char *content){
  struct node *cur;
  
  int id = hash(content);
  for (cur = hash_table[id]; cur != NULL && strcmp(cur->content, content); cur = cur->next);

  return cur;
}

void remove_item(char *content){
  struct node *cur, *prev;

  int id = hash(content);
  for (cur = hash_table[id], prev = NULL; cur != NULL && strcmp(cur->content, content); prev = cur, cur = cur->next);

  if(cur == NULL)
    return;

  if (prev == NULL)
    hash_table[id] = cur->next;
  else{
    prev->next = cur->next;
  }
  free(cur);
}

void destroy_hash_table(void){
  struct node *ptr;

  for(int i = 0; i < HASH_TABLE_SIZE; i++){
    while(hash_table[i] != NULL){
      ptr = hash_table[i];
      hash_table[i] = hash_table[i]->next;
      free(ptr->content);
      free(ptr);
    }
  }
}

void print_hash_table(void){
  struct node *p;

  for (int i = 0; i < HASH_TABLE_SIZE; i++){
    if (hash_table[i] != NULL){
      printf("Bucket %d:", i);
      p = hash_table[i];
      while(p != NULL){
        printf(" [%s]", p->content);
        p = p->next;
      }
      printf("\n");
    }
  }
}

