#include<stdio.h>
 
 
int N;
int arr[26][26] = { 0, };
int visited[26][26] = { 0, };
 
int direction[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }; // 상, 하, 좌, 우
int danji[400] = { 0, };
int DFS(int i, int j) {
     
    int cache_i = i;
    int cache_j = j;
    visited[i][j] = 1;    
    int count = 1;
    for (int k = 0; k <= 3; k++) {
        int tmp_i = cache_i + direction[k][0];
        int tmp_j = cache_j + direction[k][1];
       // printf(":%d %d %d:", tmp_i, tmp_j,k);
        if ((tmp_i >= 1 && tmp_i <= N) && (tmp_j >= 1 && tmp_j <= N)) {
            if (arr[tmp_i][tmp_j] == 1 && visited[tmp_i][tmp_j] == 0) {
               count+= DFS(tmp_i, tmp_j);
            }
        }
    }
    return count;
}
 
int main() {
    //freopen("Text.txt", "rt", stdin);
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char tmp;
            scanf(" %c", &tmp);
            int home = tmp - '0';
            arr[i][j] = home;
        }
    }
    // DFS.
    int danjicount = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1 && visited[i][j] == 0) {
                danji[danjicount++] = DFS(i, j);
            }
        }
    }
 
    //printf("A: %d", danjicount);
 
    for (int i = 0; i < danjicount-1; i++) {
        int minidx = i;
        for (int j = i + 1; j < danjicount;j++) {
            if (danji[minidx] > danji[j]) minidx = j;
        }
        int tmp = danji[minidx];
        danji[minidx] = danji[i];
        danji[i] = tmp;
    }
 
 
    printf("%d\n", danjicount);
    for (int i = 0; i < danjicount; i++) {
        printf("%d\n", danji[i]);
    }
 
    return 0;
}