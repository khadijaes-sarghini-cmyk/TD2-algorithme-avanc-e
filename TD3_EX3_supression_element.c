/* EXERCICE 3 : Suppression du minimum.
   Ce programme identifie la plus petite valeur et libère son nœud.
   On utilise un pointeur précédent pour maintenir la structure de la liste.
   Complexité : O(n) pour le parcours de recherche du minimum.
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

/* Fonction d'insertion (Exercice 1) */
int InsererElementEnTete(LISTE **L, int valeur) {
    LISTE *element = (LISTE*) malloc(sizeof(LISTE));
    if (element == NULL) return 0;
    element->val = valeur;
    element->suivant = *L;
    *L = element;
    return 1;
}

/* --- Exercice 3 : Suppression de la valeur minimale --- */
int SuppressionValeurMin(LISTE **L) {
    LISTE *ptr = *L, *pMin = NULL;
    int minim;

    if (!ptr) return 0; // Liste vide

    if (!ptr->suivant) { // Un seul élément
        *L = NULL;
        free(ptr);
        return 1;
    }

    // Recherche du minimum et du pointeur précédent (pMin)
    minim = ptr->val;
    pMin = NULL; 
    
    while (ptr->suivant) {
        if (minim > ptr->suivant->val) {
            minim = ptr->suivant->val;
            pMin = ptr; // pMin garde l'adresse de l'élément AVANT le minimum
        }
        ptr = ptr->suivant;
    }

    // Suppression
    if (!pMin) { // Le minimum était le premier élément
        ptr = *L;
        *L = (*L)->suivant;
        free(ptr);
    } else { // Le minimum est ailleurs dans la liste
        ptr = pMin->suivant;
        pMin->suivant = pMin->suivant->suivant;
        free(ptr);
    }
    return 1;
}

/* Fonction pour afficher la liste */
void AfficherListe(LISTE *L) {
    while (L) {
        printf("%d -> ", L->val);
        L = L->suivant;
    }
    printf("NULL\n");
}

int main() {
    LISTE *maListe = NULL;
    srand(time(NULL));

    // Création d'une liste de 10 éléments pour le test
    for(int i = 0; i < 10; i++) {
        InsererElementEnTete(&maListe, rand() % 50);
    }

    printf("Liste avant suppression : \n");
    AfficherListe(maListe);

    SuppressionValeurMin(&maListe);

    printf("\nListe apres suppression de la valeur minimale : \n");
    AfficherListe(maListe);

    return 0;
}
