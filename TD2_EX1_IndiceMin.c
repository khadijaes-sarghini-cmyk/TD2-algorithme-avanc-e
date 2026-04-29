#include <stdio.h>

/* * EXERCICE 1 : Recherche de l'indice de la première occurrence du minimum
 * Complexité calculée : T(n) = 4n - 2
 * Ordre de grandeur : O(n)
 */

#define N 10 // Taille définie selon l'exemple de l'énoncé

int trouverIndiceMin(int tab[N]) {
    int i;
    int index = 0; // 1 affectation initiale

    // La boucle s'exécute n-1 fois
    for(i = 1; i < N; i++) {
        // Comparaison : n-1 fois
        // On utilise '<' pour garder la PREMIÈRE occurrence du minimum
        if(tab[i] < tab[index]) {
            index = i; // Affectation : n-1 fois dans le pire des cas
        }
    }
    
    return index;
}

int main() {
    // Exemple de l'énoncé : 5,2,4,2,1,7,9,4,1,1
    // Le minimum est 1. Il apparaît aux indices 4, 8 et 9.
    // Le programme doit retourner l'indice 4.
    int tableau[] = {5, 2, 4, 2, 1, 7, 9, 4, 1, 1};
    
    int resultat = trouverIndiceMin(tableau);
    
    printf("Tableau : 5, 2, 4, 2, 1, 7, 9, 4, 1, 1\n");
    printf("L'indice de la premiere occurrence du minimum est : %d\n", resultat);
    
    return 0;
}
