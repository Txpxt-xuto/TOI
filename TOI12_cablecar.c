/*
TASK: cablecar.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200005
int head[MAX_SIZE];
typedef struct 
{
    int first;
    int second;
} Pair;
typedef struct 
{
    int first;
    Pair second;
} Triple;
typedef struct 
{
    Triple *array;
    int size;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) 
{
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (Triple*)malloc(capacity * sizeof(Triple));
    pq->size = 0;
    return pq;
}

void swap(Triple* a, Triple* b) 
{
    Triple temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue* pq, Triple item) 
{
    pq->array[pq->size] = item;
    int i = pq->size;
    pq->size++;
    while (i > 0 && pq->array[i].first > pq->array[(i - 1) / 2].first) 
    {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Triple pop(PriorityQueue* pq) 
{
    Triple item = pq->array[0];
    pq->size--;
    pq->array[0] = pq->array[pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) 
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int maxIndex = i;
        if (pq->array[leftChild].first > pq->array[maxIndex].first) maxIndex = leftChild;
        if (rightChild < pq->size && pq->array[rightChild].first > pq->array[maxIndex].first) maxIndex = rightChild;
        if (maxIndex == i) break;
        swap(&pq->array[i], &pq->array[maxIndex]);
        i = maxIndex;
    }
    return item;
}

void freePriorityQueue(PriorityQueue* pq) 
{
    free(pq->array);
    free(pq);
}

int findhead(int p) 
{
    if (head[p] == p) return p;
    return head[p] = findhead(head[p]);
}

void unionhead(int ip, int fp) 
{
    ip = findhead(ip);
    fp = findhead(fp);
    head[fp] = ip;
}

int main() 
{
    int n, m, i, s, d;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++) head[i] = i;
    PriorityQueue* pq = createPriorityQueue(m);
    for(i = 0; i < m; i++) 
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        Triple trip;
        trip.first = z;
        trip.second.first = x;
        trip.second.second = y;
        push(pq, trip);
    }
    long long passenger;
    scanf("%d%d%lld", &s, &d, &passenger);
    int minimum;
    while (1) 
    {
        Triple trip = pop(pq);
        int ip = trip.second.first;
        int fp = trip.second.second;
        int w = trip.first;
        if (findhead(ip) == findhead(fp)) continue;
        unionhead(ip, fp);
        if (findhead(s) == findhead(d)) 
        {
            minimum = w - 1;
            break;
        }
    }
    if (passenger % minimum == 0) printf("%lld", passenger / minimum);
    else printf("%lld", passenger / minimum + 1);
    return 0;
}