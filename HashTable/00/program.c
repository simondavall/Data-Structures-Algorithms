#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash_table.h"
#define N 1000
#define CODE_LEN 4

char codes[N][CODE_LEN + 1];
void generate_random_codes();

int main(void){

  generate_random_codes();

  for (int i = 0; i < N; i++)
    add_item(codes[i]);
  
  char *test_str = codes[5];
  struct node *item = find_item(test_str);
  if (item == NULL){
    printf("Process failed. Item not found\n");
    exit(EXIT_FAILURE);
  }

  remove_item(test_str);

  item = find_item(test_str);
  if (item != NULL){
    printf("Process failed. Item not removed\n");
    exit(EXIT_FAILURE);
  }

  print_hash_table();
  printf("Process succeeded. Congratulations. :-)\n");

  destroy_hash_table();
  return EXIT_SUCCESS;
}

void generate_random_codes(){
  srand((unsigned) time(NULL));
  for (int i = 0; i < N; i++){
    codes[i][0] = rand() % 26 + 'a';
    codes[i][1] = rand() % 26 + 'a';
    codes[i][2] = '-';
    codes[i][3] = rand() % 10 + '0';
    codes[i][4] = '\0';
  }
}
