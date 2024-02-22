
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


#ifndef checker 
	// se il parametro x corrisponde a verita allora significa che e' avvenuto un errore, 
	// quindi deve mostrare a schermo l'errore (msg) e esce dal programma
	#define checker(x, msg) 					\
		if(x){							\
			printf("errore: %s", msg); exit(EXIT_FAILURE);	\
		}
#else
	#error, "macro checker already defined"
#endif

// prototype per istanziare gli oggetti
struct person* Persona(const char*, const char*, unsigned short int); // funzione che serve a generare una istanza della classe 


// classe persona
struct person{

	// proprieta classe
	char
		* nome,
		* cognome;

	unsigned short int 
		eta;

	// puntatore a funzione (metodi della classe)
	void			(*inc_eta)	(struct person*); 
	void 			(*__del__)	(struct person*);
	char*			(*__str__)	(struct person*);
};


// prototype dei metodi della classe Person
static void 	incrementa_eta(struct person*); // metodo che incrementa la proprieta eta della struct
static void	object_delete(struct person*);	// metodo che deve eliminare l'oggetto
static char* 	return__str__(struct person*);	// metodo che ritorna un vettore di caratteri contenente i valori delle proprieta


struct person* Persona(const char* nome, const char* cognome, unsigned short int eta){
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
	 *	<nome_struct>->inc_eta(<nome_struct>); 	// la struct passato come parametro e' l'equivalente del 'self'
	 *	<nome_struct>->str(<nome_struct>);
	 * 	Una volta assegnato tutti i valori viene ritornata la struct coi valori assegnati
	 * 
	*/

	struct person* __init__ 	= (struct person*) malloc(sizeof(struct person));
	checker(__init__ == NULL, "errore nell'allocare dinamicamente l'oggetto (problema struct)");

	__init__ -> nome 		= (char*) malloc(strlen(nome) - 1);
	__init__ -> cognome 		= (char*) malloc(strlen(cognome) - 1);

	checker(((__init__ -> nome == NULL) || (__init__ -> cognome == NULL)), "errore nell'allocare dinamicamente le proprieta dell'oggetto");


	/*	assegnazione valori alle proprieta'	*/
	strcpy(__init__ -> nome, nome);
	strcpy(__init__ -> cognome, cognome);
	__init__ -> eta 		= eta;

	/*		metodi della classe		*/
	__init__ -> inc_eta 		= incrementa_eta; 	// dal main, la funzione e' chiamabile così: <oggetto>->inc_eta(<oggetto>);
	__init__ -> __str__ 		= return__str__;	// dal main, la funzione e' chiamabile cosi: <oggetto>->__str__(<oggetto>);	
	__init__ -> __del__		= object_delete;	// dal main, la funzione e' chiamabile cosi: <oggetto>->__del__(<oggetto>);

	return __init__;	// ritorno in pratica la struct con tutti i valori impostati
}


		/*		METODI			*/
static void incrementa_eta(struct person* oggetto){
	// funzione che incrementa l'eta della persona di 1
	oggetto->eta++;
}


static char* return__str__(struct person* oggetto){
	#ifndef BUFFER_SIZE
		#define BUFFER_SIZE 128
	#else
		free(oggetto);	// prima di far terminare il programma libero la memoria
		checker(1, "macro BUFFER_SIZE already defined");
	#endif

	static char stringa[BUFFER_SIZE];
	sprintf(stringa, "nome: %s cognome: %s eta: %d\n", oggetto->nome, oggetto->cognome, oggetto->eta);	

	return stringa;
}


static void object_delete(struct person* oggetto){
	free(oggetto);
}
