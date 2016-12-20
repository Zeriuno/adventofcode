#include <stdio.h>
#include <string.h>

/*
signX, axisX signY axisY
0,0 + L2 = -2,0
L2 = -2,-2

L8 può avere due significati a seconda del contesto?


0,0 = L è partire in -X
-3,0 = L è partire in -Y
-3, -3 = L è partire in +X
3, 3 = L è partire in
*/

int turn(int buana) ;

int main(int argc, char* argv[])
{
  int signX = 1, signY = 1 ;
  int axisX = 0, axisY = 0 ;
  int move ;
  int nowMoving = 0 ; // 0 to change the X axis value, 1 to change the Y
  int read ;
  char coordinates[500] ;
  char coordfile ;
  int coordinateslen ;
  int i = 0 ;

  FILE *f1;

  if(argc == 2)
  {
    f1 = fopen(argv[1], "r") ;
    while(!EOF)
    {
      fscanf(f1, &coordfile);
    }
    fclose(f1);
    printf("Read it\n");
  }
  else
  {
    printf("axisX = %d - axisY = %d\n", axisX, axisY);
    printf("Submit the coordinates: ");
    scanf("%s", coordinates);
    coordinateslen = strlen(coordinates) ;
    printf("coordinateslen = %d\n", coordinateslen );
    printf("axisX = %d - axisY = %d\n", axisX, axisY); //WTF
    axisY = 0 ;
    axisX = 0 ;
    while(i < coordinateslen)
    {
      read = coordinates[i] ;
      printf("i = %d\nread = %c\n", i, read);
      if (read != 32) //blank space
      {
        if( read == 76 || read == 82 ) // 76 == L, 82 == R
        {
          switch(read)
          {
            case 76:
            if (nowMoving == 0)
            {
              if (signY == 1)
              {
                signX = -1 ;
              }
              else
              {
                signX = 1 ;
              }
            }
            else //nowMoving == 1
            {
              if (signX == 1)
              {
                signY = 1 ;
              }
              else
              {
                signY = -1 ;
              }
            }
            break;
            case 82:
            if (nowMoving == 0)
            {
              if (signY == 1)
              {
                signX = 1 ;
              }
              else
              {
                signX = -1 ;
              }
            }
            else //nowMoving == 1
            {
              if (signX == 1)
              {
                signY = -1 ;
              }
              else
              {
                signY = 1 ;
              }
            }
            break ;
          };
        }
        else
        {
          if ((read > 47) && (read < 58))
          {
            move = read - 48 ;
            printf("move = %d\n", move);
            while (read !=  44)
            {
              i++;
              printf("i=%d\n",i);
              if (i < coordinateslen)
               {
                  read = coordinates[i] ;
                  printf("read = %c\n", read);
                if ((read > 47) && (read < 58))
                {
                  move = (move * 10) + read - 48 ;
                  printf("move = %d\n", move);
                }
              }
            }
            switch(nowMoving)
            {
              case 0:
              printf("signX = %d\n", signX);
              axisX += move * signX ;
              break;
              case 1:
              printf("signY = %d\n", signY);
              axisY += move * signY ;
              break;
            }
            nowMoving = turn(nowMoving) ;
          }
        }
        printf("Coordinates: X %d - Y %d - i %d\n", axisX, axisY, i);
        }
        i++ ;
        printf("i= %d\n", i);
      } 
    }
  if(axisX < 0)
    axisX *= -1 ;
  if(axisY < 0)
  axisY *= -1 ;
  printf("Distance : %d blocks\n", axisX + axisY);
  return 0 ;
}

int turn(int buana)
{
  if (buana == 0)
    buana = 1;
  else
    buana = 0;
  return buana;
}
