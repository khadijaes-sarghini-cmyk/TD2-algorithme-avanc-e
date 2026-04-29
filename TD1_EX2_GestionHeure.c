#include <stdio.h>

/**
 * EXERCICE 2 : Manipulation de structures temporelles
 * --------------------------------------------------
 * Ce programme permet de gérer des durées au format HH:MM:SS.
 * La stratégie utilisée consiste à convertir les heures en secondes
 * pour faciliter les calculs arithmétiques.
 */

typedef struct { 
    int hh; // Heures
    int mm; // Minutes
    int ss; // Secondes
} Heure; 

/* 1. Conversion d'une Heure en nombre total de secondes */
int HeureEnSecondes(Heure h) { 
    return (h.hh * 3600 + h.mm * 60 + h.ss); 
} 

/* 2. Conversion d'un nombre de secondes en structure Heure */
Heure SecondesEnHeure(int sec) { 
    Heure h; 
    h.hh = sec / 3600; 
    sec = sec % 3600; 
    h.mm = sec / 60; 
    h.ss = sec % 60; 
    return h; 
} 

/* 3. Addition de deux structures Heure */
Heure AddHeures(Heure h1, Heure h2) { 
    int totalSec = HeureEnSecondes(h1) + HeureEnSecondes(h2);
    return SecondesEnHeure(totalSec); 
} 

/* 4. Différence entre deux structures Heure (Temps écoulé) */
Heure DiffHeures(Heure h1, Heure h2) {
    int s1 = HeureEnSecondes(h1);
    int s2 = HeureEnSecondes(h2);
    int diff = (s1 > s2) ? (s1 - s2) : (s2 - s1);
    return SecondesEnHeure(diff);
}

/* Fonction utilitaire pour l'affichage */
void AfficherHeure(Heure h) {
    printf("%02dh:%02dm:%02ds\n", h.hh, h.mm, h.ss);
}

int main() { 
    Heure h1 = {2, 45, 30}; // 2h 45m 30s
    Heure h2 = {1, 20, 45}; // 1h 20m 45s
    
    printf("Heure 1 : "); AfficherHeure(h1);
    printf("Heure 2 : "); AfficherHeure(h2);
    
    printf("\nAddition : ");
    AfficherHeure(AddHeures(h1, h2));
    
    printf("Difference : ");
    AfficherHeure(DiffHeures(h1, h2));
    
    return 0; 
}
