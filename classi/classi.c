#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/*
 	Sto cercando di implementare a basso livello la classe chiamata Persona. 
	In python l'implementazione sarebbe:

	class Persona:
		def __init__(self, nome:str, cognome:str, eta:int):
			self.nome = nome
			self.cognome = cognome,
			self.eta = eta
		
		def incrementa_eta(self):
			self.eta += 1

		def __str__(self):
			return f"{self.nome}, {self.cognome}, {self.eta}"
*/



// prototype per funzioni
struct person Persona(const char*, const char*, unsigned short int); // funzione che serve a generare una istanza della classe 

unsigned short int incrementa_eta(void); 	// metodo della classe che incrementa la proprieta eta della struct
const char* return__str__(void);		// metodo della classe che ritorna un vettore di caratteri contenente i valori delle proprieta


// modello generale della classe
struct person{

	// proprieta classe
	const char* nome;
	const char* cognome;
	unsigned short int eta;


	// puntatore a funzione (metodi della classe)
	short unsigned int (*inc_eta)(void); 
	const char*(*str)(void);
};





int main(int argc, char *argv[], char *envp[]){
	setlocale(LC_CTYPE, " ");

	// ritorna una istanza della struct con valori gia assegnati
	struct person prova = Persona("Mario", "rossi", 19);

	// verifico che i valori sono stati assegnati correttamente
	printf("nome: %s cognome: %s eta: %d", prova.nome, prova.cognome, prova.eta);

	return EXIT_SUCCESS;
}



// funzione usata per istanziare la struct
struct person Persona(const char* nome, const char* cognome, unsigned short int eta){

	struct person init = {

		// proprieta dell'oggetto
		.nome = nome,			
		.cognome = cognome,		
		.eta = eta,


		// assegnazione dell'indirizzo della funzione ai puntatori,
		// cosi, si puo scrivere:
		// <nome_struct>.inc_eta() oppure <nome_struct>.str()
		.inc_eta = incrementa_eta,
		.str = return__str__
	};

	return init;
}




/*		METODI		*/
// come posso ora da funzione accedere ai valori della struct??
unsigned short int incrementa_eta(){
	
	return 0;
}



const char* return__str__(){

	return "";
}
