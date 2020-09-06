#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#define true 1
#define false 0

int graph[N][N];
int path[N];
int visited[N];
int index = 0;

void findPath(int from, int to) {
    visited[from] = true;
    path[index] = from;
    index++;
    if (from == to)
        printPath();
    else{
        for (int i = 0; i < N; i++) {
            if (visited[i] == false && graph[from][i]==true)
                findPath(i, to);
            }
    }
    visited[from] = false;
    index--; 
}

void printPath() {
    for (int i = 0; i < index; i++)
        printf("%d ", path[i]);
    printf("\n");
}