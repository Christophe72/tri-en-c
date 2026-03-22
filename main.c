#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.h"
#include "saisie.h"

int main() {
    int originalArray[10000];
    int itemCount;
    int mode;
    printf("Mode 1 = saisie manuelle, 2 = benchmark tableau aleatoire : ");
    scanf("%d", &mode);
    if (mode == 2) {
        printf("Taille du tableau (max 10000) : ");
        scanf("%d", &itemCount);
        if (itemCount <= 0 || itemCount > 10000) {
            printf("Nombre invalide.\n");
            return 1;
        }
        srand((unsigned int)time(NULL));
        for (int i = 0; i < itemCount; i++) {
            originalArray[i] = rand() % 100000;
        }
        printf("Tableau aleatoire genere.\n");
    } else {
        itemCount = saisir_tableau_complet(originalArray, 10000);
        if (itemCount <= 0) {
            return 1;
        }
    }

    int bubbleArray[10000], insertionArray[10000];
    for (int i = 0; i < itemCount; i++) {
        bubbleArray[i] = originalArray[i];
        insertionArray[i] = originalArray[i];
    }

    if (itemCount <= 30) {
        printf("Avant : ");
        for (int index = 0; index < itemCount; index++)
            printf("%d ", originalArray[index]);
        printf("\n");
    }

    clock_t start, end;

    int repeat;
    if (itemCount < 100) {
        repeat = 1000;
    } else {
        repeat = 10;
    }

    // Tri à bulles
    start = clock();
    for (int r = 0; r < repeat; r++) {
        for (int i = 0; i < itemCount; i++) bubbleArray[i] = originalArray[i];
        sort_array(bubbleArray, itemCount);
    }
    end = clock();
    double total_bubble = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    double avg_bubble = total_bubble / repeat;

    if (itemCount <= 30) {
        printf("Apres  : ");
        for (int index = 0; index < itemCount; index++)
            printf("%d ", bubbleArray[index]);
        printf("\n");
    }
    printf("Temps tri a bulles : %.8f ms (moyenne sur %d repetitions)\n", avg_bubble, repeat);
    printf("Temps total tri a bulles : %.3f ms\n", total_bubble);

    // Tri par insertion
    start = clock();
    for (int r = 0; r < repeat; r++) {
        for (int i = 0; i < itemCount; i++) insertionArray[i] = originalArray[i];
        sort_array_insertion(insertionArray, itemCount);
    }
    end = clock();
    double total_insertion = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    double avg_insertion = total_insertion / repeat;

    if (itemCount <= 30) {
        printf("Apres insertion : ");
        for (int index = 0; index < itemCount; index++)
            printf("%d ", insertionArray[index]);
        printf("\n");
    }
    printf("Temps tri insertion : %.8f ms (moyenne sur %d repetitions)\n", avg_insertion, repeat);
    printf("Temps total tri insertion : %.3f ms\n", total_insertion);

    return 0;
}
