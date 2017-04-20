#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "algorytm.h"
#include <unistd.h>

#define W 50
#define K 80

int main(int argc, char *argv[]){	//Parametry startowe: plik wejściowy, wyjściowy i ilość obrotów pętli
	
	FILE* plik_wej = fopen(argv[1],"r");
	FILE* plik_wyj = fopen(argv[2],"w");
	
	if(plik_wej != NULL && plik_wyj != NULL){
		int wier, kol, i, j, n=0;
		int **tab = create_tab(W, K);
		
		while(feof(plik_wej) == 0){
			fscanf(plik_wej, "%i", &wier);
			fscanf(plik_wej, "%i", &kol);
			insert_tab(tab, wier, kol, 1);
						
		}				

		wyswietl_tab(tab, W, K);
	
		while(n < *argv[3]){
			usleep(200000);			
			cz_ekran();
			tab = algorytm(tab, W, K);
			wyswietl_tab(tab, W, K);
			n++;
		}
		for(i=0; i<W; i++){
			for(j=0; j<K; j++){
				if(tab[i][j] == 1){
					fprintf(plik_wyj, "%3i %3i", i, j);
					fprintf(plik_wyj, "\n");
				}
			}
		}
	}
	else
		printf("Nie udalo sie otworzyc pliku \n");
	
	fclose(plik_wyj);
	fclose(plik_wej);
	return 0;	
}
