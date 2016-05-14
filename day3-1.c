#include <stdio.h>

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

*/


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