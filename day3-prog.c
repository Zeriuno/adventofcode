#include <stdio.h>

void input_file() ;
char file[20]     ;


main()
{
  int map[1000][1000]       ;
  char c                    ;
  FILE *f1                  ;


  printf("We got a map!\n") ;

  input_file()              ;
  f1 = fopen(file, "r")     ;

  while((c=fgetc(f1)) != EOF)
  {
    printf("Bonne année!\n") ;
  }

  printf("Enfin!\n") ;  

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
  printf("What's the name of the instructions file? ") ;
  scanf("%s", file)                                    ;
}

