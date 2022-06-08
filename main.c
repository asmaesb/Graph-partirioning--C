#include "header.h"

int TABOU[TABOU_SIZE];
int tabou_index = 0;



void push_tabou(int key)
{
    if(tabou_index == TABOU_SIZE)
        tabou_index = 0;
    TABOU[tabou_index++] = key;
}

int main()
{
    char *s= "graphes.txt";
    int N = 0;
    printf("GRAPH :\n");
    int **graph = construct_graph(s,&N);
    int i = 0;
    while(i < N)
    {
        int j =0;
        while(j < N)
        {
            printf("%d ",graph[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");

    
    i = 0;
    int *A = malloc(N/2*sizeof(int));
    int *B = malloc(N/2*sizeof(int));
    fillA(A, N, graph);
    fillB(B, A, N, graph);

    printf("La solution initiale est :\n");
    printf("Groupe A initial :\n");
    while (i < N/2)
    {
        printf("%d " , A[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("Groupe B initial :\n");
    while (i < N/2)
    {
        printf("%d " , B[i]);
        i++;
    }
    printf("\ncost is %d\n\n",cost(A,B,N,graph));

    int *bestA = malloc(N/2*sizeof(int));
    int *bestB = malloc(N/2*sizeof(int));

    swap_tables(bestA,A,N);
    swap_tables(bestB,B,N);


    while(i < MAX_ITER)
    {
        int *tempA = generate_neighbors(A,B,N,graph,TABOU,tabou_index);

        int *tempB = (int *)malloc(N/2*sizeof(int));
        fillB(tempB,tempA,N,graph);

        int temp_cost = cost(tempA,tempB,N,graph);
        if(temp_cost < cost(bestA,bestB,N,graph))
        {
            swap_tables(bestA,tempA,N);
            swap_tables(bestB,tempB,N);
        }

        if(check_nonexistence(key(tempA,N),TABOU,tabou_index) == 0)
        {
            if(temp_cost < cost(A,B,N,graph))
            {
                swap_tables(A,tempA,N);
                swap_tables(B,tempB,N);
            }
            else
            {
                push_tabou(key(A,N));
                swap_tables(A,tempA,N);
                swap_tables(B,tempB,N);
            }
        }
        i++;
    }
    i = 0;

    printf("La solution finale est :\n");
    printf("Groupe A final :\n");
    while (i < N/2)
    {
        printf("%d " , bestA[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("Groupe B final :\n");
    while (i < N/2)
    {
        printf("%d " , bestB[i]);
        i++;
    }
    printf("\ncost is %d\n",cost(bestA,bestB,N,graph));


}