#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int **create_tab(int wier, int kol){
    int **tab,i;
    tab = (int**)calloc(wier,sizeof(int*));
    if(tab == NULL){
        printf("Nie udalo sie zaalokowac pamieci");
		//free(tab);        
		return NULL;
    }
    for(i=0; i<wier; i++){
        tab[i] = (int*)calloc(kol,sizeof(int));
        if(tab[i] == NULL){
            printf("Nie udalo sie zaalokowac pamieci");
			//delete_tab(&tab, i);            
			return NULL;
        }
    }
return tab;
}

int **resize_tab(int **tab, int wier, int kol, int wier_add, int kol_add){
    int i,j, **tab2 = create_tab((wier+wier_add), (kol+kol_add));

    for(i=0; i<wier; i++){
        for(j=0; j<kol; j++)
            tab2[i][j] = tab[i][j];
    }
    delete_tab(&tab, wier);
    return tab2;
}

int at_tab(int **tab, int wier, int kol){
    return tab[wier][kol];
}

int **insert_tab(int **tab, int wier, int kol, int element){
    tab[wier][kol] = element;
    return tab;
}

void wyswietl_tab(int **tab, int wier, int kol){
	int i, j;
	for(i=0; i<wier; i++){
		for(j=0; j<kol; j++){
			if(tab[i][j] != 0) 
				printf("+");
			else 	
				printf(" ");
			}
			printf("\n");
	}
}

void delete_tab(int***tab, int wier){
    int i;
    for(i=0; i<wier; i++)
        free((*tab)[i]);
    free(*tab);
}
