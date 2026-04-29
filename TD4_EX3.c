/**
 * Fonction qui retourne la valeur minimale d'un ABR
 * On suppose que l'arbre n'est pas vide (T != NULL)
 */
int LePlusPetit(SEARCH_TREE T) {
    SEARCH_TREE courant = T;

    // On descend tout à gauche
    while (courant->left != NULL) {
        courant = courant->left;
    }

    return courant->element;
}
