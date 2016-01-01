#include <stdio.h>

char input_file()    ;
char file[20]        ;


{
  printf("What's the name of the instructions file?: ")       ;
  scanf("%s", file)                                           ;

main()
{
  FILE *f1                                  ;
  int h, l, w, surf, paper, slack           ;
  char input[20]                            ;

  file[20] = input_file()                   ;
  f1 = fopen (input, "r")                   ;
  paper = 0                                 ;

  while(!feof(f1))
  {
    fscanf(f1, "%dx%dx%d", &h, &l, &w)      ;
    surf = (2*h*l) + (2*h*w) + (2*l*w)      ;
    if ((2*h*l) < (2*h*w))
    {
      if ((2*h*l) < (2*l*w))
        slack = (2*h*l)                     ;
      else
        slack = (2*l*w)                     ;
    }
    else
    {
      if ((2*h*w) < (2*l*w))
        slack = (2*h*w)                     ;
      else
        slack = (2*l*w)                     ;
    }
    paper += surf + slack                   ;

   /*printf de deboggage*/
    printf("(2 × %d × %d) + (2 × %d × %d) + (2 × %d × %d) = %d + %d\n", h, l, h, w, l, w, surf, slack) ;
  }
  fclose(f1)                                ;
/*  paper = paper - surf - slack              ;*/
  printf("Surface = %d\n", paper)           ;
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


char input_file()
{
  printf("What's the name of the instructions file?: ")       ;
  scanf("%s", file)                                           ;
  return file[20]                                             ;
}

