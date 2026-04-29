#include <stdio.h>

/* * EXERCICE 3 : Optimisation de l'Exponentiation et Calcul de Somme
 * ---------------------------------------------------------------
 * Ce programme compare deux approches de calcul de puissance :
 * 1. Puissance Classique : Approche linéaire en O(n).
 * 2. Exponentiation Rapide : Approche logarithmique en O(log n), 
 * essentielle en cryptographie pour manipuler de grands nombres.
 * 3. Calcul de Somme : Calcule la somme de a^0 à a^n avec une complexité O(n²).
 */

/* 1. Fonction récursive classique : a^i */
int puissance(int a, int i) {
    if (i == 0) 
        return 1;
    else 
        return (a * puissance(a, i - 1));
}

/* 2. Méthode d'exponentiation rapide (Optimisée) */
int expRapide(int a, int i) {
    if (i == 0) 
        return 1;
    else if (i % 2 == 0) {
        // Si i est pair : a^i = (a^(i/2))^2
        int res = expRapide(a, i / 2);
        return res * res;
    } else {
        // Si i est impair : a^i = a * (a^(i/2))^2
        int res = expRapide(a, i / 2);
        return a * res * res;
    }
}

/* 4. Fonction récursive pour calculer la somme de i=0 à n de (a^i) */
int somme(int a, int n) {
    if (n == 0) 
        return 1; // Cas de base : a^0 = 1
    else 
        return (puissance(a, n) + somme(a, n - 1));
}

int main() {
    int a = 2;
    int n = 4;

    printf("--- Resultats de l'Exercice 3 ---\n");
    printf("Puissance classique (2^%d) : %d\n", n, puissance(a, n));
    printf("Exponentiation rapide (2^%d) : %d\n", n, expRapide(a, n));
    printf("Somme des puissances (de 2^0 a 2^%d) : %d\n", n, somme(a, n));

    return 0;
}
