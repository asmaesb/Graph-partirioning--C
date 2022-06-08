#include "header.h"

int *generate_neighbors(int *A,int *B , int N,int **GRAPH, int *TABOU,int tabou_index)
{
    int *currA = malloc(N/2*sizeof(int));
    int *currB = malloc(N/2*sizeof(int));
    int *tempA = malloc(N/2*sizeof(int));
    int *tempB = malloc(N/2*sizeof(int));
    int t;
    int xA = 0;
    int xB = 0;
    int i = 0;
    while(i < N/2)
    {
        currA[i] = A[i];
        currB[i] = B[i];
        i++;
    }
    t = currA[xA];
    currA[xA] = currB[xB];
    currB[xB++] = t;
    
    int iter = 0;
    while(iter < VOISIN_ITER)
    {
        while(xB < N/2)
        {
            i = 0;
            while(i < N/2)
            {
                tempA[i] = A[i];
                tempB[i] = B[i];
                i++;
            }
            t = tempA[xA];
            tempA[xA] = tempB[xB];
            tempB[xB++] = t;

            if (cost(tempA,tempB,N,GRAPH) < cost(currA,currB,N,GRAPH) && check_nonexistence(key(tempA,N),TABOU,tabou_index) == 0)
            {
                swap_tables(currA,tempA,N);
                swap_tables(currB,tempB,N);
            }

        }
        xA++;
        if (xA == N/2)
            break;
        xB = 0;
        iter++;
    }
    return currA;
}