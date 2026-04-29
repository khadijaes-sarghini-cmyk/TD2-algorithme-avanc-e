#include <stdio.h>
#include <stdlib.h>

/* Définition de la structure */
struct Element {
    int val;
    struct Element *suivant;
};
typedef struct Element LISTE;

/* Fonction d'insertion (Exercice 1) pour tester */
int InsererElementEnTete(LISTE **L, int valeur) {
    LISTE *element = (LISTE*) malloc(sizeof(LISTE));
    if (element == NULL) return 0;
    element->val = valeur;
    element->suivant = *L;
    *L = element;
    return 1;
}

/* --- Exercice 5 : Destruction d'une liste --- */
void DestructionListe(LISTE **L) {
    LISTE *ptr;
    
    // Si la liste est déjà vide, on quitte la fonction
    if (*L == NULL) return; 

    // On parcourt la liste et on libère chaque nœud
    while (*L != NULL) {
        ptr = *L;               // On garde l'adresse du nœud actuel
        *L = (*L)->suivant;     // On déplace le début de la liste au suivant
        free(ptr);              // On libère la mémoire du nœud stocké
    }
}

int main() {
    LISTE *maListe = NULL;

    // Création d'une petite liste pour le test
    InsererElementEnTete(&maListe, 10);
    InsererElementEnTete(&maListe, 20);
    InsererElementEnTete(&maListe, 30);

    printf("Liste creee avec succes.\n");

    // Destruction de la liste
    DestructionListe(&maListe);

    if (maListe == NULL) {
        printf("La liste a ete detruite et la memoire a ete liberee.\n");
    }

    return 0;
}
