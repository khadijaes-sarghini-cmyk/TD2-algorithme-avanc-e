/* EXERCICE 7 : Test de Palindrome (Pile + File).
   Vérifie si un mot se lit dans les deux sens en comparant 
   l'ordre FIFO (File) et l'ordre LIFO (Pile).
   Complexité : O(n).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Structure de la PILE (LIFO) --- */
typedef struct stack { 
    char data; 
    struct stack *next; 
} STACK; 

void push(STACK **head, char value) { 
    STACK *node = (STACK*)malloc(sizeof(STACK)); 
    if (node == NULL) abort(); 
    node->data = value; 
    node->next = *head; 
    *head = node; 
} 

char pop(STACK **head) { 
    if (*head == NULL) abort(); 
    STACK *top = *head; 
    char value = top->data; 
    *head = top->next; 
    free(top); 
    return value; 
} 

/* --- Structure de la FILE (FIFO) --- */
struct queue_node { 
    char data; 
    struct queue_node *next; 
}; 

struct queue { 
    struct queue_node *first; 
    struct queue_node *last; 
}; 

int enqueue(struct queue *q, char value) { 
    struct queue_node *node = (struct queue_node *)malloc(sizeof(struct queue_node)); 
    if (node == NULL) return 1; 
    node->data = value; 
    node->next = NULL;
    if (q->first == NULL) { 
        q->first = q->last = node; 
    } else { 
        q->last->next = node; 
        q->last = node; 
    } 
    return 0; 
} 

int dequeue(struct queue *q, char *value) { 
    if (!q->first) return 1; 
    *value = q->first->data; 
    struct queue_node *tmp = q->first; 
    q->first = q->first->next; 
    if (q->first == NULL) q->last = NULL; 
    free(tmp); 
    return 0; 
} 

/* --- Logique Palindrome --- */

void EcrireMessage(struct queue *q, char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        enqueue(q, msg[i]);
    }
}

int EstPalindrome(struct queue *q) {
    STACK *p = NULL;
    struct queue_node *ptr = q->first;
    char v_pile, v_file;

    // 1. On remplit une pile avec les éléments de la file
    while (ptr) {
        push(&p, ptr->data);
        ptr = ptr->next;
    }

    // 2. On compare la file (ordre normal) et la pile (ordre inverse)
    while (q->first != NULL) {
        v_pile = pop(&p);
        dequeue(q, &v_file);
        if (v_pile != v_file) return 0; // Pas un palindrome
    }
    return 1; // C'est un palindrome
}

int main() {
    struct queue maFile = {NULL, NULL};
    char message[100];

    printf("Entrez un mot : ");
    scanf("%s", message);

    EcrireMessage(&maFile, message);

    if (EstPalindrome(&maFile)) {
        printf("Oui, '%s' est un palindrome.\n", message);
    } else {
        printf("Non, '%s' n'est pas un palindrome.\n", message);
    }

    return 0;
}
