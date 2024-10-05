#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#define HASH_TABLE_SIZE 256

struct node{
  char *content;
  struct node *next;
};

void add_item(char *content);
struct node *find_item(char *content); // returns NULL if not found
void remove_item(char *content);
void print_hash_table(void);
void destroy_hash_table(void);


#endif // !HASH_TABLE_H

