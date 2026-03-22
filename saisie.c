#include <stdio.h>
#include "saisie.h"

void saisir_tableau(int values[], int length) {
    printf("Veuillez entrer %d entiers :\n", length);
    for (int i = 0; i < length; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &values[i]);
    }
}
