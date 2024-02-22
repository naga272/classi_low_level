#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "persona.h"


struct person Persona(const char* nome, const char* cognome, unsigned short int eta){
	/*
	 *
	 *	Funzione usata per istanziare la struct, attribuisce i valori nome, cognome
	 *	eta e attribuisce gli indirizzi delle funzioni ai puntatori inc_eta e str.
	 *	
	 *	Cosi quando il programmatore dovra chiamare un metodo al posto di fare:
	 *	incremento_eta(<nome_struct>);
	 *	return__str__(<nome_struct>);
	 *
	 * 	dovra fare:
	 *	<nome_struct>.inc_eta(<nome_struct>); 	// la struct passato come parametro e' l'equivalente del 'self'
	 *	<nome_struct.str(<nome_struct>);
	 * 	Una volta assegnato tutti i valori viene ritornata la struct coi valori assegnati
	 * 
	*/
	struct person init = {

		// proprieta dell'oggetto
		.nome 		= nome,
		.cognome 	= cognome,	
		.eta 		= eta,


		/*		metodi		*/
		// assegnazione dell'indirizzo della funzione ai puntatori,
		.inc_eta 	= incrementa_eta, 	// dal main, la funzione e' chiamabile così: <oggetto>.inc_eta(<oggetto>)
		.str 		= return__str__		// dal main, la funzione e' chiamabile cosi: <oggetto>.str(<oggetto>)
	};

	return init;	// ritorno in pratica la struct con i valori impostati (come avviene in python col costruttore __init__())
}


		/*		METODI			*/
unsigned short int incrementa_eta(struct person oggetto){
	// funzione che incrementa l'eta della persona di 1
	// il problema e' che non aggiorna in automatico il valore della struct
	return oggetto.eta++;
}


char* return__str__(struct person oggetto){
	
	// mi assicuro che nessun header ha una macro chiamata BUFFER_SIZE
	#ifndef BUFFER_SIZE
		#define BUFFER_SIZE 200
		static char stringa[BUFFER_SIZE];
	#else	// interrompo il programma perche' rischio di sovrascrivere la macro dell'header
		printf("error in function __str__: macro BUFFER_SIZE already defined");
		_exit(EXIT_FAILURE);
	#endif

	// converto tutte le proprieta in formato vettore di caratteri
	sprintf(stringa, "nome: %s, cognome: %s, eta: %d\n", oggetto.nome, oggetto.cognome, oggetto.eta);

	return stringa; // ritorno il vettore di caratteri come avviene in python con il costruttore __str__()
}


int main(int argc, char *argv[], char *envp[]){
	setlocale(LC_CTYPE, " ");

	// ritorna una istanza della struct con valori gia assegnati
	struct person prova = Persona("Mario", "rossi", 19);

	// verifico che i valori sono stati assegnati correttamente
	printf("%s", prova.str(prova));

	// incremento eta
	prova.inc_eta(prova);

	// verifico se prova.eta e' stato incrementato
	printf("%s", prova.str(prova));	// non viene incrementato

	return EXIT_SUCCESS;
}

