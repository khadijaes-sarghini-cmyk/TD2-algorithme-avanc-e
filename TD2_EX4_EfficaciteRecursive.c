#include <stdio.h>

/**
 * EXERCICE 4 : Comparaison d'efficacité entre deux fonctions récursives
 * --------------------------------------------------------------------
 * Les deux fonctions calculent 2^n, mais avec des structures différentes.
 * rec1 : Récursion simple (linéaire)
 * rec2 : Récursion double (exponentielle) -> Très inefficace !
 */

/* Calcule 2^n avec une complexité O(n) */
int rec1(int n) {
    if (n == 0) return 1;
    else return 2 * rec1(n - 1);
}

/* Calcule 2^n avec une complexité O(2^n) */
int rec2(int n) {
    if (n == 0) return 1;
    else return (rec2(n - 1) + rec2(n - 1));
}

int main() {
    int n = 5;
    printf("--- TD2 : Exercice 4 ---\n");
    printf("rec1(%d) = %d (Efficace)\n", n, rec1(n));
    printf("rec2(%d) = %d (Inefficace)\n", n, rec2(n));
    return 0;
}
