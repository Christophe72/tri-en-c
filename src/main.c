#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.h"
#include "saisie.h"

static void afficher_tableau(const char *label, const int values[], int length) {
	printf("%s", label);

	if (length <= 30) {
		for (int index = 0; index < length; index++) {
			printf("%d ", values[index]);
		}
	} else {
		for (int index = 0; index < 15; index++) {
			printf("%d ", values[index]);
		}
		printf("... ");
		for (int index = length - 5; index < length; index++) {
			printf("%d ", values[index]);
		}
		printf("(total : %d valeurs)", length);
	}

	printf("\n");
}

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

	printf("\n--- Tableaux non tries ---\n");
	afficher_tableau("Tableau initial           : ", originalArray, itemCount);
	afficher_tableau("Copie pour tri a bulles   : ", bubbleArray, itemCount);
	afficher_tableau("Copie pour tri insertion  : ", insertionArray, itemCount);
	printf("\n");

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

	printf("--- Tableaux tries ---\n");
	afficher_tableau("Apres tri a bulles       : ", bubbleArray, itemCount);
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

	afficher_tableau("Apres tri insertion      : ", insertionArray, itemCount);
	printf("Temps tri insertion : %.8f ms (moyenne sur %d repetitions)\n", avg_insertion, repeat);
	printf("Temps total tri insertion : %.3f ms\n", total_insertion);

	//ajoute une pause de 15 secondes pour permettre à l'utilisateur de voir les résultats avant que la console ne se ferme	
	printf("Appuyez sur Entrée pour continuer...");
	getchar(); // pour consommer le '\n' laissé par scanf
	return 0;
}
	