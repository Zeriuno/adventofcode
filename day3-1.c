#include <stdio.h>

void check()  ;
void move()   ;
main()
{
	int la = 0, lo = 0      ;
	int cordinates[2][1000] ;
	int houses = 0          ;

	int i                   ;

	char c                  ;

	/*get the file and open it*/
	while(!feof)
	{
		check() ;
		/*read a char*/
		/*change coordinates*/
	}
	/*close the file*/
	printf("Santa visited so many houses : %d", houses) ;
}

void check()
	{
		i = 0 ;
		while(i < houses)
		{
			if!((coordinates[0][i] == la ) && (coordinates[1][i] == lo ))
				i++                     ;
			else
				i = houses + 1          ;
		}
		if(i > houses)
		{
			coordinates[0][houses] = la ;
			coordinates[1][houses] = lo ;
			houses++                    ;
		}
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

Coordinate [][]

Ad ogni passo latitudine e longitudine vanno in una tabella se percorrendo la tabella non si trovano gli stessi valori

/recherche
cursor = 0
while (cursor < houses)
{
	if !((coordinates[1][cursor] == la) && (coordinates[2][cursor] == lo))
	{
	cursor++  ;
	}
	else
	{
	    cursor = houses+1;
	}
}
if (cursor == houses)
{
	coordinates[1][cursor] = la ;
	coordinates[2][cursor] = lo ;
	houses++ ;
}


Longitudine:

<  lo--
>  lo++

Latitudine:

^  la++
v  la--




main ()
{
	FILE *f1 ;
	char c ;
	f1 = fopen("input-day3.txt", "r");

	fscanf(f1, "%c", &c) ;
	while(!feof)
	{
		switch(c)
		{
			case '^':
				printf("yo");
			case '>':
				printf("yo");
			break;
		}
		fscanf(f1, "%c", &c) ;
		printf("Another one\n");
	}
	printf("Fait.\n");
	return 0 ;
}