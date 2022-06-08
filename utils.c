#include "header.h"

int cost(int *A, int *B,int N, int **GRAPH)
{
    int cost = 0;
    int i = 0;

    while(i < N/2)
    {
        int j = 0;
        while(j < N/2)
        {
            cost += GRAPH[A[i]][B[j]];
            j++;
        }
        i++;
    }
    return cost;
}

void swap_tables(int *t, int *T, int N)
{
    int i = 0;

    while(i < N/2)
    {
        t[i] = T[i];
        i++;
    }
}

int check_nonexistence(int x,int *T,int so_far)
{
    int i = 0;

    while(i < so_far)
    {
        if (T[i] == x)
            return 1;
        i++;
    }
    return 0;
}

int **construct_graph(char *path,int *N)
{
    FILE *f = fopen(path, "r");
    fscanf(f,"%d",N);
    
    int i = 0;
    int **graph = (int **)malloc(*N*sizeof(int *));
    while(i < *N)
    {
        graph[i] = (int *)malloc(*N*sizeof(int));
        i++;
    }
    i = 0;
    int INDEX = 0;
    int index = 0;
    int n;
    while(1)
    {
        fscanf(f,"%d",&n);
        if(INDEX == index)
        {
            graph[INDEX][index] = 0;
            index++;
        }
        else
        {
            graph[INDEX][index] = n;
            graph[index][INDEX] = n;
            index++;
        }

        if(index == *N)
        {
            INDEX++;
            if(INDEX == *N)
                break;
            index = INDEX;
        }
    }
    fclose(f);
    return graph;
}

int *sort( int *T, int N)                                            
{           
    int *duplT = malloc(N/2*sizeof(int));                                                                                                                                                
    int i=0;                                                                     
    int tmp=0;                                                                     
    int j=0;    

    while(j <N/2){
        duplT[j] = T[j];
        j++;
    }                                                              
                                                                                    
    for(i = 0; i < N/2 - 1; i++)                                  
    {                                                                          
        for(j = i+1; j < N/2; j++)                     
        {                                                    
            if(duplT[j] < duplT[i])                                                        
            {                                                                  
                tmp = duplT[i];              
                duplT[i] = duplT[j];                                                       
                duplT[j] = tmp;                                                    
            }                                                                  
        }                                                                      
    }                                                                 
    return duplT;
}

int key(int *T, int N)
{
    int *tmp = sort(T,N);
    int i = N/2 - 1;
    int key = 0;
    int n = 0;

    while(i >= 0)
    {
        key += tmp[i]*pow(10,n);
        i--;
        n++;
    }
    return key;
}