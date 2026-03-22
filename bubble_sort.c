#include <stdio.h>

void bubble_sort(int values[], int length) {
    for (int passIndex = 0; passIndex < length - 1; passIndex++) {
        for (int compareIndex = 0; compareIndex < length - passIndex - 1; compareIndex++) {
            if (values[compareIndex] > values[compareIndex + 1]) {
                int tempValue = values[compareIndex];
                values[compareIndex] = values[compareIndex + 1];
                values[compareIndex + 1] = tempValue;
            }
        }
    }
}

void insertion_sort(int values[], int length) {
    for (int currentIndex = 1; currentIndex < length; currentIndex++) {
        int currentValue = values[currentIndex];
        int insertionIndex = currentIndex - 1;

        while (insertionIndex >= 0 && values[insertionIndex] > currentValue) {
            values[insertionIndex + 1] = values[insertionIndex];
            insertionIndex--;
        }
        values[insertionIndex + 1] = currentValue;
    }
}

void sort_array(int values[], int length) {
    bubble_sort(values, length);
}

void sort_array_insertion(int values[], int length) {
    insertion_sort(values, length);
}

int main() {
    int bubbleArray[] = {64, 34, 25, 12, 22, 25, 90,8, 0, -1};
    int insertionArray[] = {64, 34, 25, 12, 22, 25, 90,8, 0, -1};
    int itemCount = sizeof(bubbleArray) / sizeof(bubbleArray[0]);

    printf("Avant : ");
    for (int index = 0; index < itemCount; index++)
        printf("%d ", bubbleArray[index]);
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
