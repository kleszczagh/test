#include "funkcje.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    struct Wezel* Korzen = NULL;
    struct Osoba dane = {0} ;
    int n = 0;

    while(n != 8){

        switch (n) {

            case 0:
                printf("\n"
                       "0) Menu \n"
                       "1) Dodaj osobę \n"
                       "2) Wypisz wszystkie dane (InOrder) \n"
                       "3) Znajdź pierwsze nazwisko wg alfabetu \n"
                       "4) Znajdz ostatnie nazwisko wg alfabetu \n"
                       "5) Policz kontakty \n"
                       "6) Wyszukaj nazwisko \n"
                       "7) Policz wysokość drzewa \n"
                       "8) Zakończ program \n");
                break;


            case 1:
                printf("\nWpisz imię: ");
                scanf("%s", &dane.imie);
                printf("Wpisz nazwisko: ");
                scanf("%s", &dane.nazwisko);
                printf("Wpisz nr. telefonu: ");
                scanf("%ld", &dane.telefon);
                Korzen = insert(Korzen, dane);
                printf("Wpisu dokonano pomyślnie. \n");
                break;


            case 2:
                wypisz(Korzen);
                break;

            case 3:
                minimum(Korzen);
                break;

            case 4:
                maksimum(Korzen);
                break;
            case 5:
                printf("W pamięci jest zapisane %d kontaktów. \n", policz(Korzen));
                break;

            case 6:{
                char klucz[NAZW];
                printf("Wpisz nazwisko \n");
                scanf("%s", klucz);
                wyszukaj(Korzen, klucz);
                break;}

            case 7:
                printf("Wysokość drzewa wynosi %d \n", wysokosc(Korzen));
                break;

            case 8:
                return 0;

            default:
                break;
        }
        printf("\n\nCo chcesz zrobić: ");
        scanf("%d", &n);
        if(n > 8 || n < 0){
            printf("Podano zly numer! \n");
        }
    }
}
