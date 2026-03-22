#include <stdio.h>
#include "saisie.h"

int saisir_tableau_complet(int values[], int max_length) {
	int itemCount;
	printf("Combien de valeurs voulez-vous trier ? ");
	scanf("%d", &itemCount);
	if (itemCount <= 0 || itemCount > max_length) {
		printf("Nombre invalide. Choisissez un nombre entre 1 et %d.\n", max_length);
		return -1;
	}
	printf("Veuillez entrer %d entiers :\n", itemCount);
	for (int i = 0; i < itemCount; i++) {
		printf("Valeur %d : ", i + 1);
		scanf("%d", &values[i]);
	}
	return itemCount;
}
