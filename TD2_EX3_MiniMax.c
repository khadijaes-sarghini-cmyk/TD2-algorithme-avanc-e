#include <stdio.h>

#define m 3 
#define n 3 

/**
 * Calcule le MiniMax : la valeur minimale parmi les maximums de chaque ligne.
 * Complexité : T(m,n) = 4mn + 3n - 2
 * Ordre : O(nm)
 */
int MiniMax(int tab[n][m]) 
{ 
    int i, j, max, minimax; 

    for(i = 0; i < n; i++) // n itérations
    { 
        max = tab[i][0]; 

        for(j = 1; j < m; j++) // m-1 itérations
        { 
            if(tab[i][j] > max) 
                max = tab[i][j]; 
        } 

        // Gestion du minimax
        if(i == 0) 
            minimax = max; 
        else if(minimax > max) 
            minimax = max; 
    } 
    return minimax; 
} 

int main() { 
    int t[3][3] = {
        {2, 3, 4}, 
        {5, 6, 7}, 
        {8, 9, 10}
    }; 
    
    printf("MiniMax = %d\n", MiniMax(t)); 
    return 0;
}
