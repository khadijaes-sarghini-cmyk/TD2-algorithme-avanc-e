/* EXERCICE 2 : Recherche séquentielle.
   Ce programme parcourt la liste pour vérifier si une valeur existe.
   Il renvoie 1 (trouvé) ou 0 (non trouvé).
   Complexité : O(n) car on peut être amené à parcourir toute la liste.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Définition de la structure */
struct Element {
    int val;
    struct Element *suivant;
};
typedef struct Element LISTE;

//Fonction d'insertion 
int InsererElementEnTete(LISTE **L, int valeur) {
    LISTE *element = (LISTE*) malloc(sizeof(LISTE));
    if (element == NULL) return 0;
    element->val = valeur;
    element->suivant = *L;
    *L = element;
    return 1;
}

//Exercice 2 : Recherche de valeur 
int RechercherValeur(LISTE *L, int valeur) {
    LISTE *ptr = L;
    while (ptr) {
        if (ptr->val == valeur) return 1; // Valeur trouvée
        ptr = ptr->suivant;
    }
    return 0; // Valeur non trouvée
}

int main() {
    LISTE *maListe = NULL;
    int valeurCherchee, resultat;

    // 1. Création de la liste (100 éléments aléatoires)
    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        InsererElementEnTete(&maListe, rand() % 100);
    }

    // 2. Test de la recherche
    printf("Entrez une valeur a rechercher (0-99) : ");
    scanf("%d", &valeurCherchee);

    resultat = RechercherValeur(maListe, valeurCherchee);

    if (resultat == 1) {
        printf("La valeur %d existe dans la liste.\n", valeurCherchee);
    } else {
        printf("La valeur %d n'existe pas dans la liste.\n", valeurCherchee);
    }

    return 0;
}
