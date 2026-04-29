int EstCeQueABR(SEARCH_TREE A) 
{ 
LISTE * L = NULL; 
ConstListeTriee(A, &L); 
if (A == NULL) return 0; 
else if ((A->left == NULL)&& (A->right == NULL)) return 1; 
else { 
while (L->suivant != NULL) 
{ 
if (L->val > L->suivant->val) return -1; 
L = L->suivant; 
} 
} 
return 1; 
} 
element_type LePlusPetit(SEARCH_TREE A) 
{ 
while (A->left != NULL) 
A = A->left; 
return A->element; 
}
