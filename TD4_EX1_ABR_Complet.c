/* structure arbre */ 
typedef int element_type; 
typedef struct tree_node *tree_ptr; 
struct tree_node { 
element_type element; 
tree_ptr left; 
tree_ptr right; 
}; 
typedef  tree_ptr  SEARCH_TREE; 
//Ins`erer une valeur dans un ABR. 
tree_ptr insert( element_type x, SEARCH_TREE T ) 
{ 
if( T == NULL ) 
{ /* Creer et retourner un arbre compose d’un seul noeud*/ 
T = (SEARCH_TREE) malloc ( sizeof (struct tree_node) ); 
if( T == NULL ) {printf("Espace memoire insuffisant!!!"); 
exit(0); 
} 
else 
{ 
T->element = x; 
T->left = T->right = NULL; 
} 
} 
else if( x <= T->element ) 
T->left = insert( x, T->left ); 
else 
if( x > T->element ) 
T->right = insert( x, T->right ); 
/* Sinon x existe deja dans l’arbre. On va rien faire */ 
return T; /* Ne pas oublier cette ligne!! */ 
} 
//Chercher si une valeur donn´ee appartient `a un ABR. 
tree_ptr  RechercherElement(SEARCH_TREE  Arbre,  element_type  e) 
{ 
if (Arbre == NULL) return NULL; 
if (e == Arbre->element) 
return Arbre; 
else if (e > Arbre->element) 
return RechercherElement(Arbre->right, e); 
else return RechercherElement(Arbre->left,e); 
} 
//Compter le nombre d’occurrences d’une valeur X donn´ee dans un ABR A. 
void NombreOccurences(SEARCH_TREE A, element_type e, int *nombre) 
{ 
if (A != NULL) { 
NombreOccurences(A->left,e, nombre); 
if (A->element == e) (*nombre)++; 
NombreOccurences(A->right,e, nombre); 
} 
} 
//Afficher les cl´es de l’ABR en utilisant un parcours infix´e. 
void ParcoursInfixeArbre(tree_ptr Arbre) 
{ 
if (Arbre != NULL) { 
ParcoursInfixeArbre(Arbre->left); 
/* traitement du cle */ 
printf("%d\t", Arbre->element); 
ParcoursInfixeArbre(Arbre->right); 
} 
} 
//Construire une liste tri´ee `a partir d’un ABR. 
void  ConstListeTriee(SEARCH_TREE  A,  LISTE  **L) 
{ 
if (A != NULL) { 
ConstListeTriee(A->left, L); 
InsererElementEnFin(L, A->element); 
ConstListeTriee(A->right, L); 
} 
} 
//Construire un ABR `a partir d’une liste (non tri´ee). 
SEARCH_TREE ArbreAPartirDeListe(LISTE  *L) 
{ 
SEARCH_TREE A = NULL; 
while (L != 0) 
{ 
A = insert(L->val, A); 
L = L->suivant; 
} 
return A; 
}
7. D´eduire une fonction de tri de liste. 
LISTE * TrierListe(LISTE * L) 
{ 
SEARCH_TREE A = NULL; 
LISTE * ptr = NULL; 
A  =  ArbreAPartirDeListe(L); 
/* Copier les elements de A dans la liste ptr */ 
ConstListeTriee(A, &ptr); 
return ptr; 
} 
Programme faisant appel aux diff´erentes fonctions d´efinies ci-dessus : 
main() 
{ 
SEARCH_TREE A=NULL; 
tree_ptr ptr = NULL; 
LISTE *L=NULL, *autreL = L; 
int i, nbre; 
/* creation d’un arbre de 10 elements */ 
for(i=1;i<=10;i++) 
A = insert(rand()%10, A); 
/* Affichage de l’arbre A */ 
printf("\n L’arbre est (infixe) : \n"); 
ParcoursInfixeArbre(A); 
printf("\n L’arbre est (prefixe) : \n"); 
ParcoursPrefixeArbre(A); 
printf("\n Donner un entier qu on cherche s il existe dans l’arbre :"); 
scanf("%d",&i); 
ptr = RechercherElement(A, i); 
if (ptr) 
printf("\n La valeur : %d figure dans l’arbre, son adresse est : %p\n", i, ptr); 
else printf("\n La valeur : %d ne figure pas dans l’arbre A\n", i); 
/* Nombre d’occurence de i*/ 
nbre = 0; 
NombreOccurences(A,i, &nbre); 
printf("\n Le nombre d’occurences de : %d est : %d\n", i, nbre); 
/* construction liste triee a partir arbre */ 
L = NULL; 
ConstListeTriee(A, &L); 
printf("\n La liste construite est :\n"); 
AfficheListe(L); 
/* creer liste non triee */ 
for(i=1; i<10;i++)
  InsererElementEnTete(&  autreL,  rand()%10); 
printf("\n La liste construite est (non triee) :\n"); 
AfficheListe(autreL); 
/* trier la liste */ 
autreL = TrierListe(autreL); 
printf("\n La liste construite apres tri :\n"); 
AfficheListe(autreL); 
/* ABR, trie ou pas -------------- Exercice 2 */ 
if (EstCeQueABR(A)) printf("\n Arbre est ABR.\n"); 
else printf("\n Arbre n’est pas un ABR.\n"); 
/* valeur minimale de l’arbre --------------------- Exercice 3 */ 
printf("La valeur min de l’arbre est : %d\n", LePlusPetit(A)); 
}
