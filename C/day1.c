/**/
#include <stdio.h>

void input_file()    ;
void show_result()   ;
char file[20]        ;
int floors, basement ;



int main()
{
  int i   ;
  char b  ;
  FILE *a ;

  b = 'a'      ;
  floors = 0   ;
  i = 0        ;
  basement = 0 ;

  input_file()                              ;
  a = fopen(file, "r")                                 ;

  while(b != '\n')
  {
    fscanf(a, "%c", &b)                                ;
    i++                                                ;
    switch(b)
    {
      case '(':
        floors += 1                                    ;
        break                                          ;
      case ')':
        floors -= 1                                    ;
        break                                          ;
      case '\n':
        printf("Phew! That was long!\n")               ;
        break                                          ;
      default:
        printf("\n\n\nHuston, we have a problem.\n\n") ;
        printf("I read %c", b)                         ;
        break                                          ;
    }
    if((floors == -1) && (basement == 0))
      basement = i                                     ;
  }
  fclose(a)                                            ;

  show_result()                                        ;
  return 0 ;
}


/*---------------------------------------------------------
--                     input_file                        --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
---------------------------------------------------------*/


void input_file()
{
  printf("What's the name of the instructions file? ")       ;
  scanf("%s", file)                                           ;
}


/*---------------------------------------------------------
--                       show_result                     --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
---------------------------------------------------------*/


void show_result()
{
  printf("Santa Claus is on floor n. %d\n", floors)    ;
  printf("And he first entered the basement at position n.%d\n", basement) ;
}
