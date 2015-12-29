#include <stdio.h>
main()
{
  FILE *f1                    ;
  int h, l, w, surf, paper    ;

  f1 = fopen ("day2.txt", "r")  ;
  paper = 0                   ;

  while(!feof(f1))
  {
    fscanf(f1, "%dx%dx%d", &h, &l, &w)   ;
    paper += (2*h*l) + (2*h*w) + (2*l*w) ;
  }
  fclose(f1) ;
  printf("Surface = %d\n", paper)        ;
}
