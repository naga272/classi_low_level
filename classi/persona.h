
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



// prototype per istanziare gli oggetti
struct 	person Persona(const char*, const char*, unsigned short int); // funzione che serve a generare una istanza della classe 

// prototype dei metodi della classe Person<
unsigned short int 	incrementa_eta(struct person); 		// metodo che incrementa la proprieta eta della struct
char* 			return__str__(struct person);		// metodo che ritorna un vettore di caratteri contenente i valori delle proprieta


// classe persona
struct person{

	// proprieta classe
	const char* nome;
	const char* cognome;
	unsigned short int eta;


	// puntatore a funzione (metodi della classe)
	unsigned short int 	(*inc_eta)	(struct person); 
	char*			(*str)		(struct person);
};

