
/*************************************************************************************/
/*************************************************************************************/
/*******************    Autor: Marc Isidre Balada Fibla           ********************/
/*******************    Data: 04/02/2022                          ********************/
/*******************    Funcionalitat: fitxer amb les capçaleres  ********************/
/*************************************************************************************/
/*************************************************************************************/

#define MAX_PARAULA 20
#define MAX_PARAULES 50
#define MAX_FRASES 15

typedef struct{
    char paraula[MAX_PARAULA];
    bool ultima_paraula;

} Paraula;

typedef struct{
    Paraula paraules[MAX_PARAULES];
    int num_paraules;

} Frase;

bool paraula_final(char paraula[]);

int llegir_fitxer(FILE *f, Frase fra[]);

void imprimir_frases(Frase frase[], int n_frases);

void desordenar(Frase frase[], int n_frases, int coeficient);

void ralentitzacio(Frase frase[], int n_frases, int velocitat);

void borrar_punt (Frase frase[], int num_frases);

void afegir_punt(Frase frase[], int num_frases);

void escriure_fitxer(FILE *f, Frase frase[], int num_frases);

void menu_velocitats();

void menu_yodificacio();

void dibuixa_yoda();
