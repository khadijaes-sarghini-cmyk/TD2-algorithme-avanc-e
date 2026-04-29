#include <stdio.h>

/* * EXERCICE 3 : Algorithmes Récursifs et Étude de Complexité
 * -------------------------------------------------------
 * Ce programme suit la correction officielle du TD2 :
 * 1. Puissance classique : O(n)
 * 2. Exponentiation rapide : O(ln(n)) - Méthode optimisée
 * 3. Somme des puissances : O(n²)
 */

/* 1. Fonction puissance classique (a^i) */
int puissance(int a, int i) {
    if (i == 0) 
        return 1;
    else 
        return (a * puissance(a, i - 1));
}

/* 2. Méthode d'exponentiation rapide (Structure du Prof) */
int expRapide(int a, int i) {
    if (i == 0) 
        return 1;
    else if (i % 2 == 0) 
        // On calcule (a^(i/2))^2 récursivement
        return expRapide(expRapide(a, i / 2), 2);
    else 
        // On calcule a * (a^(i/2))^2 récursivement
        return a * expRapide(expRapide(a, i / 2), 2);
}

/* 3. Fonction somme récursive (Somme de i=0 à n de a^i) */
int somme(int a, int n) {
    if (n == 0) 
        return 1;
    else 
        return (puissance(a, n) + somme(a, n - 1));
}

int main() {
    int a = 2;
    int n = 4;

    printf("--- TD2 : Exercice 3 (Correction Officielle) ---\n");
    printf("1. Puissance classique (2^%d) : %d\n", n, puissance(a, n));
    printf("2. Exponentiation rapide (2^%d) : %d\n", n, expRapide(a, n));
    printf("3. Somme des puissances (2^0 a 2^%d) : %d\n", n, somme(a, n));

    return 0;
}
