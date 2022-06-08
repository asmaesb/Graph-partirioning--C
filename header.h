#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define VOISIN_ITER 50
#define MAX_ITER 10
#define TABOU_SIZE 5

// extern int GRAPH[6][6];
// extern int A[3],B[3];

int cost(int *A, int *B,int N, int **GRAPH);
void swap_tables(int *t, int *T, int N);
int **construct_graph(char *path, int *N);

int randomStart(int N);
int check_nonexistence(int x,int *T,int so_far);
void fillA(int *A, int N, int **GRAPH);
void fillB(int *B, int *A, int N, int **GRAPH);
int *generate_neighbors(int *A,int *B , int N,int **GRAPH, int *TABOU,int tabou_index);
int *sort( int *T, int N) ;
int key(int *T, int N);

#endif