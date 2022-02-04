/*************************************************************************************/
/*************************************************************************************/
/*******************    Autor: Marc Isidre Balada Fibla             ******************/
/*******************    Data: 04/02/2022                            ******************/
/*******************    Funcionalitat: fitxer amb els procediments  ******************/
/*************************************************************************************/
/*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"

bool paraula_final(char paraula[]){
    int i=0;
    bool fi = false;
    while((paraula[i] != '\0')&&(!fi)){
        if (paraula[i] == '.'){
            fi = true;
        }else{
            i++;
        }
    }
    return fi;
}

int llegir_fitxer(FILE *f, Frase fra[]){
    Paraula par;
    int i=0, j=0;
    par.ultima_paraula = false;
    fra[i].num_paraules = 1;
    while (!feof(f)){

        fscanf(f, "%s", par.paraula);
        fra[i].paraules[j] = par;
        if (paraula_final(par.paraula)){
            fra[i].paraules[j].ultima_paraula = true;
            i++;
            fra[i].num_paraules = 0;
            j = 0;
        }else{
            j++;
        }
        fra[i].num_paraules++;

    }
    return i;
}

void imprimir_frases(Frase frase[], int n_frases){
    int i, j;
    printf("\n");
    for (i=0; i<n_frases; i++){
        for (j=0; j<frase[i].num_paraules; j++){
            printf("%s ", frase[i].paraules[j].paraula);
        }
        printf("\n");
    }
}

void desordenar(Frase frase[], int n_frases, int coeficient){
    Paraula aux;
    int i=0, j=0, k, dim;
    for (i=0; i<n_frases; i++){

        if (frase[i].num_paraules != 1){
            dim = frase[i].num_paraules-1;
            k=0;

            if (coeficient == 1){
                for(j=0; j < (dim+1)/2; j+=2){

                    aux = frase[i].paraules[j];
                    frase[i].paraules[j] = frase[i].paraules[dim-k];
                    frase[i].paraules[dim-k]= aux;
                    k+=2;
                }
            }else{

                for (j=0; j < (dim+1)/2; j++){

                    aux = frase[i].paraules[j];
                    frase[i].paraules[j] = frase[i].paraules[dim-k];
                    frase[i].paraules[dim-k]= aux;
                    k++;
                }
                if (j == dim-k){
                    aux = frase[i].paraules[j];
                    frase[i].paraules[j] = frase[i].paraules[j-1];
                    frase[i].paraules[j-1]= aux;
                }
            }
        }
    }
}

void ralentitzacio(Frase frase[], int n_frases, int velocitat){
    int i, j, k, dim;
    bool trobat;
    for (i=0; i<n_frases; i++){

        if (frase[i].num_paraules != 1){
            dim = frase[i].num_paraules-1;
            if (velocitat == 1){
                for (j=1; j<dim; j+=2){

                    trobat = false;
                    k=0;
                    while ((frase[i].paraules[j].paraula[k] != '\0')&&(!trobat)){
                        if (frase[i].paraules[j].paraula[k+1] == '\0'){
                            frase[i].paraules[j].paraula[k+1] = '.';
                            frase[i].paraules[j].paraula[k+2] = '.';
                            frase[i].paraules[j].paraula[k+3] = '.';
                            frase[i].paraules[j].paraula[k+4] = '\0';
                            trobat = true;
                        }else{
                            k++;
                        }
                    }
                }
            }else{
                for (j=0; j<dim; j++){

                    trobat = false;
                    k=0;
                    while ((frase[i].paraules[j].paraula[k] != '\0')&&(!trobat)){
                        if (frase[i].paraules[j].paraula[k+1] == '\0'){
                            frase[i].paraules[j].paraula[k+1] = '.';
                            frase[i].paraules[j].paraula[k+2] = '.';
                            frase[i].paraules[j].paraula[k+3] = '.';
                            frase[i].paraules[j].paraula[k+4] = '\0';
                            trobat = true;
                        }else{
                            k++;
                        }
                    }
                }
            }
        }
    }
}

void borrar_punt (Frase frase[], int num_frases){
    int i, j, k;
    bool trobat = false;
    for(i=0; i<num_frases; i++){
        j=0;
        trobat=false;
        while((j<frase[i].num_paraules)&&(!trobat)){
            if ((frase[i].paraules[j].ultima_paraula)&&(j+1 != frase[i].num_paraules)){
                frase[i].paraules[j].ultima_paraula = false;
                trobat = true;
                k=0;
                while(frase[i].paraules[j].paraula[k] != '\0'){
                    if (frase[i].paraules[j].paraula[k] == '.'){
                        frase[i].paraules[j].paraula[k] = '\0';
                    }else{
                        k++;
                    }
                }
            }
            else{
                j++;
            }
        }
    }
}

void afegir_punt(Frase frase[], int num_frases){
    int i, j, dim;
    bool trobat = false;

    for (i=0; i<num_frases; i++){
        dim = frase[i].num_paraules-1;
        if (dim != 0){
            j=0;
            trobat = false;
            while ((frase[i].paraules[dim].paraula[j] != '\0')&&(!trobat)){
                if (frase[i].paraules[dim].paraula[j+1] == '\0'){
                    frase[i].paraules[dim].paraula[j+1] = '.';
                    frase[i].paraules[dim].paraula[j+2] = '\0';
                    trobat = true;
                }else{
                    j++;
                }
            }
        }
    }
}

void escriure_fitxer(FILE *f, Frase frase[], int num_frases){
    int i, j;
    for (i=0; i<num_frases; i++){
        for (j=0; j<frase[i].num_paraules; j++){
            fprintf(f, "%s ", frase[i].paraules[j].paraula);
        }
        fprintf(f, "\n");
    }
}

void menu_velocitats(){
    printf("\n0: velocitat normal\n1: velocitat lenta\n2: velocitat molt lenta\nEscull una opcio: ");
}


void menu_yodificacio(){
    printf("\n0: sense yodificacio\n1: yodificacio normal\n2: yodificacio alta\nEscull una opcio: ");
}


void dibuixa_yoda(){
    char yoda[4][19] = {{92, 96, 45, 45, 46, 95, 39, 46, 58, 58, 46, 96, 46, 95, 46, 45, 45, 39, 47},
        {32, 92, 32, 32, 32, 96, 32, 95, 95, 58, 58, 95, 95, 32, 39, 32, 32, 32, 47},
        {32, 32, 32, 45, 45, 58, 46, 96, 39, 46, 46, 96, 39, 46, 58, 45, 45, 32, 32},
        {32, 32, 32, 32, 32, 32, 92, 32, 96, 45, 45, 39, 32, 47, 32, 32, 32, 32, 32}};
    int i, j;
    printf("\n\n\n");
    for (i = 0; i < 4; i++){
        for (j = 0; j < 19; j++){
            printf ("%c", yoda[i][j]);
        }
        printf("\n");
    }
}

