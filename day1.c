/**/
#include <stdio.h>

char saisie_fichier() ;
void affichage()      ;
FILE *a               ;
char file[20]         ;
int floors, basement  ;



main()
{
  int i                                                ;
  char b                                               ;

  b = 'a'                                              ;
  floors = 0                                           ;
  i = 0                                                ;
  basement = 0                                         ;

  file[20] = saisie_fichier()                          ;
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
        break                                          ;
    }
    if((floors == -1) && (basement == 0))
      basement = i                                     ;
  }
  fclose(a)                                            ;

  affichage()                                          ;
}


/*---------------------------------------------------------
--                Saisie du fichier                      --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
---------------------------------------------------------*/


char saisie_fichier()
{
  printf("What's the name of the file to count the floors? ") ;
  scanf("%s", file)                                           ;
  return file[20]                                             ;
}


/*---------------------------------------------------------
--                Affichage du résultat                  --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
--                                                       --
---------------------------------------------------------*/


void affichage()
{
  printf("Santa Claus is on floor n. %d\n", floors)    ;
  printf("And he first entered the basement at position n.%d\n", basement) ;
}
