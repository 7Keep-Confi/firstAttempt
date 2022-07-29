#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

/* Your function will be put here */
void merge_pass( ElementType list[], ElementType sorted[], int N, int length )
{
    int cur = 0, top = 0;// cur表示当前要归并的子序列的起始位置
    int head, rhead;// head, rhead分别指向一个子序列的头部和另一个子序列的头部
    while(cur < N)
    {
        head = cur;
        rhead = cur + length;
        while(head < N && rhead < N && head < (cur + length) && rhead < (cur + length * 2))
        {
            if(list[head] < list[rhead]) sorted[top++] = list[head++];
            else sorted[top++] = list[rhead++];
        }
        // 以下两个循环的条件中 两个指针均要小于N
        while(head < (cur + length) && head < N) sorted[top++] = list[head++];
        while(rhead < (cur + length * 2) && rhead < N) sorted[top++] = list[rhead++];
        cur = cur + length * 2;
    }
}