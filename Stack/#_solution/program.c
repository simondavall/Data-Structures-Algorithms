
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void)
{
  Stack s1, s2;
  char *str;

  s1 = create();
  s2 = create();

  push(s1, "abc");
  push(s1, "def");

  str = pop(s1);
  if (strcmp(str, "def"))
  {
    printf("An unexpected value '%s' was popped from the stack. Expected 'def'\n", str);
    printf("Process Failed\n");
    exit(EXIT_FAILURE);
  }
  printf("Popped %s from s1\n", str);
  push(s2, str);
  str = pop(s1);
  if (strcmp(str, "abc"))
  {
    printf("An unexpected value '%s' was popped from the stack. Expected 'abc'\n", str);
    printf("Process Failed\n");
    exit(EXIT_FAILURE);
  }
  printf("Popped %s from s1\n", str);
  push(s2, str);

  destroy(s1);

  while (!is_empty(s2))
    printf("Popped %s from s2\n", pop(s2));

  str = pop(s2);
  if (str != NULL )
  {
    printf("Expected stack s2 to be empty.\n");
    printf("Process Failed\n");
    exit(EXIT_FAILURE);
  }
  
  push(s2, "xyz");
  str = pop(s2);
  if (strcmp(str, "xyz"))
  {
    printf("An unexpected value '%s' was popped from the stack. Expected 'xyz'\n", str);
    printf("Process Failed\n");
    exit(EXIT_FAILURE);
  }

  make_empty(s2);
  if (!is_empty(s2))
  {
    printf("Expected stack s2 to be empty.\n");
    printf("Process Failed\n");
    exit(EXIT_FAILURE);
  }

  destroy(s2);

  printf("Process succeeded. Congratulations. :-)\n");
  return 0;
}
