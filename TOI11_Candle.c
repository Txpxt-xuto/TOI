/*
TASK: candle.c
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>
#include <stdlib.h>
#define check_border(X, Y, M, N) ((X)>=(M) || (X)<0 || (Y)>=(N) || (Y)<0)
char candle[2000][2000];
void bfs(int x, int y, int m, int n);
int main(void) 
{
    int m, n, count = 0, i, j;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++) scanf("%s", candle[i]);
    for(i=0;i<m;i++) 
    {
        for(j=0;j<n;j++) 
        {
            if (candle[i][j] == '0') continue;
            bfs(i, j, m, n);
            count++;
        }
    }
    printf("%d\n", \count);
    return 0;
}
void bfs(int x, int y, int m, int n){
    candle[x][y] = '0';
    struct queue {
        int x;
        int y;
        struct queue *next;
    };
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    struct queue *tail = q;
    *q = (struct queue) { .x = x, .y = y, .next = NULL };
    int i, j;
    while (q != NULL) 
    {
        int cur_x = q->x;
        int cur_y = q->y;
        for(i=cur_x-1;i<cur_x+2;i++) 
        {
            for(j=cur_y-1;j<cur_y+2;j++) 
            {
                if (check_border(i, j, m, n)) continue;
                if (candle[i][j] == '0') continue;
                candle[i][j] = '0';
                tail->next = (struct queue *)malloc(sizeof(struct queue));
                tail = tail->next;
                *tail = (struct queue) { .x = i, .y = j, .next = NULL };
            }
        }
        struct queue *temp = q;
        q = q->next;
        free(temp);
    }
}