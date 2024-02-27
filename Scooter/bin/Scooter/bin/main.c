#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "scooter.h"

char* test(struct scooter* oggetto){

	return "ho cambiato l'indirizzo del puntatore a funzione";
}



int main(int argc, char *argv[], char *envp[]){
	setlocale(LC_CTYPE, " ");
	struct scooter *p1 = Scooter(12.0, 13.0, 15, 18);

	printf("capacità: %.2f\n", p1 -> capacita);
	p1 -> capacita = 18.0;

	printf("capacità: %.2f\n", p1->capacita);

	return EXIT_SUCCESS;
}

