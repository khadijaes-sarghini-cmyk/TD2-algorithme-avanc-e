#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TMAX 20

/* 1. Définition de la structure avec typedef */
typedef struct {
    int abs; // Abscisse (x)
    int ord; // Ordonnée (y)
} Point;

/* 2. Fonction pour saisir un point */
Point SaisirPoint() {
    Point p;
    printf("Donner l'abscisse et l'ordonnee : ");
    if (scanf("%d %d", &p.abs, &p.ord) != 2) {
        printf("Erreur de saisie.\n");
    }
    return p;
}

/* 3. Fonction pour afficher un point format (x,y) */
void AfficherPoint(Point p) {
    printf("(%d,%d) ", p.abs, p.ord);
}

/* 5.a Distance par rapport à l'origine (Passage par valeur) */
float DistTransVal(Point p) {
    return sqrt(p.abs * p.abs + p.ord * p.ord);
}

/* 5.b Distance par rapport à l'origine (Passage par adresse) */
float DistTransAdr(Point* p) {
    return sqrt(p->abs * p->abs + p->ord * p->ord);
}

/* 6. Tri du tableau par ordre croissant des distances */
void tritab(Point t[], int taille) {
    int i, j;
    Point aux;
    for(i = 0; i < taille - 1; i++) {
        for(j = i + 1; j < taille; j++) {
            if (DistTransVal(t[i]) > DistTransVal(t[j])) {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
}

/* 7. Programme principal d'essai */
int main() {
    int i, taille;
    srand(time(NULL));

    // --- Saisie d'un point unique ---
    printf("--- Saisie d'un point unique ---\n");
    Point a = SaisirPoint();
    printf("Le point saisi est : ");
    AfficherPoint(a);
    printf("\nDistance a l'origine : %.2f\n\n", DistTransVal(a));

    // --- Gestion des tableaux ---
    printf("Donner la taille des tableaux (max %d) : ", TMAX);
    scanf("%d", &taille);

    Point TStat[TMAX];               // Version Statique
    Point *TDyn = (Point*)malloc(taille * sizeof(Point)); // Version Dynamique

    if (TDyn == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Remplissage aléatoire
    for(i = 0; i < taille; i++) {
        TStat[i].abs = rand() % 20;
        TStat[i].ord = rand() % 20;
        TDyn[i] = TStat[i]; // On copie dans le dynamique pour comparer
    }

    printf("\nTableau dynamique avant tri :\n");
    for(i = 0; i < taille; i++) AfficherPoint(TDyn[i]);

    // Tri du tableau dynamique
    tritab(TDyn, taille);

    printf("\n\nTableau dynamique apres tri (par distance croissante) :\n");
    for(i = 0; i < taille; i++) {
        AfficherPoint(TDyn[i]);
        printf("[dist: %.2f] ", DistTransVal(TDyn[i]));
    }
    printf("\n");

    free(TDyn); // Libération de la mémoire
    return 0;
}
