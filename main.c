/*************************************************************************************/
/*************************************************************************************/
/*******************    Autor: Marc Isidre Balada Fibla         **********************/
/*******************    Data: 04/02/2022                        **********************/
/*******************    Funcionalitat: programa principal       **********************/
/*************************************************************************************/
/*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"

int main()
{
    FILE *f1;
    char fitxer[MAX_PARAULA];
    int velocitat, yodificacio, num_frases;
    Frase taula_frases[MAX_FRASES];

    printf("Introdueixi el nom del fitxer a processar: ");
    scanf("%s", fitxer);

    f1 = fopen (fitxer,"r");

    if (f1 != NULL){

        printf("\nIntrodueixi la velocitat de parla: ");
        do{
            menu_velocitats();
            scanf("%d", &velocitat);

            switch(velocitat){
                case 0: printf("\nvelocitat 0: normal\n");
                    break;
                case 1: printf("\nvelocitat 1: lent\n");
                    break;
                case 2: printf("\nvelocitat 2: molt lent\n");
                    break;
                default: printf("\nOpcio incorrecta\n\nTorni a introduir la velocitat de parla: ");
                    break;
            }
        }while((velocitat!=0)&&(velocitat!=1)&&(velocitat!=2));

        printf("\nIntrodueixi el coeficient de yodificacio: ");

        do{
            menu_yodificacio();
            scanf("%d", &yodificacio);

            switch(yodificacio){
                case 0: printf("\nyodificacio 0: sense yodificacio\n");
                    break;
                case 1: printf("\nyodificacio 1: yodificacio normal\n");
                    break;
                case 2: printf("\nyodificacio 2: yodificacio alta\n");
                    break;
                default: printf("\nOpcio incorrecta\n\nTorni a introduir el coeficient de yodificacio: ");
                    break;
            }
        }while((yodificacio!=0)&&(yodificacio!=1)&&(yodificacio!=2));

        num_frases = llegir_fitxer(f1, taula_frases);

        imprimir_frases(taula_frases, num_frases);

        if (yodificacio != 0){

            desordenar(taula_frases, num_frases, yodificacio);
            borrar_punt(taula_frases, num_frases);
            afegir_punt(taula_frases, num_frases);
        }

        if (velocitat != 0){

            ralentitzacio(taula_frases, num_frases, velocitat);
        }

        imprimir_frases(taula_frases, num_frases);

        dibuixa_yoda();

        fclose(f1);

        f1 = fopen ("mestre_yoda.txt","w");

        escriure_fitxer(f1, taula_frases, num_frases);

        printf("\n\n\n");

        if (f1 != NULL){
            printf("Document 'mestre_yoda.txt' generat correctament.\n");
        }else{
            printf("El document 'mestre_yoda.txt' NO s'ha pogut generar!\n");
        }

        fclose(f1);

    }else{
        printf("\nEl fitxer no existeix!\n");
    }
    return 0;
}
