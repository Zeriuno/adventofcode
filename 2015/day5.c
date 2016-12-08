#include <stdio.h>

int main()
{
	return 0 ;
}
/*
Un ciclo di lettura che continua con una variabile di controllo

keepon = 0
while(keepon == 0)
{
	fscanf(f1, "%s")	
}

sur la base de la lecture

si `a` ou `e` ou `i` ou `o` ou `u`
	voyelle++
si `a` ou `c` ou `d` ou `ou` `x` (ab, cd, pq, or xy)
	lire un autre caractère
		si celui-ci est égal au premier
			double = 1
		sinon si
			caractère1 == a
				si caractère2 == b
			... ou bien on met les char dans un int et on vérifie si le deuxième est égal au premier plus un.
			keepon = 0

*/

/*
To improve using this (or something else from here: https://stackoverflow.com/questions/1071542/in-c-check-if-a-char-exists-in-a-char-array)
#include <stdio.h>
#include <string.h>

// This code outputs: h is in "This is my test string"
int main(int argc, char* argv[])
{
   const char *invalid_characters = "hz";
   char *mystring = "This is my test string";
   char *c = mystring;
   while (*c)
   {
       if (strchr(invalid_characters, *c))
       {
          printf("%c is in \"%s\"\n", *c, mystring);
       }

       c++;
   }

   return 0;
}

*/