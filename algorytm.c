#include "algorytm.h"//srfaeteaw
#include "array.h"
<<<<<<< HEAD
sdasds
asdas
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> remotes/origin/test

int sasiedzi(int** tab, int wier, int kol){
	int i, j, n=0;
	for(i=(wier-1); i<=(wier+1); i++){
		for(j=(kol-1); j<=(kol+1); j++){
			if(tab[i][j] == ZYWA)
				n++;
		}	
	}
	if(tab[wier][kol] == ZYWA)
		n--;
	return n;
}

int **algorytm(int **tab, int wier, int kol){
    int i, j;
    int **tab_pom = create_tab(wier, kol);
    for(i=1; i<wier-1; i++){
        for(j=1; j<kol-1; j++){
            if(tab[i][j] == ZYWA){
                if(sasiedzi(tab, i, j) == 2 || sasiedzi(tab, i, j) == 3)
					tab_pom = insert_tab(tab_pom, i, j, ZYWA);
    		}
			else if(tab[i][j] == MARTWA && sasiedzi(tab, i, j) == 3)			
				insert_tab(tab_pom, i, j, ZYWA);
	
        }
    }
   
    return tab_pom;
}

void cz_ekran(){
	printf("\033[2J"); //Czyści ekran
	printf("\033[K"); //Ustawia kursor w lewym, górnym rogu
}
