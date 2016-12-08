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

int main(int argc, char* argv[])
{
  int signX = 1, signY = 1 ;
  int axisX = 0, axisY = 0 ;
  int nowMoving = 0 ; // 0 to change the X axis value, 1 to change the Y
  int read ;
  char coordinates[500] ;
  int coordinateslen ;
  int i = 0 ;

  if(argC == 2)
  {
  }
  else
  {
    printf("Submit the coordinates: ");
    scanf("%s", &coordinates);
    coordinateslen = strlen(coordinates) ;
    while(i < coordinateslen)
    {
      read = coordinates[i]
      if( read == 76 || read == 82 ) // 76 == L, 82 == R
      switch(i)
      {
      case '76':
        if ((signX == 1) && (signY == 1) )
        {
          signX *= -1 ;
        }
        if ((signX == -1) && (signY == 1))
        {
          signY *= -1 ;
        }
        if ((signX == -1) && (signY == -1))
        {

        }
        break ;
      case '82':
        break ;
      }
      nowMoving = turn(nowMoving) ;
    }
  }
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
