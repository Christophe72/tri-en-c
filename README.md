# Reprise en main C

Ce projet propose une base simple en langage C pour manipuler, compiler et executer deux algorithmes classiques de tri : le tri a bulles et le tri par insertion.

Le programme compile un unique fichier source, applique chaque algorithme sur un tableau de test identique, puis affiche les resultats avant et apres tri.

## Objectifs

- reviser la syntaxe de base du langage C
- comprendre le fonctionnement de deux algorithmes de tri simples
- manipuler une compilation locale avec GCC
- disposer d'un exemple minimal pour experimentation ou apprentissage

## Contenu du projet

- `bubble_sort.c` : implementation des fonctions de tri et point d'entree `main`
- `Makefile` : compilation du programme avec `make`
- `build.bat` : compilation du programme sous Windows via un script batch

## Prerequis

La configuration actuelle suppose que GCC est installe a l'emplacement suivant :

`C:\gcc-15.2.0\bin\gcc.exe`

Si votre installation utilise un autre chemin, adaptez la variable `CC` dans les fichiers suivants :

- `Makefile`
- `build.bat`

## Compilation

### Avec le script batch

```bat
build.bat
```

### Avec Make

```bash
make
```

## Execution

Sous Windows :

```bat
bubble_sort.exe
```

## Nettoyage

Avec le script batch :

```bat
build.bat clean
```

Avec Make :

```bash
make clean
```

## Comportement du programme

Le programme effectue les operations suivantes :

1. Affiche le tableau initial
2. Applique le tri a bulles sur une premiere copie
3. Applique le tri par insertion sur une seconde copie
4. Affiche les tableaux obtenus apres tri

Cette approche permet de comparer facilement les deux implementations sur un meme jeu de donnees.

## Exemple de sortie

Voici un exemple de sortie typique lors de l'execution du programme :

```
Avant : 64 34 25 12 22 25 90 8 0 -1 
Apres  : -1 0 8 12 22 25 25 34 64 90 
Apres insertion : -1 0 8 12 22 25 25 34 64 90 
```

Les valeurs peuvent varier si vous modifiez le tableau de test dans le code source.

## Auteur

Projet realise dans le cadre d'une reprise en main du langage C.

Vous pouvez remplacer cette section par votre nom, votre pseudo ou le nom de votre organisation.

## Licence

Aucune licence n'est definie pour le moment.

Si vous souhaitez rendre ce projet reutilisable publiquement, vous pouvez ajouter un fichier `LICENSE` et preciser ici la licence retenue, par exemple MIT.