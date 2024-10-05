#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "quicksort.h"
#define N 10

int numbers[N];
bool test_success();

int main(void){
  int i;
  
  srand((unsigned) time(NULL));
  for (i = 0; i < N; i++)
    numbers[i] = rand() % 100;

  printf("Unsorted array\n");
  for (i = 0; i < N; i++)
    printf(" [%d]", numbers[i]);
  printf("\n");
 
  quicksort(numbers, 0, N - 1);

  printf("\nSorted array\n");
  for (i = 0; i < N; i++)
    printf(" [%d]", numbers[i]);
  printf("\n");

  if (test_success()){
    printf("Process succeeded. Congratulations. :-)\n");
  }
  else
    printf("Process failed. Check your code and try again.\n");

  return EXIT_SUCCESS;
}

bool test_success(){
  for(int i = 1; i < N; i++)
    if (numbers[i - 1] > numbers[i])
      return false;
  return true;
}
