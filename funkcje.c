#include "funkcje.h"

struct Wezel* insert(struct Wezel* adres, struct Osoba nowa) {

    int i;
    struct Wezel *pom;

    pom = (struct Wezel*) malloc(sizeof(struct Wezel));
    if (pom == NULL) {
        printf("Nie udało się zaalokować pamięci");
        free(pom);
        return NULL;
    } else {
        for (i = 0; nowa.imie[i] != '\0'; i++)
            pom -> dane.imie[i] = nowa.imie[i];
        for (i = 0; nowa.nazwisko[i] != '\0'; i++)
            pom -> dane.nazwisko[i] = nowa.nazwisko[i];
        pom -> dane.telefon = nowa.telefon;

        pom -> lewy = NULL;
        pom -> prawy = NULL;
    }

    if(adres==NULL){
        adres = pom;
        return adres;
    }

    struct Wezel* tmp = adres;
    while (1) {

        if (porownaj(nowa.nazwisko, adres -> dane.nazwisko) ==2 ) {
            if (tmp -> prawy != NULL) {
                tmp = tmp -> prawy;
            } else {
                tmp -> prawy = pom;
                break;
            }
        }
        else {
            if (tmp -> lewy != NULL) {
                tmp = tmp -> lewy;
            } else {
                tmp -> lewy = pom;
                break;
            }
        }
    }
    return adres;
}

void wypisz(struct Wezel* adres){   //InOrder
    if(adres == NULL)return;

    if(adres -> lewy != NULL)wypisz(adres -> lewy);

    printf("\n%s %s %ld ", adres -> dane.nazwisko, adres -> dane.imie, adres -> dane.telefon);

    if(adres -> prawy != NULL) wypisz(adres -> prawy);
}

void minimum(struct Wezel* adres){
    if(adres == NULL){
        return;
    }
    if(adres -> lewy == NULL){
        printf("Pierwsze nazwisko to: %s \n", adres -> dane.nazwisko);
        return;
    }
    minimum(adres -> lewy);
}

void maksimum(struct Wezel* adres){
    if(adres == NULL){
        return;
    }
    if(adres -> prawy == NULL){
        printf("Ostatnie nazwisko to: %s \n", adres -> dane.nazwisko);
        return;
    }
    maksimum(adres -> prawy);
}

int policz(struct Wezel* adres){
    if(adres == NULL){
        return 0;
    }
    return policz(adres -> lewy) + policz(adres -> prawy) + 1;
}

void wyszukaj(struct Wezel *adres, char* klucz){
    if(adres == NULL || klucz == NULL){
        return;
    }
    if(test(adres -> dane.nazwisko, klucz) == 1){
        printf("\n%s %s %ld ", adres -> dane.nazwisko, adres -> dane.imie, adres -> dane.telefon);
    }
    if(porownaj(klucz, adres -> dane.nazwisko) == 1) wyszukaj(adres -> lewy, klucz);
    else wyszukaj(adres -> prawy, klucz);
}

int wysokosc(struct Wezel* adres){
    if(adres == NULL) return -1;
    int w1 = wysokosc(adres -> lewy);
    int w2 = wysokosc(adres -> prawy);
    return 1 + (w1 > w2 ? w1 : w2);
}

short test(char slowo1[NAZW], char slowo2[NAZW]) {
    int i;

    if(strlen(slowo1) != strlen(slowo2)) return 0;

    for(i = 0; i < strlen(slowo1); i++) {  //zamiast NAZW
        if(slowo1[i] != slowo2[i]) {
            return 0;
        }
    }
    return 1;
}

short porownaj(char slowo1[NAZW], char slowo2[NAZW]) {
    int i;

    for(i = 0; (slowo1[i] != '\0' && slowo2[i] != '\0'); i++) {
        if(slowo1[i] < slowo2[i]) {
            return 1;
        }
        else if(slowo1[i] > slowo2[i]){
            return 2;
        }
    }
    return 1;
}
