#include <stdio.h>
#include "bubble_sort.h"
#include "saisie.h"

int main() {
    int originalArray[100];
    int itemCount = saisir_tableau_complet(originalArray, 100);
    if (itemCount <= 0) {
        return 1;
    }

    int bubbleArray[100], insertionArray[100];
    for (int i = 0; i < itemCount; i++) {
        bubbleArray[i] = originalArray[i];
        insertionArray[i] = originalArray[i];
    }

    printf("Avant : ");
    for (int index = 0; index < itemCount; index++)
        printf("%d ", originalArray[index]);
    printf("\n");

    sort_array(bubbleArray, itemCount);

    printf("Apres  : ");
    for (int index = 0; index < itemCount; index++)
        printf("%d ", bubbleArray[index]);
    printf("\n");

    sort_array_insertion(insertionArray, itemCount);

    printf("Apres insertion : ");
    for (int index = 0; index < itemCount; index++)
        printf("%d ", insertionArray[index]);
    printf("\n");

    return 0;
}
