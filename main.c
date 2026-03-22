#include <stdio.h>
#include "bubble_sort.h"
#include "saisie.h"

int main() {
    int itemCount;
    printf("Combien de valeurs voulez-vous trier ? ");
    scanf("%d", &itemCount);
    if (itemCount <= 0 || itemCount > 100) {
        printf("Nombre invalide. Choisissez un nombre entre 1 et 100.\n");
        return 1;
    }
    int originalArray[100];
    saisir_tableau(originalArray, itemCount);

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
