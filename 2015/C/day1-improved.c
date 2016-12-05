#include <stdio.h>
#include <string.h>

void check(char)                    ;

int floors = 0, position = 0, i = 0 ;

int main(int argc, char* argv[])
{
  int found = 0, inputlength ;
  char b = 'a'               ;
  char input[50]             ;
  FILE  *f1                  ;

  if(argc == 2)
  {
    f1 = fopen(argv[1], "r") ;
    while(b != '\n')
    {
      fscanf(f1, "%c", &b)   ;
      check(b)               ;
    }
    fclose(f1)               ;
  }
  else
  {
    printf("Type the input: ")  ;
    scanf("%s", input)          ;
    inputlength = strlen(input) ;
    while(i < inputlength)
    {
      check(input[i])           ;
    }
  }
  printf("Santa finished at floor #%d\n", floors)               ;
  printf("He entered the basement in position #%d\n", position) ;
  return 0 ;
}

void check(char argi)
{
  switch(argi)
  {
    case '(':
      floors += 1                      ;
      break                            ;
    case ')':
      floors -= 1                      ;
      break                            ;
    case '\n':
      printf("Phew! That was long!\n") ;
      break                            ;
    default:
    /*debug
      printf("\n\n\nHuston, we have a problem.\n\n") ;
      printf("I read %c", b)                         ;
      */
      break                            ;
  }
  if (position == 0)
  {
    if(floors == -1)
      position = i+1                   ;
  }
  i++                                  ;
}
