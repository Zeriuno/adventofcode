#include <stdio.h>

/*

Uno schema cartesiano.
La casella di partenza ed ogni nuova casella ulteriore vengono contate

Latitudine = 0
Longitudine = 0

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