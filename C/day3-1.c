#include <stdio.h>

void check()            ;
void input_file()       ;
void move()             ;

char file[20]           ;
int la = 0, lo = 0      ;
int coordinates[2][9000] ;
int houses = 0          ; 	// Starts at 1 because the starting point is already a house served.
FILE *f1                ;

main()
{	
	
	char c       ;

	input_file() ;
	
	f1 = fopen(file, "r") ;
	while(!feof(f1))
	{
		check() ; /*Starting at 0,0*/
		move()  ;
	}
	fclose(f1) ;
	printf("Santa visited this many houses : %d\n", houses) ;
	return 0 ;
}

void check()
	{
		int i = 0              ;
		while(i < houses)
		{
		//	printf("houses: %d\n", houses);
		//	printf("i     : %d\n", i)     ;
			if(!((coordinates[0][i] == la ) && (coordinates[1][i] == lo ))) //if coordinates are not in the cell
			{
		//		printf("la = %d\ncoordinates[0][%i]=%d\n", la, i, coordinates[0][i]) ;
		//		printf("lo = %d\ncoordinates[1][%i]=%d\n", lo, i, coordinates[1][i]) ;
				i++                     ; 								  //Keep on checking the table
			}
			else
				i = houses + 1          ; 								  //else quit the loop
		}
		//printf("After check\n");
		//printf("houses: %d\n", houses);
		//printf("i     : %d\n", i)     ;
		if(i == houses) //if we quit the loop because of the 'else', we add to the table the current coordinates
		{
			coordinates[0][houses] = la           ;
			coordinates[1][houses] = lo           ;
			houses++                              ;
//			printf("Served %d houses!\n", houses) ;
		}
	}

void move() //what happens when you move
{
	char c ;
	fscanf(f1, "%c"	, &c) ;
	// printf("I read '%c'\n", c) ;
	switch(c)
	{
		case '^':
			la++  ;
		//	printf("la = %d\nlo = %d\n", la, lo) ;
			break ;
		case 'v':
			la--  ;
		//	printf("la = %d\nlo = %d\n", la, lo) ;
			break ;
		case '<':
			lo--  ;
		//	printf("la = %d\nlo = %d\n", la, lo) ;
			break ;
		case '>':
			lo++  ;
		//	printf("la = %d\nlo = %d\n", la, lo) ;
			break ;
		default:
		//	printf("Mhh, bumpy road: %c\n", c) ;
			break ;
	}
}

void input_file()
{
  printf("What's the name of the instructions file? ")       ;
  scanf("%s", file)                                           ;
}

/*

Un piano cartesiano.
La casella di partenza ed ogni nuova casella ulteriore vengono contate

1. Partire con

Latitudine = 0
Longitudine = 0

2. Aggiungere questo alle coordinate

coordinates[1][0] = la
coordinates[2][0] = lo

3. Ad ogni nuovo carattere aggiornare le coordinate

selonque caractètre est
  ^ : la++
  v : la--
  < : lo--
  > : lo++
finselonque

4. Cercare le coordinate presenti tra quelle già salvate: se non si trova, salvare le coordinate nella lista.
Se si trova, passare al 3.

5. Se il carattere è feof, stampare la lunghezza della lista delle coordinate, e poi chiudere.
*/