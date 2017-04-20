#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>

int **create_tab(int, int);
int **resize_tab(int**, int, int, int, int);
int at_tab(int**, int, int);
int **insert_tab(int**, int, int, int);
void wyswietl_tab(int**, int, int);
void delete_tab(int***, int);


#endif
