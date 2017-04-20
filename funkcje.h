#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <stdio.h>
#include <stdlib.h>
#define IMIE 15
#define NAZW 20

#include <string.h>

struct Osoba{
    char imie[IMIE];
    char nazwisko[NAZW];
    long int telefon;
};

struct Wezel{
        struct Osoba dane;
        struct Wezel *lewy;
        struct Wezel *prawy;
};

struct Wezel * insert(struct Wezel*, struct Osoba);
void wypisz(struct Wezel*);
void minimum(struct Wezel*);
void maksimum(struct Wezel*);
int policz(struct Wezel*);
void wyszukaj(struct Wezel*, char*);
short porownaj(char*, char*);
short test(char*, char*);
int wysokosc(struct Wezel*);

#endif
