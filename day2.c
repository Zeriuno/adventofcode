#include <stdio.h>

main()
{
  FILE *f1                                  ;
  int h, l, w, surf, paper, slack, bow      ;
  int ribbon, perimeter                     ;
  char file[20]                             ;


  printf("What's the name of the instructions file? ")        ;
  scanf("%s", file)                                           ;
  f1 = fopen (file, "r")                    ;
  paper = 0                                 ;
  ribbon = 0                                ;

  while(!feof(f1))
  {
    fscanf(f1, "%dx%dx%d", &h, &l, &w)      ;
    surf = (2*h*l) + (2*h*w) + (2*l*w)      ;
    if ((h*l) < (h*w))
    {
      if ((h*l) < (l*w))
        slack = (h*l)                     ;
      else
        slack = (l*w)                     ;
    }
    else
    {
      if ((h*w) < (l*w))
        slack = (h*w)                     ;
      else
        slack = (l*w)                     ;
    }
    paper += surf + slack                   ;

    if(((2*h) + (2*l)) < ((2*h) + (2*w)))
    {
      if(((2*h) + (2*l)) < ((2*w) + (2*l)))
      {
        perimeter = ((2*h) + (2*l))         ;
      }
      else
      {
        perimeter = ((2*w) + (2*l))         ;
      }
    }
    else
    {
      if(((2*h) + (2*w)) < ((2*w) + (2*l)))
      {
        perimeter = ((2*h) + (2*w))         ;
      }
      else
      {
        perimeter = ((2*w) + (2*l))         ;
      }
    }
    bow = h * l * w                         ;

    ribbon += bow + perimeter               ;
   /*
    debug printf
    printf("(2 × %d × %d) + (2 × %d × %d) + (2 × %d × %d) = %d + %d\n", h, l, h, w, l, w, surf, slack) ;*/
  }
  fclose(f1)                                ;
  paper = paper - surf - slack              ;
  printf("Surface = %d\n", paper)           ;
  ribbon = ribbon - perimeter - bow         ;
  printf("Ribbon = %d\n", ribbon)           ;

}
