#include <stdio.h>
#include <stdlib.h>

typedef enum { true, false, maybe } Keys;
typedef Keys ElementType;

void Read( ElementType A[], int N ); /* details omitted */

void MySort( ElementType A[], int N );

void PrintA( ElementType A[], int N )
{
    int i, k;

    k = i = 0;
    for ( ; i<N && A[i]==false; i++ );
    if ( i > k )
        printf("false in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==maybe; i++ );
    if ( i > k )
        printf("maybe in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==true; i++ );
    if ( i > k )
        printf("true in A[%d]-A[%d]\n", k, i-1);
    if ( i < N )
        printf("Wrong Answer\n");
}

int main()
{
    int N;
    ElementType *A;

    scanf("%d", &N);
    A = (ElementType *)malloc(N * sizeof(ElementType));
    Read( A, N );
    MySort( A, N );
    PrintA( A, N );
    return 0;
}

/* Your function will be put here */
void MySort( ElementType A[], int N )
{
    int amt0 = 0, amt1 = 0, amt2 = 0;// 3个amt分别用来计算false、true、maybe的个数
    int i;
    for( i = 0; i < N; i++)
    {
        if(A[i] == false) amt0++;
        else if(A[i] == true) amt1++;
        else if(A[i] == maybe) amt2++;
    }
    for(i = 0; i < amt0; i++) A[i] = false;
    for(i = amt0; i < amt2 + amt0; i++) A[i] = maybe;
    for(i = amt0 + amt2; i < N; i++) A[i] = true;
}