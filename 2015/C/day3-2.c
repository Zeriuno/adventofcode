#include <stdio.h>

void check()              ;
void input_file()         ;
void move()               ;

char file[20]             ;
char c                    ;
int la = 0, lo = 0        ;
int robola = 0			  ;
int robolo = 0            ;
int coordinates[2][9000]  ;
int houses = 0            ;
int turn = 0              ;
FILE *f1                  ;

main()
{	
	input_file() ;
	
	f1 = fopen(file, "r") ;
	while(!feof(f1))
	{
		check() ;
		if(turn == 1)
			turn = 2 ;
		else
			turn = 1 ;
		if(turn == 0)
			turn = 1 ;
		move()  ;
	}
	fclose(f1) ;
	printf("Santa and RoboSanta visited this many houses : %d\n", houses) ;
	return 0 ;
}

void check()
	{
		int i = 0          ;
	//	printf("turn = %d\n", turn) ;
		if(turn == 1)
		{
			while(i < houses)
			{
				if(!((coordinates[0][i] == la ) && (coordinates[1][i] == lo ))) //if coordinates are not in the cell
					i++ ;
				else
					i = houses +1 ;
			}
			if(i == houses)
			{
				coordinates[0][houses] = la ;
				coordinates[1][houses] = lo ;
				houses++                    ;
			}
	/*		printf("la = %d\n", la);
			printf("lo = %d\n", lo);
			printf("houses = %d\n", houses);
	*/	}
		else
		{
			while(i < houses)
			{
				if(!((coordinates[0][i] == robola ) && (coordinates[1][i] == robolo ))) //if coordinates are not in the cell
					i++ ;
				else
					i = houses +1 ;
			}
			if(i == houses)
			{
				coordinates[0][houses] = robola ;
				coordinates[1][houses] = robolo ;
				houses++                    ;
	/*		printf("la = %d\n", robola);
			printf("lo = %d\n", robolo);
			printf("houses = %d\n", houses);
	*/		}
		}
	}

void move() //what happens when you move
{
	fscanf(f1, "%c"	, &c) ;
	printf("I read '%c'\n", c) ;
	if((turn == 1)|| (turn == 0))
	{
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
				printf("Mhh, bumpy road: %c\n", c) ;
				break ;
		}/*
	printf("la = %d\n", la);
	printf("lo = %d\n", lo);*/
	}
	else
	{
		switch(c)
		{
			case '^':
				robola++  ;
			//	printf("la = %d\nlo = %d\n", la, lo) ;
				break ;
			case 'v':
				robola--  ;
			//	printf("la = %d\nlo = %d\n", la, lo) ;
				break ;
			case '<':
				robolo--  ;
			//	printf("la = %d\nlo = %d\n", la, lo) ;
				break ;
			case '>':
				robolo++  ;
			//	printf("la = %d\nlo = %d\n", la, lo) ;
				break ;
			default:
				printf("Mhh, bumpy road: %c\n", c) ;
				break ;
		}/*
	printf("robola = %d\n", robola);
	printf("robolo = %d\n", robolo);*/
	}
}

void input_file()
{
  printf("What's the name of the instructions file? ")       ;
  scanf("%s", file)                                           ;
}

/*

Uno schema cartesiano.
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