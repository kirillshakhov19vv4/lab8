#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;
int** G;
int* dist;
int ver;
int* ext;
int D = 0;
int R = 1000;
int* stp;

void BFSD(int s, int rows) {
    int v;
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < rows; i++) {
            if (G[v][i] > 0 && dist[i] > dist[v] + G[v][i]) {
                dist[i] = dist[v] + G[v][i];
                q.push(i);
            }
        }
    }
}

int main()
{
    int rows;
    int n = 0;
    int k = 0;
    system("cls");
    printf("rows:");
    scanf("%d", &rows);
    srand(time(NULL));

    stp = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        stp[i] = 0;
    }

    G = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        G[i] = (int*)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            G[i][j] = rand() % 5;
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];

        }
    }
    printf("Matrix smeg\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", G[i][j]);
            if (G[i][j] > 0) {
                stp[i]++;
            }
        }
        printf("\n");
    }
    printf("\n");

    dist = (int*)malloc(rows * sizeof(int));


    ext = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        ext[i] = -1;
    }
    printf("\n");
    for (int a = 0; a < rows; a++) {
        for (int i = 0; i < rows; i++) {
            dist[i] = 1000;
        }
        BFSD(a, rows);
        printf("Dist do %d versh: \n", a);
        for (int i = 0; i < rows; i++) {
            printf("%d ", dist[i]);
            if (ext[a] < dist[i]) {
                ext[a] = dist[i];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("Excentrisitet %d versh %d\n", i, ext[i]);
        if (ext[i] > D && ext[i] != 0 && ext[i] != 1000) {
            D = ext[i];
        }
        if (ext[i] < R && ext[i] != 0 && ext[i] != 1000) {
            R = ext[i];
        }
    }
    printf("\n");
    printf("Diametr: %d\nRadius: %d", D, R);
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("Stepen %d versh: %d\n", i, stp[i]);
    }

    printf("\nIzolir versh:");
    for (int i = 0; i < rows; i++) {
        if (stp[i] == 0) {
            printf("%d ", i);
        }
    }

    printf("\nKoncevie versh:");
    for (int i = 0; i < rows; i++) {
        if (stp[i] == 1) {
            printf("%d ", i);
        }
    }

    printf("\nDominir versh:");
    for (int i = 0; i < rows; i++) {
        if (stp[i] == rows - 1) {
            printf("%d ", i);
        }
    }

    printf("\nCentraln versh:");
    for (int i = 0; i < rows; i++) {
        if (ext[i] == R) {
            printf("%d ", i);
        }
    }

    printf("\nPerifer versh:");
    for (int i = 0; i < rows; i++) {
        if (ext[i] == D) {
            printf("%d ", i);
        }
    }
    for (int i = 0; i < rows; i++)
        free(G[i]);
    free(G);
    getchar();
    return 0;
}
