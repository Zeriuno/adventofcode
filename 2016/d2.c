#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE *f1;
  int x , y = 1, test;
  int line;
  char direction;
  char code[10];
  for (line = 0 ; line < 10; line++)
  	code[line] = '\0';
  line = 0;
  if (argc == 2)
  {
	  f1 = fopen(argv[1], "r");
	  while(!EOF)
	  {
	    fscanf(f1, "%c", &direction);
	    printf("direction = %c\n", direction);
	    switch(direction)
	    {
	      case 'L':
	        test = x - 1;
	        if(test > 0)
	        	x = test;
	      break;
	      case 'R':
			test = x + 1;
	        if(test < 3)
	        	x = test;
	      break;
	      case 'U':
	   		test = y - 1;
	        if(test > 0)
	        	y = test;
	      break;
	      case 'D':
	   		test = y + 1;
	        if(test < 3)
	        	y = test;     
	      break;
	      case '\n':
	        printf("x = %d\ny = %d\n", x, y);
	        switch(x)
	        {
	        	case 0:
	        	    switch(y)
	        		{
	        		case 0:
	        		  code[line] = 7 + 48 ;
		        	break;
		        	case 1:
		        		code[line] = 4 + 48 ;
		        	break;
		        	case 2:
		        		code[line] = 1 + 48 ;
		        	break;
		        	}
	        	break;
	        	case 1:
	        	    switch(y)
		        	{
		        	case 0:
		        		code[line] = 8 + 48 ;
		        	break;
		        	case 1:
		        		code[line] = 5 + 48 ;
		        	break;
		        	case 2:
		        		code[line] = 2 + 48 ;
		        	break;
		        	}
	        	break;
	        	case 2:
	        	    switch(y)
		        	{
		        	case 0:
		        		code[line] = 9 + 48 ;
		        	break;
		        	case 1:
		        		code[line] = 6 + 48 ;
		        	break;
		        	case 2:
		        		code[line] = 3 + 48 ;
		        	break;
		        	}
	        	break;
	        }
	        line++;
	        printf("line = %d\n", line);
	      break;
	    }
	  }
  }
  fclose(f1);
  printf("%s\n", code);
  return 0;
}