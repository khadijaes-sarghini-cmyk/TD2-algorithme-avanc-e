#include <stdio.h>

/* * EXERCICE 2 : Recherche de la valeur MiniMax d'une matrice
 * Définition : Le minimum des maximums de chaque ligne.
 * Complexité : T(n,m) = 4nm + 3n - 2 => O(n*m)
 */

#define N 3
#define M 3

int MiniMax(int tab[N][M]) {
    int i, j;
    int max;
    int minimax;

    for (i = 0; i < N; i++) {
        // Initialisation du max avec le premier élément de la ligne
        max = tab[i][0];

        // Boucle pour trouver le maximum de la ligne i
        for (j = 1; j < M; j++) {
            if (tab[i][j] > max) {
                max = tab[i][j];
            }
        }

        // Si c'est la première ligne, on initialise minimax avec son max
        if (i == 0) {
            minimax = max;
        } 
        // Sinon, on compare pour garder le plus petit maximum
        else if (max < minimax) {
            minimax = max;
        }
    }
    return minimax;
}

int main() {
    // Exemple de l'énoncé
    int t[3][3] = {
        {2, 3, 4},  // Max ligne 0 = 4
        {5, 6, 7},  // Max ligne 1 = 7
        {8, 9, 10}  // Max ligne 2 = 10
    };
    
    // Le minimum de {4, 7, 10} est 4.
    printf("La valeur MiniMax est = %d\n", MiniMax(t));

    return 0;
}
