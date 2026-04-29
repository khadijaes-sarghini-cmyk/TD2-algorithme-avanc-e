#include <stdio.h>
#include <stdlib.h>

/* Définition de la structure */
struct Element {
    int val;
    struct Element *suivant;
};
typedef struct Element LISTE;

/* Fonction pour insérer en fin (nécessaire pour la fusion) */
void InsererElementEnFin(LISTE **L, int valeur) {
    LISTE *element = (LISTE*) malloc(sizeof(LISTE));
    element->val = valeur;
    element->suivant = NULL;

    if (*L == NULL) {
        *L = element;
    } else {
        LISTE *ptr = *L;
        while (ptr->suivant) {
            ptr = ptr->suivant;
        }
        ptr->suivant = element;
    }
}

/* --- Exercice 4 : Fusion de deux listes en alternance --- */
LISTE * FusionDe2ListesAlternance(LISTE *L1, LISTE * L2) {
    LISTE *ptr1 = L1, *ptr2 = L2, *res = NULL;

    if (L1 == NULL) return L2;
    else if (L2 == NULL) return L1;

    // Fusion en alternance tant qu'il y a des éléments dans les deux listes
    while(ptr1 && ptr2) {
        InsererElementEnFin(&res, ptr1->val);
        InsererElementEnFin(&res, ptr2->val);
        ptr1 = ptr1->suivant;
        ptr2 = ptr2->suivant;
    }

    // Si L1 est plus longue, on ajoute le reste de L1
    while (ptr1) {
        InsererElementEnFin(&res, ptr1->val);
        ptr1 = ptr1->suivant;
    }

    // Si L2 est plus longue, on ajoute le reste de L2
    while (ptr2) {
        InsererElementEnFin(&res, ptr2->val);
        ptr2 = ptr2->suivant;
    }

    return res;
}

/* Fonction pour afficher une liste */
void AfficherListe(LISTE *L) {
    while (L) {
        printf("%d -> ", L->val);
        L = L->suivant;
    }
    printf("NULL\n");
}

int main() {
    LISTE *A = NULL;
    LISTE *B = NULL;
    LISTE *C = NULL;

    // Création de la liste A : {1, 2}
    InsererElementEnFin(&A, 1);
    InsererElementEnFin(&A, 2);

    // Création de la liste B : {10, 20, 30, 40}
    InsererElementEnFin(&B, 10);
    InsererElementEnFin(&B, 20);
    InsererElementEnFin(&B, 30);
    InsererElementEnFin(&B, 40);

    printf("Liste A : "); AfficherListe(A);
    printf("Liste B : "); AfficherListe(B);

    C = FusionDe2ListesAlternance(A, B);

    printf("\nListe C (Fusion) : ");
    AfficherListe(C);

    return 0;
}
