#include <stdio.h>
#include <stdlib.h>

/* Définition de la structure d'une pile (Stack) */
typedef struct stack { 
    int data; 
    struct stack *next; 
} STACK; 

/* Fonction Empiler (Push) */ 
void push(STACK **head, int value) { 
    STACK *node = (STACK*)malloc(sizeof(STACK)); 
    if (node == NULL) { 
        fputs("Error: no space available for node\n", stderr); 
        abort(); 
    } else { 
        node->data = value; 
        node->next = *head; 
        *head = node; 
    } 
} 

/* Fonction Dépiler (Pop) */ 
int pop(STACK **head) { 
    int value; 
    if (*head == NULL) { 
        fputs("Error: stack underflow\n", stderr); 
        abort(); 
    } else { 
        STACK *top = *head; 
        value = top->data; 
        *head = top->next; 
        free(top); 
        return value; 
    } 
} 

/* Procédure PairImpair pour organiser la pile P2 */
STACK * PairImpair(STACK * P1) { 
    STACK * P2 = NULL, *P3 = NULL; 
    int val; 

    // On vide P1 : les pairs vont dans P2, les impairs dans P3
    while (P1) { 
        val = pop(&P1); 
        if (val % 2 == 0) 
            push(&P2, val); 
        else 
            push(&P3, val); 
    } 

    // On remet les impairs de P3 dans P2 (ils seront au-dessus des pairs)
    while (P3) { 
        val = pop(&P3); 
        push(&P2, val); 
    } 
    return P2; 
} 

/* Fonction pour afficher la pile */
void AffichePile(STACK *P) { 
    while (P) { 
        printf("%d\t", P->data);  
        P = P->next; 
    } 
    printf("\n"); 
} 

int main() { 
    int i; 
    STACK * P1 = NULL, *P2 = NULL; 

    // Remplissage de P1 avec des valeurs de 1 à 9
    for (i = 1; i < 10; i++) push(&P1, i); 
    
    printf("Pile P1 initiale : \n");
    AffichePile(P1); 

    // Organisation de la pile
    P2 = PairImpair(P1); 

    printf("Pile P2 (Pairs en bas, Impairs en haut) : \n");
    AffichePile(P2); 

    return 0;
}
