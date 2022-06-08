#include "header.h"

int randomStart(int N)
{
    int start;
    time_t t1;

    srand((unsigned)time(&t1));
    start = rand() % N;

    return start;
}

void fillA(int *A,int N, int **GRAPH)
{
    int curr_pnt = randomStart(N);
    int a = 0;
    int A_index = 0;
    
    A[A_index++] = curr_pnt;
    while(1)
    {
        int i = 0;
        while(i < N)
        {
            if(GRAPH[curr_pnt][i] != 0 && check_nonexistence(i,A,A_index) == 0)
            {
                A[A_index++] = i;
                if (A_index == N/2)
                return;
            }
            i++;
        }
        curr_pnt = A[++a];
    }
}

void fillB(int *B,int *A, int N, int **GRAPH)
{
    int b = 0;
    int B_index = 0;

    while(b < N)
    {
        if(check_nonexistence(b,A,N/2) == 0)
        {
            B[B_index] = b;
            B_index++;
        }
        b++;
    }
}

