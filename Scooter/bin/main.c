#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "scooter.h"

char* test(struct scooter* oggetto){

	return "ho cambiato l'indirizzo del puntatore";
}



int main(int argc, char *argv[], char *envp[]){
	setlocale(LC_CTYPE, " ");

	struct scooter* p1 = Scooter(12.0, 5.0, 1.0, 4.5);
	struct scooter* p2 = Scooter(12.0, 5.0, 1.0, 4.5);

	// come si potrebbe rendere visibile ma non modificabile?
	p1->id = 23;

	printf("%s\n", p1->__str__(p1));

	// assegno un nuovo indirizzo al puntatore
	p1->__str__ = test;

	printf("%s\n", p1->__str__(p1));

	p1->__del__(p1);
	p2->__del__(p2);
	return EXIT_SUCCESS;
}

